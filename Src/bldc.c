
#include "stm32f1xx_hal.h"
#include <math.h>
#include "defines.h"
#include "setup.h"
#include "config.h"
#include "cfgbus.h"

uint8_t enable = 0;

uint32_t offsetcount = 0;
adc_offsets_t offsets = {0};

uint16_t _lastPosL = 0;
uint16_t _lastPosR = 0;

const int pwm_res = 64000000 / 2 / PWM_FREQ; // = 2000

//(hall_to_pos + 2) % 6
const uint8_t hall_to_pos[8] = {
   2,
   5,
   1,
   0,
   3,
   4,
   2,
   2,
};

inline void blockPWM(int pwm, int pos, int *u, int *v, int *w) {
  switch(pos) {
    case 0:
      *u = 0;
      *v = pwm;
      *w = -pwm;
      break;
    case 1:
      *u = -pwm;
      *v = pwm;
      *w = 0;
      break;
    case 2:
      *u = -pwm;
      *v = 0;
      *w = pwm;
      break;
    case 3:
      *u = 0;
      *v = -pwm;
      *w = pwm;
      break;
    case 4:
      *u = pwm;
      *v = -pwm;
      *w = 0;
      break;
    case 5:
      *u = pwm;
      *v = 0;
      *w = -pwm;
      break;
    default:
      *u = 0;
      *v = 0;
      *w = 0;
  }
}


//scan 8 channels with 2ADCs @ 20 clk cycles per sample
//meaning ~80 ADC clock cycles @ 8MHz until new DMA interrupt =~ 100KHz
//=640 cpu cycles
void DMA1_Channel1_IRQHandler() {
  DMA1->IFCR = DMA_IFCR_CTCIF1;

  // callibrate ADC offset before startup by averaging 1024 samples.
  if(offsetcount < 1024) {
    offsetcount++;
    offsets.rl1 += adc_buffer.rl1;
    offsets.rl2 += adc_buffer.rl2;
    offsets.rr1 += adc_buffer.rr1;
    offsets.rr2 += adc_buffer.rr2;
    offsets.dcl += adc_buffer.dcl;
    offsets.dcr += adc_buffer.dcr;
    offsets.temp += adc_buffer.temp;
    offsets.vbat += adc_buffer.vbat;
    return;
  } else if (offsetcount == 1024) {
	offsetcount++;
    offsets.rl1 /= 1024;
    offsets.rl2 /= 1024;
    offsets.rr1 /= 1024;
    offsets.rr2 /= 1024;
    offsets.dcl /= 1024;
    offsets.dcr /= 1024;
    offsets.temp /= 1024;
    offsets.vbat /= 1024;
  }

  //disable PWM when current limit is reached (current chopping)
  if(ABS(adc_buffer.dcl - offsets.dcl) > DC_CUR_THRESHOLD || enable == 0) {
    LEFT_TIM->BDTR &= ~TIM_BDTR_MOE;
  } else {
    LEFT_TIM->BDTR |= TIM_BDTR_MOE;
  }

  if(ABS(adc_buffer.dcr - offsets.dcr) > DC_CUR_THRESHOLD || enable == 0) {
    RIGHT_TIM->BDTR &= ~TIM_BDTR_MOE;
  } else {
    RIGHT_TIM->BDTR |= TIM_BDTR_MOE;
  }

  //determine next position based on hall sensors
  uint8_t hall_l =  (LEFT_HALL_PORT->IDR >> LEFT_HALL_LSB_PIN) & 0b111;
  uint8_t hall_r =  (RIGHT_HALL_PORT->IDR >> RIGHT_HALL_LSB_PIN) & 0b111;

  cfg.vars.pos_r = hall_to_pos[hall_r];
  cfg.vars.pos_l = hall_to_pos[hall_l];

  //keep track of wheel movement
  if(_lastPosL != cfg.vars.pos_l)
    cfg.vars.tacho_l += (_lastPosL == (cfg.vars.pos_l + 1)%6) ? 1 : -1;

  if(_lastPosR != cfg.vars.pos_r)
    cfg.vars.tacho_r += (_lastPosR == (cfg.vars.pos_r + 1)%6) ? 1 : -1;

  _lastPosL = cfg.vars.pos_l;
  _lastPosR = cfg.vars.pos_r;

  //update PWM channels based on position
  int ul, vl, wl;
  int ur, vr, wr;

  blockPWM(cfg.vars.pwm_l, cfg.vars.pos_l, &ul, &vl, &wl);
  blockPWM(cfg.vars.pwm_r, cfg.vars.pos_r, &ur, &vr, &wr);

  LEFT_TIM->LEFT_TIM_U = CLAMP(ul + pwm_res / 2, 10, pwm_res-10);
  LEFT_TIM->LEFT_TIM_V = CLAMP(vl + pwm_res / 2, 10, pwm_res-10);
  LEFT_TIM->LEFT_TIM_W = CLAMP(wl + pwm_res / 2, 10, pwm_res-10);

  RIGHT_TIM->RIGHT_TIM_U = CLAMP(ur + pwm_res / 2, 10, pwm_res-10);
  RIGHT_TIM->RIGHT_TIM_V = CLAMP(vr + pwm_res / 2, 10, pwm_res-10);
  RIGHT_TIM->RIGHT_TIM_W = CLAMP(wr + pwm_res / 2, 10, pwm_res-10);
}
