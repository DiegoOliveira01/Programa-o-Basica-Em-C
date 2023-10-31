

// Link para acesso ao projeto no tinkercadr:
// https://www.tinkercad.com/things/kj97lbE8ebq


byte estadoBtn = 0; 
const byte btPin = 12;

const byte face [6] = {     
B00001100,  // = Digito 1   
B10110110,  // = Digito 2   
B10011110,  // = Digito 3   
B11001100,  // = Digito 4   
B11011010,  // = Digito 5   
B11111010  // = Digito 6  
};

void setup() {
  pinMode(btPin , INPUT_PULLUP);     
  DDRD = B11111110;    
  PORTD = 0;  
  randomSeed(analogRead(0)); 
}

void loop() { 
estadoBtn = digitalRead(btPin);
  if(!estadoBtn){    
    rodadada(); 
    delay(150);
}

}
void rodadada(){
  byte result = 0; 
  byte rodada = random(15, 35); 
  for (byte i = 0; i < rodada; i++)
    {
      result = random(0, 6);                             
      show(result); 
      delay(50 + i * 10); 
    }
}


void show(int result) {
  PORTD = face[result];   
}

