
const int buzzerPin =13; 
const int redPin = 12;
const int greenPin=11;
const int bluePin=10;
const int startLedPin=0;
const int startSensorPin=1;
const int resetLedPin=2;
const int resetSensorPin=3;
int reset =0;
int start=0;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(buzzerPin,OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(startLedPin,OUTPUT);
  pinMode(startSensorPin,INPUT);

}

void loop() {
  
  /*
  // testing buzzer 
  buzzerGetPoint();
  delay(1000);
  buzzerLoose();*/
/*
  // testing RGB   
  while(1){
  lightRgb(redPin);
  delay(200);
  lightRgb(greenPin);
  delay(200);
  lightRgb(bluePin);
  delay(200);
  }*/


  while(1){
    if(digitalRead(startSensorPin)) touchSensor(startSensorPin);
    if(digitalRead(resetSensorPin)) touchSensor(resetSensorPin);   
  }
  
}

void buzzerGetPoint(){
  digitalWrite(buzzerPin,HIGH);
  delay(200);
  digitalWrite(buzzerPin,LOW);
  delay(100);
  digitalWrite(buzzerPin,HIGH);
  delay(200);
  digitalWrite(buzzerPin,LOW);
  
}

void buzzerLoose(){
  digitalWrite(buzzerPin,HIGH);
  delay(500);
  digitalWrite(buzzerPin,LOW);
  delay(300);
  digitalWrite(buzzerPin,HIGH);
  delay(500);
  digitalWrite(buzzerPin,LOW);
  delay(300);
  digitalWrite(buzzerPin,HIGH);
  delay(500);
  digitalWrite(buzzerPin,LOW);
}


void lightRgb(int pin){
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  digitalWrite(pin,HIGH);
}

void touchSensor(int pin){
  if(pin == 1){
    start=1;
    digitalWrite(0,HIGH);
  }
  else if(pin == 3){
    reset=1;
    digitalWrite(2,HIGH);
  }
  
}



