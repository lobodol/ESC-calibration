[![Build Status](https://travis-ci.org/lobodol/ESC-calibration.svg?branch=master)](https://travis-ci.org/lobodol/ESC-calibration)

# 1. Introduction
This project provides an Arduino sketch to calibrate up to 4 Electrical Speed Controllers (ESC) at the same time. Feel free to update this sketch if you need to calibrate more than 4 ESCs.

ESC are used to control brushless motors.
This sketch is based on the [Servo library](https://www.arduino.cc/en/Reference/Servo) that allows controling servo-motors sending them a 50Hz [servo-control](https://en.wikipedia.org/wiki/Servo_control) signal (a particular kind of PWM).
Generated pulses length are about 1000µs to 2000µs. Feel free to edit pulses length according to your needs.

This sketch was written according to the [HobbyKing ESC documentation](https://www.firediy.fr/files/drone/HW-01-V4.pdf)

A detailed tutorial is available [here](https://www.firediy.fr/article/calibrer-ses-esc-avec-un-arduino-drone-ch-3) (in french).

# 2. Cabling
## 2.1 Motor to ESC
Connect each motor (3 wires) to its ESC. The way of wiring doesn't matter : brushless motors are like 3-phased motors, thus it only affects the direction of rotation. For calibration step, direction of rotation is not important.

:warning: Do NOT place propellers on motors if you care about your fingers !

## 2.2 Arduino to ESCs
Connect each ESC's ground to the Arduino's ground to make all having common ground.
Most of the time, ESC's command wire is white, then connect them as following : 
 - ESC1 to Arduino's digital pin #4
 - ESC2 to Arduino's digital pin #5
 - ESC3 to Arduino's digital pin #6 
 - ESC4 to Arduino's digital pin #7
    
:information_source: If you don't want to calibrate all ESCs at the time, you're free to connect them one by one and run the Arduino sketch, it doesn't make any difference.
![ESC cabling](https://www.firediy.fr/images/articles/drone-3/esc_calib.jpg)

:warning: The Arduino will be powered by USB cable. Do not power the Arduino with the BEC output of an ESC to prevent any damage.

# 3. Usage
After having uploaded sketch on your Arduino and having ESCs **not powered up yet** :

1. Plug your Arduino to your computer with USB cable, open terminal, then type :one:.
This will send max throttle to each ESC in order to make them enter programming mode.
2. Power up your ESCs. You must hear "beep1 beep2 beep3" tones meaning the power supply is OK.
3. After 2sec, "beep beep" tone emits, meaning the throttle highest point has been correctly confirmed.
4. Then, type :zero: to send 0 throttle. This will set the lowest throttle level for each ESC.
5. Several "beep" tones emits, wich means the quantity of the lithium battery cells (3 beeps for a 3 cells LiPo).
6. A long beep tone emits meaning the throttle lowest point has been correctly confirmed.
Your ESC's are now well calibrated and ready for test.
7. Type :two: to launch test function. This will send 0 to max throttle to ESCs : you must see your motors starting to run with increasing speed, then stop when maximum speed is reached.
