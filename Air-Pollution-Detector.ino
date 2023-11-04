#include <SDS011.h>

SDS011 mySensor;
float pm25Value = 0;
float pm10Value = 0;

void setup() {
  Serial.begin(9600);
  mySensor.begin(Serial1); // Serial1 is used for communication with SDS011 sensor
}

void loop() {
  if (mySensor.read()) {
    pm25Value = mySensor.getPM25();
    pm10Value = mySensor.getPM10();
    
    Serial.print("PM2.5: ");
    Serial.print(pm25Value);
    Serial.print(" µg/m3\t");
    
    Serial.print("PM10: ");
    Serial.print(pm10Value);
    Serial.println(" µg/m3");
  } else {
    Serial.println("Unable to read from the sensor");
  }
  
  delay(1000); // Wait for 1 second before taking the next reading
}
