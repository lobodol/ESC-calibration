/**
 * Usage, according to documentation(http://www.hobbywing.com/uploadfiles/sx/file/manual/HW-01-V4.pdf) : 
 *     Power up your Arduino, then type 1 to send max throttle to every ESC.
 *     Power up your ESCs.
 *     1. You must hear a beep1 beep2 beep3 sounds meaning the ESC is powered up
 *     2. After 2sec, you must hear beep beep, meaning that max throttle has been stored
 *     3. Type 0 to send 0 throttle
 *     4. You must hear one long beep meaning that min throttle has been stored.
 *     5. Type 2 to launch test function. This will send 0 to 180 throttle to ESCs to test them.
 */

#include <Servo.h>

Servo motA, motB, motC, motD;
char data;

/**
 * Initialisation routine
 */
void setup() {
    Serial.begin(9600);
    
    motA.attach(4, 1000, 2000);
    motB.attach(5, 1000, 2000);
    motC.attach(6, 1000, 2000);
    motD.attach(7, 1000, 2000);
    
    displayInstructions();
}

/**
 * Main function
 */
void loop() {
    if (Serial.available()) {
        data = Serial.read();

        switch (data) {
            // 0
            case 48 : Serial.println("Sending 0 throttle");
                      motA.write(0);
                      motB.write(0);
                      motC.write(0);
                      motD.write(0);
            break;

            // 1
            case 49 : Serial.println("Sending 180 throttle");
                      motA.write(180);
                      motB.write(180);
                      motC.write(180);
                      motD.write(180);
            break;

            // 2
            case 50 : Serial.print("Running test in 3");
                      delay(1000);
                      Serial.print(" 2");
                      delay(1000);
                      Serial.println(" 1...");
                      delay(1000);
                      test();
            break;
        }
    }
    

}

/**
 * Test function sending angle to the ESCs from 0 to 180 degrees
 */
void test()
{
    for (int i=0; i<=180; i++) {
        Serial.print("Speed = ");
        Serial.println(i);
        
        motA.write(i);
        motB.write(i);
        motC.write(i);
        motD.write(i);
        
        delay(200);
    }

    Serial.println("STOP");
    motA.write(0);
    motB.write(0);
    motC.write(0);
    motD.write(0);
}

/**
 * Displays instructions to user
 */
void displayInstructions()
{  
    Serial.println("READY - PLEASE SEND INSTRUCTIONS AS FOLLOWING :");
    Serial.println("\t0 : Sends 0 throttle");
    Serial.println("\t1 : Sends 180 throttle");
    Serial.println("\t2 : Runs test function\n");
}

