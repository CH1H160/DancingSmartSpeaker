#include <SCServo.h>

SCSCL servo;

void setup(){
  Serial.begin(115200);
  Serial2.begin(1000000);
  servo.pSerial = &Serial2;
}

void loop(){
  for (int i = 1; i <= 4; i++){
    if(i == 1){Serial.print("{");}
    Serial.print(servo.ReadPos(i));
    if(i == 4){
      Serial.println("},");
    }else{
      Serial.print(",");
    }
  }
  delay(1000);
}
