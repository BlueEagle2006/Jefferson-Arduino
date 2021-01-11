#include <LiquidCrystal.h>


const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String alf1 = "PNAFLXZWDCMJEVIQBYGOHKRTSU";
String alf2 = "YCZWMQHRVAILBTFXSGJDUOKENP";
String alf3 = "DOUQYWZCGJSAMXHFNTKBVERLPI";
String alf4 = "PKYMDOQBXULTRVEHCWSNFJIAZG";
String alf5 = "UDPZGMQVHYFWKCRLJASNXIBETO";
String alfabeler[5]={alf1,alf2,alf3,alf4,alf5};
String secalf="SC";
String girdi="";
String girdi2="";
String girdi3="";
int gir;
String alf  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int getco(){
  if ((analogRead(A0))==(0)){
    return 4;
  }
  else if ((analogRead(A0))>(200) && (analogRead(A0))<(300)){
    return 3;
  }
  else if ((analogRead(A0))>(50) && (analogRead(A0))<(100)){
    return 2;
  }
  else if ((analogRead(A0))>(400) && (analogRead(A0))<(500)){
    return 1;
  }
  else if ((analogRead(A0))>(600) && (analogRead(A0))<(700)){
    return 0;
  }
  else{
    return 5;
  }
}
void cls(){
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 0);
  lcd.print("                ");
}
void sprint(String girdi){
  lcd.print(" "+girdi.substring(0,16));
  delay(1000);
  for(int i=0;i<girdi.length()-15;i++){
    lcd.setCursor(0, 1);
    lcd.print(girdi.substring(i,i+16));
    delay(500);
  }
}
String klavye(String baslik,String tip=""){
  String gecerli="";
  if (tip=="secenek"){
    gecerli=secalf;
  }
  else{
    gecerli=alf;
  }
  girdi="";
  gir=0;
  while(!(getco()==0)){
    cls();
    lcd.setCursor(0, 0);
    lcd.print(baslik);
    lcd.setCursor(0, 1);
    if (girdi.length()>14){
      lcd.print(girdi.substring(girdi.length()-14,girdi.length())+"_"+gecerli[gir]);
    }
    else{
      lcd.print(girdi+"_"+gecerli[gir]);
    }
    if (getco()==2 && gir>0){
      gir-=1;
    }
    if (getco()==3 && gir<gecerli.length()-1){
      gir+=1;
    }
    if (getco()==4){
      girdi+=gecerli[gir];
    }
    if (getco()==1){
      girdi=girdi.substring(0,girdi.length()-1);
    }
    delay(200);
    };
  return girdi;
}
void Sifrele(String metin){
  String cikti="";
  int rakam=0;
  for(int i=0;i<metin.length();i++){
    rakam=alfabeler[i%5].indexOf(metin[i])+1;
    if (rakam>25){
      rakam=0;
    }
    cikti+=alfabeler[i%5][rakam];
  }
  cls();
  lcd.setCursor(0, 1);
  if (cikti.length()>16){
    for(int i=0;i<5;i++){
      sprint(cikti);
    }
  }
  else if(cikti.length()>0){
    lcd.print(cikti);
    delay(10000);
  }
}
void Coz(String metin){
  String cikti="";
  int rakam=0;
  for(int i=0;i<girdi.length();i++){
    rakam=alfabeler[i%5].indexOf(metin[i])-1;
    if (rakam<0){
      rakam=25;
    }
    cikti+=alfabeler[i%5][rakam];
  }
  cls();
  lcd.setCursor(0, 1);
  if (cikti.length()>16){
    for(int i=0;i<5;i++){
      sprint(cikti);
    }
  }
  else if(cikti.length()>0){
    lcd.print(cikti);
    delay(10000);
  }
}void setup() {
  lcd.begin(16, 2);
  while(girdi!="ENIGMA"){
    girdi=klavye("SIFRE:");
    if (girdi!="ENIGMA"){
      cls();
      lcd.setCursor(4, 0);
      lcd.print("Sifre");
      lcd.setCursor(3, 1);
      lcd.print("Yanlis");
      delay(1000);
    }
  }
  cls();
  lcd.setCursor(4, 0);
  lcd.print("Sifre");
  lcd.setCursor(4, 1);
  lcd.print("Dogru");
  delay(1000);
  while(1){
    String girdi2=klavye("(S/C):","secenek");
    cls();
    delay(500);
    if (girdi2=="S"){
      String girdi3=klavye("Sifrele:");
      Sifrele(girdi3);
    }
    if(girdi2=="C"){
      String girdi3=klavye("Coz:");
      Coz(girdi3);
    }
  }
};
void loop(){
}
