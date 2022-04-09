void ldr_telur(){
  lcd.clear();
  lcd.print(0,0,"Telur :");   
  int ldrValue = analogRead(ldrPin); 
  if (ldrValue == 1024){
  lcd.print(0,1,"Masukan Telur");              
  }
  else if (ldrValue >188){
  lcd.print(0,1,"INFERTIL");              
  }
  else if (ldrValue <188){
  lcd.print(0,1,"FERTIL");
  }
}
