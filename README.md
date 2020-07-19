# hoverboard-firmware-hack-SIN
## With Sinusoidal BLDC control and Phase Advance
[![Build Status](https://travis-ci.com/EmanuelFeru/hoverboard-firmware-hack-SIN.svg?branch=master)](https://travis-ci.com/EmanuelFeru/hoverboard-firmware-hack)

This repository improves significantly the performance of the previous BLDC motor control for hoverboards developed by [NiklasFauth](https://github.com/NiklasFauth/hoverboard-firmware-hack). Compared to previous commutation method, this project implements 3 more additional control methods. The new control methods offers superior performance featuring:
 - reduced noise and vibrations 	
 - smooth torque output 	
 - improved motor efficiency. Thus, lower energy consumption
 - automatic phase advance / field weakening
 
 ### This repository is not supported any more! See my new [firmware based on FOC motor control](https://github.com/EmanuelFeru/hoverboard-firmware-hack-FOC) for latest updates. The new firmware still offers the posiblity to select Sinusoidal control.
 

![Schematic representation of the control methods](https://raw.githubusercontent.com/EmanuelFeru/hoverboard-firmware-hack/master/01_Matlab/02_Figures/control_methods.png)

A classification of the BLDC control methods in terms of performance is as follows:

|Control method| Torque output | Noise performance | Efficiency |
|--|--|--|--|
|Commutation| High | Low | Low |
|Pure Trapezoidal| High | Medium | Medium |
|Sinusoidal| Medium | High | High
|Sinusoidal 3rd harmonic| High | High | High |

> All these 4 methods are available in this repository and can be selected by a calibratable inside 'config.h' file. Default selected method: *Sinusoidal 3rd harmonic*.

A short video showing the noise performance of the Commutation method vs Sinusoidal 3rd harmonic can be found here:
[►Video: Commutation method vs Sinusoidal 3rd harmonic](https://drive.google.com/file/d/1vC_kEkp2LE2lAaMCJcmK4z2m3jrPUoBD/view)

![Hoverboard wheel](https://raw.githubusercontent.com/EmanuelFeru/hoverboard-firmware-hack/master/docs/pictures/hoverboard_wheel.JPG)


** A more detailed and better movie will come soon... so stay tuned ;)

---
GENERAL NOTES:
 - All the calibratable motor parameters can be found in the 'BLDC_controller_data.c'. I provided you with an already calibrated controller, but if you feel like fine tuning it feel free to do so.
 - The C code for the controller was auto-code generated using [Matlab/Simulink](https://nl.mathworks.com/solutions/embedded-code-generation.html) from a model which I developed from scratch specifically for hoverboard control. For more details regarding the parameters and the working principle of the controller please consult the [Matlab/Simulink model](https://github.com/EmanuelFeru/hoverboard-firmware-hack/tree/master/01_Matlab).
 - A [webview](https://github.com/EmanuelFeru/hoverboard-firmware-hack/tree/master/01_Matlab/BLDC_controller_ert_rtw/html/webview) was created, so Matlab/Simulink installation is not needed, unless you want to regenerate the code

NOTES Phase Advance / Field weakening:

 - The Phase Advance engages automatically and smooth (no need for boost buttons or additional fancy arrangements). You can re-calibrate the Phase Advance to your needs and your liking. 
 - The default map was experimentally calibrated on the real motor based on the minimum noise and minimum torque ripple
 - If you re-calibrate the Phase advance map please take all the safety measures! The motors can spin VERY VERY FAST! Please use it with care!
 - I do not recommend more than 40 deg MAX Phase advance. 

---
## Building 
For building (and flashing) I recommend platform.io, plaformio.ini file included. Simply open the folder in the IDE of choice (vscode or Atom), and press the 'PlatformIO:Build' or the 'PlatformIO:Upload' button (bottom left in vscode).

Additionally, you can also flash using the method described below in the Flashing Section.

---

## Hardware
![otter](https://raw.githubusercontent.com/EmanuelFeru/hoverboard-firmware-hack/master/pinout.png)

The original Hardware supports two 4-pin cables that originally were connected to the two sensor boards. They break out GND, 12/15V and USART2&3 of the Hoverboard mainboard.
Both USART2 & 3 can be used for UART and I2C, PA2&3 can be used as 12bit ADCs.

The mainboard reverse-engineered schematics (PCB Markings: 679393 20150722):
http://vocke.tv/lib/exe/fetch.php?media=20150722_hoverboard_sch.pdf

The mainboard reverse-engineered schematics (PCB Markings: YST-DXT-J20 V4):
http://vocke.tv/lib/exe/fetch.php?media=20190620_at32_hover_sch.pdf

---

## Flashing
To build the firmware, just type "make". Make sure you have specified your gcc-arm-none-eabi binary location in the Makefile ("PREFIX = ...") (version 7 works, there is a version that does not!) (if the ons in linux repos do not work, use the official version: https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads). Right to the STM32, there is a debugging header with GND, 3V3, SWDIO and SWCLK. Connect GND, SWDIO and SWCLK to your SWD programmer, like the ST-Link found on many STM devboards.

Do not power the mainboard from the 3.3V of your programmer! This has already killed multiple mainboards.

Make sure you hold the powerbutton or connect a jumper to the power button pins while flashing the firmware, as the STM might release the power latch and switches itself off during flashing. Battery > 36V have to be connected while flashing.

To flash the STM32, use the ST-Flash utility (https://github.com/texane/stlink).

If you never flashed your mainboard before, the STM is probably locked. To unlock the flash, use the following OpenOCD command:
```
openocd -f interface/stlink-v2.cfg -f target/stm32f1x.cfg -c init -c "reset halt" -c "stm32f1x unlock 0"
```

If that does not work:
```
openocd -f interface/stlink-v2.cfg -f target/stm32f1x.cfg -c init -c "reset halt" -c "mww 0x40022004 0x45670123" -c "mww 0x40022004 0xCDEF89AB" -c "mww 0x40022008 0x45670123" -c "mww 0x40022008 0xCDEF89AB" -c "mww 0x40022010 0x220" -c "mww 0x40022010 0x260" -c "sleep 100" -c "mww 0x40022010 0x230" -c "mwh 0x1ffff800 0x5AA5" -c "sleep 1000" -c "mww 0x40022010 0x2220" -c "sleep 100" -c "mdw 0x40022010" -c "mdw 0x4002201c" -c "mdw 0x1ffff800" -c targets -c "halt" -c "stm32f1x unlock 0"
```
```
openocd -f interface/stlink-v2.cfg -f target/stm32f1x.cfg -c init -c "reset halt" -c "mww 0x40022004 0x45670123" -c "mww 0x40022004 0xCDEF89AB" -c "mww 0x40022008 0x45670123" -c "mww 0x40022008 0xCDEF89AB" -c targets -c "halt" -c "stm32f1x unlock 0"
```
Or use the Windows ST-Link utility.

Then you can simply flash the firmware:
```
st-flash --reset write build/hover.bin 0x8000000
```
or
```
openocd -f interface/stlink-v2.cfg -f target/stm32f1x.cfg -c flash "write_image erase build/hover.bin 0x8000000"
```

---
## Troubleshooting
First, check that power is connected and voltage is >36V while flashing.
If the board draws more than 100mA in idle, it's probably broken.

If the motors do something, but don't rotate smooth and quietly, try to use an alternative phase mapping. Usually, color-correct mapping (blue to blue, green to green, yellow to yellow) works fine. However, some hoverboards have a different layout then others, and this might be the reason your motor isn't spinning.

Nunchuck not working: Use the right one of the 2 types of nunchucks. Use i2c pullups.

Nunchuck or PPM working bad: The i2c bus and PPM signal are very sensitive to emv distortions of the motor controller. They get stronger the faster you are. Keep cables short, use shielded cable, use ferrits, stabilize voltage in nunchuck or reviever, add i2c pullups. To many errors leads to very high accelerations which triggers the protection board within the battery to shut everything down.

Most robust way for input is to use the ADC and potis. It works well even on 1m unshielded cable. Solder ~100k Ohm resistors between ADC-inputs and gnd directly on the mainboard. Use potis as pullups to 3.3V.

---


## Examples

Have a look at the config.h in the Inc directory. That's where you configure to firmware to match your project.
Currently supported: Wii Nunchuck, analog potentiometer and PPM-Sum signal from a RC remote.
A good example of control via UART, eg. from an Arduino or raspberryPi, can be found here:
https://github.com/p-h-a-i-l/hoverboard-firmware-hack
