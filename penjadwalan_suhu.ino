BLYNK_WRITE(V15){
  if (param.asInt()){
  state=!state;
  }
  }
  BLYNK_WRITE(V16){
  switch (param.asInt()){
  case 1:{
    mod = 1;
    break;
  }
  case 2:{
    mod = 2;
    break;
  }
    case 3:{
    mod = 3;
    break;
  }
  }
  }
void penjadwalan_suhu(){
DS18B20.requestTemperatures();
suhu = DS18B20.getTempCByIndex(0);
kelembaban = DS18B20.toFahrenheit(suhu);
Blynk.virtualWrite(V3, suhu);
 Serial.println(suhu, 2);
Blynk.virtualWrite(V4, kelembaban);
 Serial.println(kelembaban, 3);
switch (mod){
  case 1:{
     if(state && suhu < 37.00){                   //Jika suhu < 37.00*C lampu ON
     waktu_1.on();
     indikasi_lampu.on();
     digitalWrite(lampu, LOW);
     digitalWrite(kipas, HIGH);
    }
     else if(state && suhu > 38.00){              //Jika suhu > 38.50*C lampu OFF
     indikasi_lampu.off();      
     waktu_1.off();
     digitalWrite(kipas, LOW);
     digitalWrite(lampu, HIGH);
  }
  break;
  }
   case 2:{
     if(state && suhu < 37.50){                   //Jika suhu < 37.50*C lampu ON
      waktu_2.on(); 
      indikasi_lampu.on();
      digitalWrite(lampu, LOW);
      digitalWrite(kipas, HIGH);    
    }
    else if(state && suhu > 38.50){              //Jika suhu < 38.50*C lampu OFF
      indikasi_lampu.off();
      waktu_2.off();
      digitalWrite(lampu, HIGH);
      digitalWrite(kipas, LOW);
  }
  break;
   } 
     case 3:{
      if(state && suhu < 38.00){                   //Jika suhu < 38.00*C lampu ON
      waktu_3.on();
      indikasi_lampu.on();
      digitalWrite(lampu, LOW);
      digitalWrite(kipas, HIGH);   
    }
    else if(state && suhu > 39.00){              //Jika suhu < 39.00*C lampu OFF
      waktu_3.off();
      indikasi_lampu.off();
      digitalWrite(lampu, HIGH);
      digitalWrite(kipas, LOW);
  }
  break;   
    }
      }
        }
