/*
The RegWritePos example passed the test in ST3215 Servo, 
and if testing other models of ST series servos
please change the appropriate position, speed and delay parameters.
*/

#include <SCServo.h>

SMS_STS st;

// the UART used to control servos.
// GPIO 18 - S_RXD, GPIO 19 - S_TXD, as default.

void setup()
{
  Serial.begin(115200);
  Serial2.begin(1000000, SERIAL_8N1);
  st.pSerial = &Serial2;
  delay(1000);
}

void loop()
{
  const int ID1 = 1;
  const int ID2 = 2;
  Serial.print("Sweeping Servo "); Serial.print(ID1); Serial.print(" to pos "); Serial.println(4000);
  Serial.print("Sweeping Servo "); Serial.print(ID2); Serial.print(" to pos "); Serial.println(4000);
  st.RegWritePosEx(ID1, 4000, 3400, 50); // servo(ID1) speed=3400，acc=50，move to position=4095.
  st.RegWritePosEx(ID2, 4000, 3400, 50); // servo(ID2) speed=3400，acc=50，move to position=4095.
  st.RegWriteAction();
  delay(3000);

  Serial.print("Sweeping Servo "); Serial.print(ID1); Serial.print(" to pos "); Serial.println(1000);
  Serial.print("Sweeping Servo "); Serial.print(ID2); Serial.print(" to pos "); Serial.println(1000);
  st.RegWritePosEx(ID1, 1000, 3400, 50); // servo(ID1) speed=3400，acc=50，move to position=0.
  st.RegWritePosEx(ID2, 1000, 3400, 50); // servo(ID2) speed=3400，acc=50，move to position=0.
  st.RegWriteAction();
  delay(3000);

  while(1);
}
