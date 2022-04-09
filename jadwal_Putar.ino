//------------  PUSH DATA  -------------

//Input Time Perputaran ke-1
BLYNK_WRITE(V5) {
  TimeInputParam t(param);
  Hour_1  = t.getStartHour();
  Min_1   = t.getStartMinute();
  Sec_1   = t.getStartSecond();
}

//Input Time Perputaran ke-2
BLYNK_WRITE(V6) {
  TimeInputParam t(param);
  Hour_2  = t.getStartHour();
  Min_2   = t.getStartMinute();
  Sec_2   = t.getStartSecond();
}

//Input Time Perputaran ke-3
BLYNK_WRITE(V7) {
  TimeInputParam t(param);
  Hour_3  = t.getStartHour();
  Min_3   = t.getStartMinute();
  Sec_3   = t.getStartSecond();
}
//Input Time Perputaran ke-4
BLYNK_WRITE(V8) {
  TimeInputParam t(param);
  Hour_4  = t.getStartHour();
  Min_4   = t.getStartMinute();
  Sec_4   = t.getStartSecond();
}
//------------- WAKTU Perputaran -------------

void jadwal_Putar() {
  DateTime now = rtc.now();
  sprintf(currentTime, "%02d:%02d:%02d", now.hour(), now.minute(), now.second());
  Blynk.virtualWrite(V9, currentTime);
//    Serial.print(now.hour(), DEC);
//    Serial.print(':');
//    Serial.print(now.minute(), DEC);
//    Serial.print(':');
//    Serial.print(now.second(), DEC);
//    Serial.println();
  sama_1 = (now.hour() == Hour_1  && now.minute() == Min_1   && now.second() == Sec_1);
  sama_2 = (now.hour() == Hour_2  && now.minute() == Min_2   && now.second() == Sec_2);
  sama_3 = (now.hour() == Hour_3  && now.minute() == Min_3   && now.second() == Sec_3);
  sama_4 = (now.hour() == Hour_4  && now.minute() == Min_4   && now.second() == Sec_4);

  if ( sama_1 || sama_2 || sama_3 || sama_4) {
    digitalWrite(pin_motor_putar, LOW);             //Relay aktif untuk menyalakan motor Putar
    indikasi_motor.on();
    Blynk.notify("Motor Nyala");
    timer.setTimeout(waktu_motor_putar, []() {
      digitalWrite(pin_motor_putar, HIGH);         //Relay mati untuk mematikan motor putar
      indikasi_motor.off();
       Blynk.notify("Motor Hidup");
    });
  }
}
