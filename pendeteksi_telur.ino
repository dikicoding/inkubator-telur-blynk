void pendeteksi_telur()
{                        
int ldrValue;
ldrValue = analogRead(ldrPin);
//lcd Untuk Blynk
  Serial.print(ldrValue);
  lcd.print(1,0,"Telur :");   
  Blynk.virtualWrite(V0, ldrValue);
  
  if (ldrValue<200){
  Serial.println("MASUKAN TELUR");//ke serial monitor
  lcd.print(1,1,"MASUKAN TELUR");           
  }  
  else if (ldrValue>500){
  Serial.println("NON INFERTIL");
  lcd.print(1,1,"NON INFERTIL");              
  }
  
  else if (ldrValue<400){
  Serial.println("INFERTIL");
  lcd.print(1,1,"INFERTIL");
  }
}
