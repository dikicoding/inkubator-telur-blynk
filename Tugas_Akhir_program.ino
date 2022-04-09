#include "deklarasi.h"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

BlynkTimer timer;
WidgetLCD lcd(V0);
WidgetLED indikasi_lampu(V1);
WidgetLED indikasi_lampu_pendeteksi(V10);
WidgetLED waktu_1(V11);
WidgetLED waktu_2(V12);
WidgetLED waktu_3(V13);

char auth[] = "9kd5_os-WUnT4ZzAaNidvvkD3soLIBHt";   // Tokennya di email sesuai akun Blynk
char ssid[] = "tugas akhir";  // SSID internet
char pass[] = "1461700035"; // pass Wifi 

BLYNK_CONNECTED() {
  Blynk.syncAll();
}

void setup(){
Serial.begin(115200);
Blynk.begin(auth, ssid, pass, "iot.serangkota.go.id", 8080);
 
//-------Penjadwalan Suhu Inkubator --------------
timer.setInterval(800L, penjadwalan_suhu); 
float suhu = DS18B20.getTempCByIndex(0);
float kelembaban = DS18B20.toFahrenheit(suhu); 
pinMode(lampu, OUTPUT);
pinMode(kipas, OUTPUT);
digitalWrite(kipas, HIGH);
digitalWrite(kipas, LOW);
digitalWrite(lampu, HIGH);
digitalWrite(lampu, LOW);

//------------- Waktu Perputaran ------------
timer.setInterval(800L, jadwal_Putar);
pinMode(pin_motor_putar, OUTPUT);
digitalWrite(pin_motor_putar, HIGH);
rtc.begin();
//rtc.adjust(DateTime(2021, 12, 30, 23, 34, 00));
//rtc.adjust(DateTime(__DATE__, __TIME__));

//------------- Pendeteksi Telur -------------
timer.setInterval(800L, pendeteksi_telur); 
pinMode(lampu_pendeteksi, OUTPUT);
pinMode(IR, INPUT);
digitalWrite(lampu_pendeteksi, HIGH);
digitalWrite(lampu_pendeteksi, LOW);

timer.setInterval(1000L, ldr_telur); 
}

void loop(){
  timer.run();
  Blynk.run();
  delay(100);
}
