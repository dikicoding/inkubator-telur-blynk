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

//------------- WAKTU Perputaran -------------
void jadwal_Putar() {
  DateTime now = rtc.now();
  sprintf(currentTime, "%02d:%02d:%02d", now.hour(), now.minute(), now.second());
  Blynk.virtualWrite(V9, currentTime);
  
  putar_1 = (now.hour() == Hour_1 && now.minute() == Min_1 && now.second() == Sec_1);
  putar_2 = (now.hour() == Hour_2 && now.minute() == Min_2 && now.second() == Sec_2);
  putar_3 = (now.hour() == Hour_3 && now.minute() == Min_3 && now.second() == Sec_3);

  if ( putar_1 || putar_2 || putar_3) {
    digitalWrite(pin_motor_putar, LOW);           //Relay aktif untuk menyalakan motor Putar
    Blynk.notify("Motor Putar Menyala");

    timer.setTimeout(waktu_motor_putar, []() {
    digitalWrite(pin_motor_putar, HIGH);         //Relay mati untuk mematikan motor putar
    Blynk.notify("Motor Putar Mati");
    });
  }
}
