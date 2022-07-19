 //
 // GyroSensor.h
 //
 // Copyright (c) 2015-2016 Embedded Technology Software Design Robot Contest
 //
 
 #ifndef EV3CPPAPI_GYROSENSOR_H_
 #define EV3CPPAPI_GYROSENSOR_H_
 
 #include "Sensor.h"
 
 namespace ev3api {
 class GyroSensor: public Sensor
 {
 public:
     static const int16_t DEFAULT_OFFSET = 0;
 
     explicit GyroSensor(ePortS port);
 
     void setOffset(int16_t offset);
 
     void reset(void);
 
     int16_t getAnglerVelocity(void) const;
 
     int16_t getAngle(void) const;
 
 private:
     int16_t mOffset;
 }; // class GyroSensor
 }  // namespace ev3api
 
 #endif // ! EV3CPPAPI_GYROSENSOR_H_