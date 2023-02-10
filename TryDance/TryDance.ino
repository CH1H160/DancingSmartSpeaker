#include <SCServo.h>
SCSCL servo;

int pos[][4]={
{// ここにサーボの位置配列データを入れます。
};

void setup() {
  Serial2.begin(1000000);
  servo.pSerial = &Serial2;

  for (int i=1; i <= 4; i++){
    servo.EnableTorque(i, HIGH);
  }
}

void loop() {

  int motion = sizeof(pos)/sizeof(*pos);

  for (int i=0; i < motion; i++){
    for (int j=1; j <= 4; j++){
      servo.WritePos(j, pos[i][j-1], 500);
    }
    delay(500);
  }
}
