#include "HomeSpan.h"         // Always start by including the HomeSpan library
#include "DEV_Sensors.h"

int sensorPin = 16;                                                       // pin number of the motion sensor

void setup() {
  Serial.begin(115200);

  //homeSpan.setStatusPin(15);
  homeSpan.setWifiCredentials("SSID", "PASSWORD");        // change these to your wifi credentials
  homeSpan.setPairingCode("09654387");                    // pairing pin
  homeSpan.setControlPin(0);

  homeSpan.enableOTA(true);

  homeSpan.begin(Category::Bridges, "HS Bridge");

  new SpanAccessory();                              
  new Service::AccessoryInformation();           
  new Characteristic::Identify();                

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Identify();
  new Characteristic::Name("motion");
  new DEV_MotionSensor(16);
}

void loop() {

  homeSpan.poll();

}
