

// Link para acesso ao projeto no tinkercadr:
// https://www.tinkercad.com/things/ijrEKL98cJg


#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);


float convertido;


float distancia;
void ultrasonico(byte trig, byte echo) {
 
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
 
  digitalWrite (trig, LOW);
  delayMicroseconds (2);
  digitalWrite (trig, HIGH);
  delayMicroseconds (10);
  digitalWrite (trig, LOW);
  unsigned long duracao=pulseIn (echo, HIGH);
  distancia = duracao/58;
 
}


void setup() {

  lcd.begin(16,2);
  
  lcd.setCursor(0,0);
  lcd.print("Carregando...");
  delay(2000);
  lcd.setCursor(0,0);
  lcd.print("     CM      ");  

}

void loop() {

  ultrasonico(9,8);

 if(distancia < 340){
 lcd.setCursor(0,0); 
 lcd.print("TRENA DIGITAL");
 lcd.setCursor(0,1);
 lcd.print("dist:  ");
 lcd.print(distancia);
 lcd.print(" CM  "); 
  delay(200);
  }  
}

