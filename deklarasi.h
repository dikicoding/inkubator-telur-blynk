//------------- Waktu Perputaran -------------

int Hour_1, Min_1, Sec_1;
int Hour_2, Min_2, Sec_2;
int Hour_3, Min_3, Sec_3;
boolean putar_1, putar_2, putar_3, state;
byte mod;

// RTC
#include "RTClib.h"
RTC_DS3231 rtc;
char currentTime[9];
int waktu_motor_putar = 30000;                        // Durasi perputaran telur selama 30 detik
#define pin_motor_putar D7                              //PIN motor putar telur

// ------------ Pendeteksi Telur --------------
#define lampu_pendeteksi D5 //Lampu pendeteksi
#define IR D3
bool ir;
#define ldrPin A0 //Pin Sensor LDR
int ldrValue;

//----------------- Sensor Suhu ------------------

#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#define ONE_WIRE_BUS D4 //PIN Sensor Suhu DS18B20
#define lampu D8 //PIN Lampu Inkubator
#define kipas D6 //PIN kipas Inkubator
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature DS18B20(&oneWire);
float suhu;
float kelembaban=0;
