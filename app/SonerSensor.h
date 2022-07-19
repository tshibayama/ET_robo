//
 // SonarSensor.h
 //
 // Copyright (c) 2015-2016 Embedded Technology Software Design Robot Contest
 //
 
 #ifndef EV3CPPAPI_SONARSENSOR_H_
 #define EV3CPPAPI_SONARSENSOR_H_
 
 #include "Sensor.h"
 
 namespace ev3api {
 class SonarSensor: public Sensor
 {
 public:
     explicit SonarSensor(ePortS port);
 
     virtual ~SonarSensor(void);
 
     int16_t getDistance(void) const;
 
     bool listen(void) const;
 }; // class SonarSensor
 }  // namespace ev3api
 
 #endif // ! EV3CPPAPI_SONARSENSOR_H_