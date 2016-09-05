# Introduction
This project provides an Arduino sketch to calibrate up to 4 Electrical Speed Controllers (ESC) at the same time. Feel free to update this sketch if you need to calibrate more than 4 ESCs.
ESC are used to control brushless motors.
This sketch is based on the Servo library (https://www.arduino.cc/en/Reference/Servo) that allows controling servo-motors sending them a PPM (Pulse Position Modulation) command.

This sketch was written according to the HobbyKin ESC documentation : http://www.hobbywing.com/uploadfiles/sx/file/manual/HW-01-V4.pdf



# Cabling
## Motor to ESC
Connect each motor (3 wires) to its ESC. The way of wiring doesn't matter : brushless motors are like 3-phased motors, thus it only affects the direction of rotation. For calibration step, direction of rotation is not important.

## Arduino to ESCs
Connect each ESC's ground to the Arduino's ground to make all having common ground.
Most of the time, ESC's command wire is white, then connect them as following : 
 - First ESC to Arduino pin 4
 - Second ESC to Arduino pin 5
 - Third ESC to Arduino pin 6 
 - Last ESC to Arduino pin 7
    
(i) If you don't want to calibrate all ESCs at the time, you're free to connect them one by one and run the Arduino sketch, it doesn't make any difference.

````
Connection example for one ESC.

+---------------------+                            +---------------------+               
|       Arduino       |                            |                     |                   x  x     
|              pin #4 +--------//white-wire//------+         ESC         |--------------- x        x  
|                     |                            |                     |---------------x  Motor   x 
|              pin #5 +       +---//black-wire//---+                     |---------------x          x 
|                     |       |                    |                     |                x        x 
|              pin #6 +       |                    +---------------------+                   x  x   
|                     |       |
|              pin #7 +       |
|                     |       | 
|                 GND +-------+
|                     |
+---------------------+
```

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
