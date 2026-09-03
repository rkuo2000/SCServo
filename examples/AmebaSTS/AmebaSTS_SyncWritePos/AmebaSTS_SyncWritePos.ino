/*
The SyncWritePos example passed the test in ST3215 Servo, 
and if testing other models of ST series servos
please change the appropriate position, speed and delay parameters.
*/

#include <SCServo.h>
SMS_STS st;

// the UART used to control servos.
// GPIO 18 - S_RXD, GPIO 19 - S_TXD, as default.

byte ID[2];
s16 Position[2];
u16 Speed[2];
byte ACC[2];

void setup()
{
  Serial.begin(115200);
  Serial2.begin(1000000, SERIAL_8N1);
  st.pSerial = &Serial2;
  delay(1000);
  ID[0] = 1;
  ID[1] = 2;
  Speed[0] = 3400;
  Speed[1] = 3400;
  ACC[0] = 50;
  ACC[1] = 50;
}

void loop()
{
  Position[0] = 4000;
  Position[1] = 4000;
  Serial.print("Servo Sync Write Pos = "); Serial.println(Position[0]);  
  st.SyncWritePosEx(ID, 2, Position, Speed, ACC); // servo(ID1/ID2) speed=3400，acc=50，move to position=3000.
  delay(2000);

  Position[0] = 1000;
  Position[1] = 1000;
  Serial.print("Servo Sync Write Pos = "); Serial.println(Position[0]);   
  st.SyncWritePosEx(ID, 2, Position, Speed, ACC); // servo(ID1/ID2) speed=3400，acc=50，move to position=100.
  delay(2000);
}
