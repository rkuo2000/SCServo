/*
The normal write example passed the test in ST3215 Servo, 
and if testing other models of ST series servos
please change the appropriate position, speed and delay parameters.
*/

#include <SCServo.h>

SMS_STS st;

// the UART used to control servos.
// GPIO 18 - S_RXD, GPIO 19 - S_TXD, as default.
#define SERVO_ID 1

void setup()
{
  Serial.begin(115200);
  Serial2.begin(1000000, SERIAL_8N1);
  st.pSerial = &Serial2;
  delay(1000);
}

void loop()
{
  Serial.print("Servo ID = ");
  Serial.println(SERVO_ID);

  // LeRobot Servo_ID=1, speed=3400，acc=50，move to position=745.
  // LeRobot Servo_ID=6, speed=3400，acc=50，move to position=2039.
  st.WritePosEx(SERVO_ID, 745, 3400, 50);                                        
  delay(2000);

  // LeRobot Servo_ID=1, speed=3400，acc=50，move to position=3461.
  // LeRobot Servo_ID=6, speed=3400，acc=50，move to position=3527.
  st.WritePosEx(SERVO_ID, 3461, 3400, 50); 
  delay(2000);
}
