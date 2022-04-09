
void Sensor_Suhu(){
DS18B20.requestTemperatures();
suhu = DS18B20.getTempCByIndex(0);
kelembaban = DS18B20.toFahrenheit(suhu);
Blynk.virtualWrite(V3, suhu);
Blynk.virtualWrite(V4, kelembaban);
}
