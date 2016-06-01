# Introduction
This project provides an Arduino sketch to calibrate Electrical Speed Controllers (ESC).
ESC are used to control brushless motors.
This sketch is based on the Servo library (https://www.arduino.cc/en/Reference/Servo) that allows controling servo-motors sending them a PPM (Pulse Position Modulation) command.

This sketch was written according to the HobbyKin ESC documentation : http://www.hobbywing.com/uploadfiles/sx/file/manual/HW-01-V4.pdf

# Cabling
TODO

# Usage
After having uploaded sketch on your Arduino and having ESCs NOT powered up yet :

1. Plug your Arduino to your computer with USB cable, open terminal, then type "1".
This will send max throttle to each ESC in order to make them enter programming mode.
2. Power up your ESCs. You must hear "beep1 beep2 beep3" tones meaning the power supply is OK.
3. After 2sec, "beep beep" tone emits, meaning the throttle highest point has been correctly confirmed.
4. Then, type "0" to send 0 throttle. This will set the lowest throttle level for each ESC.
5. Several "beep" tones emits, wich means the quantity of the lithium battery cells (3 beeps for a 3 cells LiPo).
6. A long beep tone emits meaning the throttle lowest point has been correctly confirmed.
Your ESC's are now well calibrated and ready for test.
7. Type "2" to launch test function. This will send 0 to 180 throttle to ESCs : you must see your motors starting to run with increasing speed.
