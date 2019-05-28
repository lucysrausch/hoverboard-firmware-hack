---


---

<h1 id="hoverboard-firmware-hack">hoverboard-firmware-hack</h1>
<h2 id="with-sinusoidal-bldc-control-and-phase-advance">With Sinusoidal BLDC control and Phase Advance</h2>
<p><a href="https://travis-ci.org/joemccann/dillinger"><img src="https://travis-ci.org/joemccann/dillinger.svg?branch=master" alt="Build Status"></a></p>
<p>This repository improves significantly the performance of the previous BLDC motor control for hoverboards developed by <a href="https://github.com/NiklasFauth/hoverboard-firmware-hack">NiklasFauth</a>. Compared to previous commutation method, this project implements 3 more additional control methods. The new control methods offers superior performance featuring:</p>
<ul>
<li>reduced noise and vibrations</li>
<li>smooth torque output</li>
<li>improved motor efficiency. Thus, lower energy consumption</li>
<li>automatic phase advance / field weakening</li>
</ul>
<pre><code>![Schematic representation of the control methods](http://url/to/img.png)
</code></pre>
<p><img src="https://github.com/EmanuelFeru/hoverboard-firmware-hack/blob/master/01_Matlab/02_Figures/control_methods.png" alt="Schematic representation of the control methods"></p>
<p><a href="https://github.com/EmanuelFeru/hoverboard-firmware-hack/blob/master/docs/pictures/hoverboard_wheel.JPG">Hoverboard wheel</a></p>
<p>A classification of the BLDC control methods in terms of performance is as follows:</p>

<table>
<thead>
<tr>
<th>Control method</th>
<th>Torque output</th>
<th>Noise performance</th>
<th>Efficiency</th>
</tr>
</thead>
<tbody>
<tr>
<td>Commutation</td>
<td>High</td>
<td>Low</td>
<td>Low</td>
</tr>
<tr>
<td>Pure Trapezoidal</td>
<td>High</td>
<td>Medium</td>
<td>Medium</td>
</tr>
<tr>
<td>Sinusoidal</td>
<td>Medium</td>
<td>High</td>
<td>High</td>
</tr>
<tr>
<td>Sinusoidal 3rd harmonic</td>
<td>High</td>
<td>High</td>
<td>High</td>
</tr>
</tbody>
</table><blockquote>
<p>All these 4 methods are available in this repository and can be selected by a calibratable inside ‘config.h’ file. Default selected method: <em>Sinusoidal 3rd harmonic</em>.</p>
</blockquote>
<p>A short video showing the noise performance of the Commutation method vs Sinusoidal 3rd harmonic can be found here:<br>
<a href="https://drive.google.com/file/d/1vC_kEkp2LE2lAaMCJcmK4z2m3jrPUoBD/view">►Video: Commutation method vs Sinusoidal 3rd harmonic</a><br>
** A more detailed and better movie will come soon… so stay tuned ;)</p>
<hr>
<p>GENERAL NOTES:</p>
<ul>
<li>All the calibratable motor parameters can be found in the ‘BLDC_controller_data.c’. I provided you with an already calibrated controller, but if you feel like fine tuning it feel free to do so.</li>
<li>The C code for the controller was auto-code generated using <a href="https://nl.mathworks.com/solutions/embedded-code-generation.html">Matlab/Simulink</a> from a model which I developed from scratch specifically for hoverboard control. For more details regarding the parameters and the working principle of the controller please consult the Matlab/Simulink model.</li>
<li>A webview was created, so Matlab/Simulink installation is not needed, unless you want to regenerate the code</li>
</ul>
<p>NOTES Phase Advance / Field weakening:</p>
<ul>
<li>The Phase Advance engages automatically and smooth (no need to boost buttons, no need for additional fancy arrangements). You can re-calibrate the Phase Advance to your needs and your liking.</li>
<li>The default calibration was experimentally calibrated on the real motor based on the minimum noise and minimum torque ripple</li>
<li>If you re-calibrate the Phase advance map please take all the safety measures! The motors can spin VERY VERY FAST… crazy fast! Please use it with care!</li>
<li>I do not recommend more than 40 deg MAX Phase advance.</li>
</ul>
<h3 id="future-work">Future work</h3>
<ul>
<li>we will try to fit this new controller into the hoverboard main functionality of <a href="https://github.com/bipropellant/bipropellant-hoverboard-firmware">bipropellant</a> I still need to ask if he would like to take this up :)</li>
<li>use it for other robotic applications</li>
</ul>
<hr>
<h2 id="building">Building</h2>
<p>For building (and flashing) I recommend <a href="http://platform.io">platform.io</a>, plaformio.ini file included. Simply open the folder in the IDE of choice (vscode or Atom), and press the ‘PlatformIO:Build’ or the ‘PlatformIO:Upload’ button (bottom left in vscode).</p>
<p>Additionally, you can also flash using the method described below in the Flashing Section.</p>
<h2 id="hardware">Hardware</h2>
<p><img src="https://raw.githubusercontent.com/NiklasFauth/hoverboard-firmware-hack/master/pinout.png" alt="otter"></p>
<p>The original Hardware supports two 4-pin cables that originally were connected to the two sensor boards. They break out GND, 12/15V and USART2&amp;3 of the Hoverboard mainboard.<br>
Both USART2 &amp; 3 can be used for UART and I2C, PA2&amp;3 can be used as 12bit ADCs.</p>
<p>The reverse-engineered schematics of the mainboard can be found here:<br>
<a href="http://vocke.tv/lib/exe/fetch.php?media=20150722_hoverboard_sch.pdf">http://vocke.tv/lib/exe/fetch.php?media=20150722_hoverboard_sch.pdf</a></p>
<hr>
<h2 id="flashing">Flashing</h2>
<p>To build the firmware, just type “make”. Make sure you have specified your gcc-arm-none-eabi binary location in the Makefile (“PREFIX = …”) (version 7 works, there is a version that does not!) (if the ons in linux repos do not work, use the official version: <a href="https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads">https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads</a>). Right to the STM32, there is a debugging header with GND, 3V3, SWDIO and SWCLK. Connect GND, SWDIO and SWCLK to your SWD programmer, like the ST-Link found on many STM devboards.</p>
<p>Do not power the mainboard from the 3.3V of your programmer! This has already killed multiple mainboards.</p>
<p>Make sure you hold the powerbutton or connect a jumper to the power button pins while flashing the firmware, as the STM might release the power latch and switches itself off during flashing. Battery &gt; 36V have to be connected while flashing.</p>
<p>To flash the STM32, use the ST-Flash utility (<a href="https://github.com/texane/stlink">https://github.com/texane/stlink</a>).</p>
<p>If you never flashed your mainboard before, the STM is probably locked. To unlock the flash, use the following OpenOCD command:</p>
<pre><code>openocd -f interface/stlink-v2.cfg -f target/stm32f1x.cfg -c init -c "reset halt" -c "stm32f1x unlock 0"
</code></pre>
<p>If that does not work:</p>
<pre><code>openocd -f interface/stlink-v2.cfg -f target/stm32f1x.cfg -c init -c "reset halt" -c "mww 0x40022004 0x45670123" -c "mww 0x40022004 0xCDEF89AB" -c "mww 0x40022008 0x45670123" -c "mww 0x40022008 0xCDEF89AB" -c "mww 0x40022010 0x220" -c "mww 0x40022010 0x260" -c "sleep 100" -c "mww 0x40022010 0x230" -c "mwh 0x1ffff800 0x5AA5" -c "sleep 1000" -c "mww 0x40022010 0x2220" -c "sleep 100" -c "mdw 0x40022010" -c "mdw 0x4002201c" -c "mdw 0x1ffff800" -c targets -c "halt" -c "stm32f1x unlock 0"
</code></pre>
<pre><code>openocd -f interface/stlink-v2.cfg -f target/stm32f1x.cfg -c init -c "reset halt" -c "mww 0x40022004 0x45670123" -c "mww 0x40022004 0xCDEF89AB" -c "mww 0x40022008 0x45670123" -c "mww 0x40022008 0xCDEF89AB" -c targets -c "halt" -c "stm32f1x unlock 0"
</code></pre>
<p>Or use the Windows ST-Link utility.</p>
<p>Then you can simply flash the firmware:</p>
<pre><code>st-flash --reset write build/hover.bin 0x8000000
</code></pre>
<p>or</p>
<pre><code>openocd -f interface/stlink-v2.cfg -f target/stm32f1x.cfg -c flash "write_image erase build/hover.bin 0x8000000"
</code></pre>
<hr>
<h2 id="troubleshooting">Troubleshooting</h2>
<p>First, check that power is connected and voltage is &gt;36V while flashing.<br>
If the board draws more than 100mA in idle, it’s probably broken.</p>
<p>If the motors do something, but don’t rotate smooth and quietly, try to use an alternative phase mapping. Usually, color-correct mapping (blue to blue, green to green, yellow to yellow) works fine. However, some hoverboards have a different layout then others, and this might be the reason your motor isn’t spinning.</p>
<p>Nunchuck not working: Use the right one of the 2 types of nunchucks. Use i2c pullups.</p>
<p>Nunchuck or PPM working bad: The i2c bus and PPM signal are very sensitive to emv distortions of the motor controller. They get stronger the faster you are. Keep cables short, use shielded cable, use ferrits, stabilize voltage in nunchuck or reviever, add i2c pullups. To many errors leads to very high accelerations which triggers the protection board within the battery to shut everything down.</p>
<p>Most robust way for input is to use the ADC and potis. It works well even on 1m unshielded cable. Solder ~100k Ohm resistors between ADC-inputs and gnd directly on the mainboard. Use potis as pullups to 3.3V.</p>
<hr>
<h2 id="examples">Examples</h2>
<p>Have a look at the config.h in the Inc directory. That’s where you configure to firmware to match your project.<br>
Currently supported: Wii Nunchuck, analog potentiometer and PPM-Sum signal from a RC remote.<br>
A good example of control via UART, eg. from an Arduino or raspberryPi, can be found here:<br>
<a href="https://github.com/p-h-a-i-l/hoverboard-firmware-hack">https://github.com/p-h-a-i-l/hoverboard-firmware-hack</a></p>

