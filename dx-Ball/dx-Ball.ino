
const int buzzerPin =9; 
const int redPin = 7;
const int greenPin=6;
const int bluePin =5;
const int startSensorPin=10;
const int resetSensorPin=8;
const int moveRightSensorPin=11;
const int moveLeftSensorPin=12;
int reset =0;
int start=0;
int rightMoves=0;
int leftMoves=0;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(buzzerPin,OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(startSensorPin,INPUT);
  pinMode(resetSensorPin,INPUT);
  pinMode(moveRightSensorPin,INPUT);
  pinMode(moveLeftSensorPin,INPUT);

}

void loop() {
  
  
  // testing buzzer 
  /*buzzerGetPoint();
  delay(1000);
  buzzerLoose();*/

 /* // testing RGB   
  while(1){
  lightRgb(redPin);
  delay(1000);
  lightRgb(greenPin);
  delay(1000);
  lightRgb(bluePin);
  delay(1000);
  }*/


  while(1){
   if(digitalRead(resetSensorPin)==HIGH) touchSensor(resetSensorPin);
   if(digitalRead(startSensorPin)==HIGH) touchSensor(startSensorPin);
   if(digitalRead(moveRightSensorPin)== LOW) moveRight();
   if(digitalRead(moveLeftSensorPin)==LOW)   moveLeft();
   lightRgb(greenPin);
   
   
}
}

void buzzerMove(){
  digitalWrite(buzzerPin,HIGH);
  delay(100);
  digitalWrite(buzzerPin,LOW);
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
  digitalWrite(7,LOW);
  digitalWrite(6,LOW);
  digitalWrite(5,LOW);
  digitalWrite(pin,HIGH);
}

void touchSensor(int pin){
  if(pin == 10){
    start=1;
  }
  else if(pin == 8){
    reset=1;
  }
  buzzerMove();
}

void moveRight(){
    rightMoves++;
    buzzerMove();
}

void moveLeft(){
  leftMoves++;
  buzzerMove();
}



