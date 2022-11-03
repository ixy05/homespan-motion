/*
This code was taken completly from a discussion in the HomeSpan repo.
https://github.com/HomeSpan/HomeSpan/discussions/159#discussioncomment-1518045
Commented by https://github.com/PhilBrien
*/


struct DEV_MotionSensor : Service::MotionSensor {                       // Motion sensor

  SpanCharacteristic *movement;                                         // reference to the MotionDetected Characteristic
  int sensorPin;                                                        // pin number of the sensor

  DEV_MotionSensor(int sensorPin) : Service::MotionSensor() {

    this->sensorPin = sensorPin;
    pinMode(sensorPin, INPUT);
    boolean motion = digitalRead(sensorPin);
    movement = new Characteristic::MotionDetected(motion);              // instantiate the MotionDetected Characteristic

  } // end constructor

  void loop() {
    boolean motion = digitalRead(sensorPin);
    if (motion != movement->getVal()) {
      movement->setVal(motion);
      if (motion == true) {
        char c[64];
        sprintf(c, "Motion was detected\n");
        LOG1(c);
      }
    }
  }
};
