void pendeteksi_telur()
{                       
  //Sensor aktif LOW
  ir = digitalRead(IR);
  if(ir == 0){
    digitalWrite(lampu_pendeteksi, LOW); 
      indikasi_lampu_pendeteksi.on();
  }
  else if(ir == 1){
    digitalWrite(lampu_pendeteksi, HIGH);
    indikasi_lampu_pendeteksi.off();
       
  }  
} 
