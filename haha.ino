
#include "UltraSonicDistanceSensor.h"

const int trigBack = 53; //chan trig sau
const int echoBack = 52; // chan echo sau
const int trigFront = 47; // chan trig truoc
const int echoFront = 46; // chan echo truoc

UltraSonicDistanceSensor distanceBack(trigBack, echoBack);  // Initialize sensor that uses digital pins 43 and 42
UltraSonicDistanceSensor distanceFront(trigFront, echoFront);  // Initialize sensor that uses digital pins 45 and 44
double valuecm1 = 0;
double valuecm2 = 0;
void setup () {
  Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
  
}

void loop () {
    // Every 100 miliseconds, do a measurement using the sensor and print the distance in centimeters.
    if(distanceBack.available() == true){
        valuecm1 = distanceBack.getcm();
        
        Serial.println(valuecm1);
    }
    if(distanceFront.available() == true)
    {
      valuecm2 = distanceFront.getcm();
      Serial.println(valuecm2);

    }
    delay(500);
}
