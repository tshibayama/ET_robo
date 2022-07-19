//
 // Steering.h
 //
 // Copyright (c) 2015-2016 Embedded Technology Software Design Robot Contest
 //
 
 #ifndef EV3CPPAPI_STEERING_H_
 #define EV3CPPAPI_STEERING_H_
 
 #include "Motor.h"
 
 namespace ev3api {
 class Steering
 {
 public:
     explicit Steering(Motor& leftMotor, Motor& rightMotor);
 
     void setPower(int power, int turnRatio);
 
 private:
     Motor& mLeftMotor;
     Motor& mRightMotor;
 }; // class Steering
 }  // namespace ev3api
 #endif // ! EV3CPPAPI_STEERING_H_