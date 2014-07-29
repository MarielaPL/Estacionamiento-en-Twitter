#include <Servo.h>

//variables para contador
int pines [] = {2,3,4,5,6,7,8}; //pines para display
byte num[] = {0B00111111,0B00000110,0B01011011,0B01001111,0B01100110,0B01101101,0B1111101,0B00000111,0B01111111,0B01101111};
int cont = 9;

//variables para botones
const int botonEntrada = 10;
const int botonSalida = 11;
int entrada = 0;
int salida = 0;

//variables de servomotor
int servoPin = 9;
Servo myservo; 

void setup(){
  myservo.attach(servoPin);
  pinMode(botonEntrada,INPUT);
  pinMode(botonSalida,INPUT);
  for(int i = 0; i < 7; i++){
    pinMode(pines[i],OUTPUT);
  }
  Serial.begin(9600);
  Serial.println(cont);
  //contador inicia con 9
  for(int j = 0; j < 7; j++){
    digitalWrite(pines[j],bitRead(num[cont],j));
  }
  
}

void loop(){
  entrada = digitalRead(botonEntrada);
  salida = digitalRead(botonSalida);
  if(entrada == HIGH){
      if(cont == 0){
      }
      else{
         abrir();
         delay(1000);
         cerrar();
         cont--;
           Serial.println(cont);
         actualizarCont(cont);
      }  
  }
  else if(salida == HIGH){
     if(cont == 9){
     }
     else{
        abrir();
        delay(1000);
        cerrar();
        cont++;
          Serial.println(cont);
        actualizarCont(cont);
     }
   }
}


void abrir(){
   for(int p = 90; p >= 1; p -= 1){                                  
    myservo.write(p);              
    delay(15);                      
  } 
}

void cerrar(){
  for(int p = 0; p < 90; p+=1){
    myservo.write(p);
    delay(15);
  }
}

void actualizarCont(int c){
  for(int j = 0; j < 7; j++){
     digitalWrite(pines[j],bitRead(num[c],j));
  }
}
