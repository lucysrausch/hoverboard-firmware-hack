This is a GD32F103RCT6 based device.

The original firmware is locked, and so can't be extracted.  However, I have captured the periferal register values and done some analysis of the communications between the main board and the sensor boards.


Note that 

GD32 USART1 = STM USART2

GD32 USART2 = STM USART3


Original firmware communications, as observed by connection a serial port at then powering up: 

Main to Sensors:

Baud rate: 52177 baud, 9 bits, 1 stop bit.

Note: this is roughly double the baud rate stated here: http://drewspewsmuse.blogspot.com/2016/06/how-i-hacked-self-balancing-scooter.html - this could be because of the MCU used.  Also, the data seems extended....

Baud rate both estimated with a 'scope, and read from the MCU periferal registers.

bytes: frames of 6 bytes, 4 leading zeros.
The LAST byte has 0x1xx set in 9 bit mode.

e.g. from boot:

00 00 00 00 00 00

sometimes:

00 00 00 00 1E 00 (seems to depend on if motor is powered)

LEDs:

Green: 00 00 00 00 00 04

Red: 00 00 00 00 00 08

Headlights: 00 00 00 00 00 01


Sensor boards to main board:

From boot:

00 00 00 00 AA 00 00 00 00 00 

(70 repetitions)

then

00 00 00 00 AA 58 58 00 00 00 

3E BC 3E BC AA 58 58 00 00 00 

3E BC 3E BC AA 58 58 00 00 00 

3E BC 3E BC AA 58 58 01 00 00 


Breakdown:

Bytes 0-1 and 2-3: first two pairs of bytes are angle of feet, in little endian 16 bit, repeated once.

*3E *BC *3E *BC AA 58 58 01 00 00 


i.e. 00 00 -> flat.  10 00 ->slightly one way.  f0ff ->slightly the other way.

range (in 16 bit hex): ~4500 -> 0000 -> b900 (from upsidedown to upsidedown, with 0000 being 'level').

Byte 4: The AA byte bcomes 55 if either IR sensor is broken.

3E BC 3E BC *AA 58 58 01 00 00 

Bytes 5-6: The next two byte are 58 58, these seem to be acceleration detection (they change when the hoverboard is moved).

3E BC 3E BC AA *58 *58 01 00 00 

Bytes 7-8: the next two bytes are angle 'side to side'

range (in 16 bit hex): ~E000 -> 0000 -> 4500 (from on end one way, to on end the other way)

3E BC 3E BC AA 58 58 *01 *00 00 

Byte 9: Always observed zero, and is 0x100 in 9 biot serial, marking end of frame.





