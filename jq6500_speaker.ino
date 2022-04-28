// LINK PREREQUISITE: https://sleemanj.github.io/JQ6500_Serial/html/index.html

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <JQ6500_Serial.h>

int tx = 27;
int rx = 28;

SoftwareSerial mySerial(tx, rx);
JQ6500_Serial mp3(mySerial);

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  mp3.reset();
  mp3.setVolume(30);
}

void loop() {
  // put your main code here, to run repeatedly:
  //insert dieu kien
  mp3.play();
}
