#include "sensors.h"
#include "stats.h"
#include "angle_math.h"
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>
#include <LiquidCrystal_I2C.h>
#define LIS3DH_CLK 13
#define LIS3DH_MISO 12
#define LIS3DH_MOSI 11
#define LIS3DH_CS 10
Adafruit_LIS3DH lis3dh = Adafruit_LIS3DH(LIS3DH_CS, LIS3DH_MOSI, LIS3DH_MISO, LIS3DH_CLK);
float acc_vals[3]{};
unsigned long prevTimeMillis;
unsigned long currTimeMillis;
float variance{0};
float std_dev{0};
float curr_average{0};
float num_vals{0};
float prev_average{0};
int flex_sensor = A0;
int value = 0;
int flex{950};
int rating{1};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  if (! lis3dh.begin(0x18)) {
    while (1) {
      yield();      //Function provided from Adafruit, can be found at https://github.com/adafruit/Adafruit_LIS3DH
    }
  }
  prevTimeMillis = millis();
  currTimeMillis = millis();
  pinMode(D5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  get_accelerations(lis3dh, acc_vals);
  currTimeMillis = millis();
  float curr_angle{get_angle(acc_vals[2])}; //retrieve z acc

  if(currTimeMillis - prevTimeMillis >= UPDATE_RATE){
    prev_average = curr_average;
    update_average(curr_average, num_vals, curr_angle);
    update_variance(variance, num_vals, prev_average, curr_average, curr_angle);
    num_vals++;
    std_dev = calculate_std_dev(variance);
  }

if (to_degrees(curr_angle) >= ANGLE_THRESHOLD || value >= flex) {
  digitalWrite(D5, HIGH);
} else {
  digitalWrite(D5, LOW);
}
  Serial.print("Angle: ");
  Serial.println(to_degrees(curr_angle));

  value = analogRead(flex_sensor);
  Serial.println(value);
  if (value >= flex) {
    //digitalWrite(D5, HIGH);
    rating = 3;
  } else if (value >= flex - 75) {
    //digitalWrite(D5, LOW);
    rating = 2;
  } else {
    //digitalWrite(D5, LOW);
    rating = 1;
  }
  Serial.print(rating);
  delay(200);

}
