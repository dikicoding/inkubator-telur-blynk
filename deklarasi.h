//------------- Waktu Perputaran -------------

int Hour_1, Min_1, Sec_1;
int Hour_2, Min_2, Sec_2;
int Hour_3, Min_3, Sec_3;
int Hour_4, Min_4, Sec_4;
boolean sama_1, sama_2, sama_3, sama_4;

// RTC
#include "RTClib.h"
#include <Wire.h>
RTC_DS3231 rtc;
char currentTime[9];
int waktu_motor_putar = 30000;                        // WAKTU PERPUTARAN MOTOR
#define pin_motor_putar D6                              //PIN motor putar telur

// ------------ Pendeteksi Telur --------------
#define lampu_pendeteksi D6 //Lampu Pendeteksi
const int ldrPin = A0; //Pin Sensor LDR
int ldrValue;

//----------------- Sensor Suhu ------------------
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS D4 //PIN Sensor Suhu
#define lampu D7 //PIN Lampu
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature DS18B20(&oneWire);
float suhu;
float kelembaban=0;
