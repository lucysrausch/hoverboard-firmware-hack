# hoverboard-firmware-hack

This is a Fork fom NiklasFauth's hoverboard-firmware-hack.

The goal is to make the board more configurable without requiring reprogramming for every setting, 
and to allow controller the board over different interfaces.

Current state:
 - implemented dma/interrupt based UART2/3 RX/TX (see uart.h/c)
 - implemented simple modbus slave (supports commands 0x3(read) and ox10(write). Works with open-source QtModMaster tool
 - cleaned code from some hacks/features. Some will be re-added later
      - removed I2C/ADC/PWM control. This will be re-integrated soon
      - clean up BLDC ADC handler, now more efficient, and only dealing with motors
      - no more delays in code, but rather non-blocking Tick() based updates
      - disabled buzzer, man I hate buzzers
      
      
Coming soon:
  - wrapper on modbus.c/h and gui to allow reading and writing arbritrary user defined settings using GUI only
  - selectable control method (UART / I2C / ADC / PWM)
  - motor speed tacho
  - merge Niklas's updates
  
Coming later:
  - adding plot capabilities to the GUI to allow monitoring all the user configured variables
  
  
If you have any feature requests, open up an issue and I will get back to you a.s.a.p!


   
