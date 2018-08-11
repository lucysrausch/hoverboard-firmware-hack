## Building the firmware in platform.io

This folder contains a platformio.ini file which results in a successful but untested build of the hoverboard firmware.

To use it, you must:

1/ make a new folder.

2/ create a sub-folder called 'src'

3/ move all the files in this repo to that folder.

4/ copy the platformio.ini file to the first folder you created.


Then, you can open the folder in platform.io (e.g. vscode or atom based IDE), and it should build.



There were a couple of changes to the source code to enable build:

a/ 'inline' was changed to 'static inline' in bldc.called

b/ 'spoof_init.c' was introduced to provide an empty '_init()' function


In the platformio.ini, source_filter is used to prevent platform.io from building ALL the files in Drivers.

