#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>
void get_accelerations(Adafruit_LIS3DH &accelerometer, float acc_array[]);
void get_accelerations_raw(Adafruit_LIS3DH &accelerometer, short acc_array[]);
void get_converted_raw_accelerations(Adafruit_LIS3DH &accelerometer, short raw_acc[], float acc_array[]);