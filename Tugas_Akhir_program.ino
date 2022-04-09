#include "deklarasi.h"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

BlynkTimer timer;
WidgetLCD lcd(V0);
WidgetLED indikasi_lampu(V1);
WidgetLED indikasi_motor(V2);

char auth[] = "9kd5_os-WUnT4ZzAaNidvvkD3soLIBHt";   // Tokennya di email sesuai akun Blynk
char ssid[] = "CALISTA";  // SSID internet
char pass[] = "Mantaptenan"; // pass Wifi 

BLYNK_CONNECTED() {
  Blynk.syncAll();
}

void setup(){
Serial.begin(115200);
Blynk.begin(auth, ssid, pass, "iot.serangkota.go.id", 8080);

//------------- Waktu Perputaran ------------
timer.setInterval(800L, jadwal_Putar);
pinMode(pin_motor_putar, OUTPUT);
digitalWrite(pin_motor_putar, HIGH);
rtc.begin();
indikasi_motor.off();
Wire.begin(5, 4);   //Setting wire (5 untuk SDA dan 4 untuk SCL)
//rtc.adjust(DateTime(2021, 10, 20, 16, 15, 00));
//rtc.adjust(DateTime(__DATE__, __TIME__));


//------------- Suhu Inkubator --------------
timer.setInterval(1000L, Sensor_Suhu); 
pinMode(lampu, OUTPUT);
digitalWrite(lampu, HIGH);
digitalWrite(lampu, LOW);

//------------- Pendeteksi Telur -------------
timer.setInterval(1000L, pendeteksi_telur);  
}

void loop(){
  timer.run();
  Blynk.run();
  float suhu = DS18B20.getTempCByIndex(0);
  float kelembaban = DS18B20.toFahrenheit(suhu); 
  if(suhu < 37.50){                   //Jika suhu < 37.00*C lampu ON
    indikasi_lampu.on();
    digitalWrite(lampu, LOW);
    }
  else if(suhu > 38.70){              //Jika suhu < 38.50*C lampu OFF
    indikasi_lampu.off();
    digitalWrite(lampu, HIGH);
   }
}
