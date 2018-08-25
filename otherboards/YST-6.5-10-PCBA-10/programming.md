I used a 'blue pill' STLink-v2 from 

Install Openocd

In windows from here http://gnutoolchains.com/arm-eabi/openocd/

run go to the bin folder, and run 

openocd -f interface/stlink-v2.cfg -f target/stm32f1x.cfg

telnet to 127.0.0.1:4444

type:

reset halt

stm32f1x unlock 0

if you have a .hex file (like the repo contains):

flash write_image erase C:\\DataNoBackup\\hoverboard\\src\\build\\hover.hex 0 ihex

if you have a .bin file (like made by platformio):

flash write_image firmware.bin 0 

programming the hover.hex from the original repo certainly operates the wheels, and generates debug output!

for platformio generated bin:

flash write_image erase C:\\DataNoBackup\\hoverboard\\.pioenvs\\genericSTM32F103RC\\firmware.bin 0x08000000 bin

both should work.......

(check diagnostic output if configured)



