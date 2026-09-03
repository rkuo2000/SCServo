/*
example for changing ID.
*/

#include <SCServo.h>

SMS_STS sms_sts;
// the UART used to control servos.
// GPIO 18 - S_RXD, GPIO 19 - S_TXD, as default.

int ID_ChangeFrom = 11;
int ID_ChangeTo   = 1;

void setup()
{
  int ID;
  Serial.begin(115200);
  Serial2.begin(1000000, SERIAL_8N1);
  sms_sts.pSerial = &Serial2;
  delay(1000);

  // Change ID 
  sms_sts.unLockEprom(1); // unlock EPROM-SAFE
  sms_sts.writeByte(ID_ChangeFrom, SMS_STS_ID, ID_ChangeTo); // ID
  sms_sts.LockEprom(ID_ChangeTo); // EPROM-SAFE locked
  Serial.print("Change Servo ID from ");
  Serial.print(ID_ChangeFrom);
  Serial.print(" to ");
  Serial.println(ID_ChangeTo);
}

void loop()
{

}
