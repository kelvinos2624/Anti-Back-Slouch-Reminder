#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>
#include "sensors.h"
#include "angle_math.h"

// CREDITS: adapted from https://learn.adafruit.com/adafruit-lis3dh-triple-axis-accelerometer-breakout/arduino
// Also credits to https://github.com/adafruit/Adafruit_LIS3DH 

/*
 * Gets the x, y, z accelerations readings from the accelerometer converted to m/s^2 by Adafruit_Sensor as single-precision floating point numbers
 * @params accelerometer the Adafruit_LIS3DH object representing the accelerometer, passed by reference
 * @params acc_array the float array that holds the accelerations to fill up (size 3) (x,y,z format)
*/
void get_accelerations(Adafruit_LIS3DH &accelerometer, float acc_array[]){
  sensors_event_t acc_event;
  accelerometer.getEvent(&acc_event);
  acc_array[0] = acc_event.acceleration.x;
  acc_array[1] = acc_event.acceleration.y;
  acc_array[2] = acc_event.acceleration.z;
}
/*
 * Gets the x, y, z accelerations readings from the accelerometer in the raw 16 bit integer format
 * @params accelerometer, the Adafruit_LIS3DH object representing the accelerometer, passed by reference
 * @params acc_array the short array that holds the accelerations to fill up (size 3) (x,y,z) format
*/
void get_accelerations_raw(Adafruit_LIS3DH &accelerometer, short acc_array[]){
  accelerometer.read();
  acc_array[0] = accelerometer.x;
  acc_array[1] = accelerometer.y;
  acc_array[2] = accelerometer.z;
}
/*
 * Gets the converted x, y, z accelerations raw readings from the accelerometer in m/s^2 (as a single precision floating point number)
 * @params accelerometer, the Adafruit_LIS3DH object representing the accelerometer, passed by reference
 * @params raw_acc the short array that holds the raw accelerations
 * @params acc_array the float array that holds the accelerations to fill up with the converted values
*/
void get_converted_raw_accelerations(Adafruit_LIS3DH &accelerometer, short raw_acc[], float acc_array[]){
  float conversion_factor = (accelerometer.getRange() * GRAVITY_ACC) / ((double) (2 << accelerometer.getRange()));
  acc_array[0] = raw_acc[0]*conversion_factor;
  acc_array[1] = raw_acc[1]*conversion_factor;
  acc_array[2] = raw_acc[2]*conversion_factor;
}