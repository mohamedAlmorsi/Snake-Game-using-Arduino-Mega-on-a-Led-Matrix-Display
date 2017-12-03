
#include <LiquidCrystal.h>

LiquidCrystal lcd(33,11,30,31,29,28);
// led 8x8 matrix
const int rows []= {9,24,8,12,25,7,2,5};
const int columns []= {13,3,4,10,6,36,22,23};

// snake body
int snakeRow [] = {4,-1,-1,-1,-1,-1,-1,-1};
int snakeColumn [] = {4,-1,-1,-1,-1,-1,-1,-1};

// apple
int appleRow;
int appleColumn;

// game state 
int size ;
int counter ;
int direction; 
int score ;
bool pause ;
bool checkRight ;
bool checkLeft ;
bool lose ;

// hardware circuit sensors
const int buzzerPin =50; 
const int redPin = 51;
const int greenPin=52;
const int bluePin =53;
const int startSensorPin=41;
const int resetSensorPin=39;
const int moveRightSensorPin=47;
const int moveLeftSensorPin=46;

void setup() {

  //lcd ini
    lcd.begin(16,2);
    lcd.clear();
    lcd.print("score : 0");
  // initializing matrix pins
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(36,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(22,OUTPUT);
  pinMode(23,OUTPUT);
  pinMode(24,OUTPUT);
  pinMode(25,OUTPUT);

  // game state initialization 
  do {
   appleRow = rand()%6 +1;
   appleColumn = rand()%6 +1 ;}while(appleRow ==4 && appleColumn ==4);
   score =0 ;
   pause = false ;
   direction =0 ;
   size =1 ;
   counter =0 ;
   
  checkRight = true ;
  checkLeft = true ;
  lose = false ;
   // sensors initialization

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
  
  if(digitalRead(resetSensorPin)==HIGH) { lose = false ;reset(); }
  if(digitalRead(startSensorPin)==HIGH) pause = !pause ;

   if(checkRight == true ){
   if(digitalRead(moveRightSensorPin)== LOW){

    checkRight = false ;
    shiftRight();
   }
   }
   if(checkLeft==true){
    if(digitalRead(moveLeftSensorPin)==LOW) {
    checkLeft= false ;
    shiftLeft();
   } 
   }
 
   if(digitalRead(moveLeftSensorPin)==HIGH)
    {
      checkLeft = true ;
    }
   if(digitalRead(moveRightSensorPin)== HIGH)
   {
    checkRight = true ;
   }
  if(lose == false){
  if(pause ==true)
   {
    whiteRgb();
   }
   else {
    blueRgb();
   }
  }
  if(lose)
  {
    redRgb();
  }
   counter=(counter+1)%91;
 
 if( counter%90==0&&counter !=0  &&  pause && lose == false )
 {
  //buzzer();
  for(int i=size-1 ; i>0 ; i--)
  {
      snakeRow[i] = snakeRow[i-1];
      snakeColumn[i]= snakeColumn[i-1];
  }
  
 // counter =0 ;
  if(direction ==0 )
  {
    snakeRow[0]++ ;
  }
  else if(direction ==1)
  {
    snakeRow[0]-- ;
  }
   else if(direction ==2)
   {
    snakeColumn[0]++;
   }
   else if(direction ==3)
   {
    snakeColumn[0]-- ;
   }

   if(snakeRow[0]==7)snakeRow[0]=1 ;
   if(snakeRow[0]==0)snakeRow[0]=6;
   if(snakeColumn[0]==7)snakeColumn[0]=1;
   if(snakeColumn[0]==0)snakeColumn[0]=6;

   if(snakeColumn[0] == appleColumn && snakeRow[0] == appleRow)
   {
     appleRow = rand()%6 +1;
     appleColumn = rand()%6 +1 ;
     if(size <8)
     {
      greenRgb();
      delay(100);
      buzzer();
       size++ ;
     }
     score++;
      lcd.clear();
      //lcd.print("score :%d",score);
       lcd.print("score: ");
      lcd.print(score);
      //delay(100);
      
   }
 }
      if(lose == false){
     for(int i=1 ; i<size; i++)
    {
      if(snakeRow[i]==snakeRow[0] && snakeColumn[i] ==snakeColumn[0])
      {
        //reset();
        buzzerLose();
        redRgb();
        lose = true ;
       lcd.clear();
       lcd.print("You Lose.   M&Ms");
       //delay(100);
        
      }
    }
      }

  if(lose == false) {
    setLed(appleRow,appleColumn);
  for(int i=0 ;i<size;i++)
  {

      setLed(snakeRow[i],snakeColumn[i]);
  }
 setWall();
  }
  lcd.display();
// delayMicroseconds(100);
}
void setLed(int row , int col )
{
  for(int i=0 ; i<8;i++)
  {
    if(i==row)
    {
      digitalWrite(rows[i],HIGH);
    }
    else {
      digitalWrite(rows[i],LOW);
    }
    
    if(i==col)
    {
      digitalWrite(columns[i],LOW);
    }
    else {
      digitalWrite(columns[i],HIGH);
    }
  }

 
 delayMicroseconds(10);
 for(int i=0 ; i<8;i++)
 {
  digitalWrite(rows[i],LOW);
  digitalWrite(columns[i],HIGH);
 }

}
void setWall()
{
  for(int i=0 ; i<8;i++)
  {
    setLed(0,i);
    setLed(7,i);
    setLed(i,0);
    setLed(i,7);
  }
}
void reset()
{
  lcd.clear();
  lcd.print("Score : 0");
  //delay(100);
  buzzer();
  size =1 ;
   for(int i= 1 ;i<8 ;i++)
   {
    snakeColumn[i]=-1;
    snakeRow[i]=-1 ;
   }
   
  pause = false ;
  score =0 ;
   appleRow = rand()%6 +1;
   appleColumn = rand()%6 +1 ;
  direction =0 ;
  counter =0;
}
void shiftLeft()
{
  if(direction==0)direction = 2;
  else if(direction==1)direction= 3;
  else if(direction==2)direction= 1;
  else if(direction==3)direction= 0;
 // buzzer();
 }
 void shiftRight(){
  if(direction==0)direction = 3;
 else if(direction==1)direction= 2;
  else if(direction==2)direction= 0;
  else if(direction==3)direction= 1;
  
 }
void whiteRgb(){
  digitalWrite(51,HIGH);
  digitalWrite(52,HIGH);
  digitalWrite(53,HIGH);
}
void blueRgb(){
  digitalWrite(51,LOW);
  digitalWrite(52,LOW);
  digitalWrite(53,HIGH);
}
void redRgb(){
  digitalWrite(51,HIGH);
  digitalWrite(52,LOW);
  digitalWrite(53,LOW);
}
void greenRgb(){
  digitalWrite(51,LOW);
  digitalWrite(52,HIGH);
  digitalWrite(53,LOW);
}
void buzzer(){
  digitalWrite(buzzerPin,HIGH);
  delay(100);
  digitalWrite(buzzerPin,LOW);
}
void buzzerLose(){
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