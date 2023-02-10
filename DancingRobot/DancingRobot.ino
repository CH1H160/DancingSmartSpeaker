#include <WiFi.h>
#include <Espalexa.h>
#include <SCServo.h>
#include "motion.h"

SCSCL servo;
Espalexa espalexa;

const int WAIT_TIME = 500;
const char* ssid = "<SSID>";
const char* password = "<PASSWORD>";

void valueChanged(EspalexaDevice* dev);

void setup(){
  Serial2.begin(1000000);
  servo.pSerial = &Serial2;

  for (int i=1; i <= 4; i++){
    servo.EnableTorque(i, HIGH);
  }

  if(connectWifi()){
    espalexa.addDevice("DancingRobot", valueChanged);
    espalexa.begin(); 
  } 
}
 
void loop(){
   espalexa.loop();
   delay(1);
}

void valueChanged(EspalexaDevice* dev){
  if (dev->getValue()){
    delay(2500);
    dancing();
  } 
}

boolean connectWifi(){
  boolean state = true;
  int i = 0;
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(WAIT_TIME);
    if (i > 20){
      state = false; break;
    }
    i++;
  }
  return state;
}

void dancing() {
  int motion = sizeof(pos)/sizeof(*pos);

  for (int i=0; i < motion; i++){
    for (int j=1; j <= 4; j++){
      servo.WritePos(j, pos[i][j-1], WAIT_TIME);
    }
    delay(WAIT_TIME);
  }
}
