//Electronic Dice Code
// Michael Sohanlall && Vincent Viray

#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x3F // <<----- Add your address here.  Find it from I2C Scanner
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

int n = 1;

LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

//Define variables 

const int ONE = 13; 
const int TWO = 12;
const int THREE = 11;
const int FOUR = 10;
const int FIVE = 9;
const int SIX = 8;
const int SEVEN = 7;
const int BUTTON = 4;
const int INDI = 2;//indicator light
/* this sets all of the terms to number values */

int val = 0; //integer value set to 0

int state = 0; //state set to 0, aka off

long randNumber; //this is needed for the random number gen

void setup(){
  pinMode(ONE, OUTPUT);
  pinMode(TWO, OUTPUT);
  pinMode(THREE, OUTPUT);
  pinMode(FOUR, OUTPUT);
  pinMode(FIVE, OUTPUT);
  pinMode(SIX, OUTPUT);
  pinMode(SEVEN, OUTPUT);
  pinMode(BUTTON, INPUT);
  pinMode(INDI, OUTPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0));
  lcd.begin(16,2);   // initialize the lcd for 16 chars 2 lines, turn on backlight
}
/* this sets all of the pins to input
or output, and keeps them that way */

 void loop(){
   val = digitalRead(BUTTON); //value set to button state
   
   if (val == HIGH){
     digitalWrite(INDI, HIGH); //red light on
     delay(100);               //0.1 sec delay
     randNumber = random(1, 7);//creates a random number 
     delay(100);               //0.1 sec delay
     Serial.println(randNumber);//prints the number to serial monitor
     delay(100);               //0.1 sec delay
     digitalWrite(INDI, LOW);  //red light off
     
     
     if (randNumber == 6){ //if it lands on 6
       digitalWrite(ONE, HIGH);
       digitalWrite(TWO, HIGH);
       digitalWrite(THREE, HIGH);
       digitalWrite(FIVE, HIGH);
       digitalWrite(SIX, HIGH);
       digitalWrite(SEVEN, HIGH);
       delay(2000);
       digitalWrite(ONE, LOW);
       digitalWrite(TWO, LOW);
       digitalWrite(THREE, LOW);
       digitalWrite(FIVE, LOW);
       digitalWrite(SIX, LOW);
       digitalWrite(SEVEN, LOW);
       
      lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // go home
      lcd.print("You rolled a 6!!");
     }
     if (randNumber == 5){ //lands on 5
       digitalWrite(ONE, HIGH);
       digitalWrite(THREE, HIGH);
       digitalWrite(FOUR, HIGH);
       digitalWrite(FIVE, HIGH);
       digitalWrite(SEVEN, HIGH);
       delay(2000);
       digitalWrite(ONE, LOW);
       digitalWrite(THREE, LOW);
       digitalWrite(FOUR, LOW);
       digitalWrite(FIVE, LOW);
       digitalWrite(SEVEN, LOW);

      lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // go home
      lcd.print("You rolled a 5!!");
     }
     if (randNumber == 4){ //lands on 4
       digitalWrite(ONE, HIGH);
       digitalWrite(THREE, HIGH);
       digitalWrite(FIVE, HIGH);
       digitalWrite(SEVEN, HIGH);
       delay(2000);
       digitalWrite(ONE, LOW);
       digitalWrite(THREE, LOW);
       digitalWrite(FIVE, LOW);
       digitalWrite(SEVEN, LOW);

      lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // go home
      lcd.print("You rolled a 4!!");

     }
     if (randNumber == 3){ //lands on 3
       digitalWrite(ONE, HIGH);
       digitalWrite(FOUR, HIGH);
       digitalWrite(SEVEN, HIGH);
       delay(2000);
       digitalWrite(ONE, LOW);
       digitalWrite(FOUR, LOW);
       digitalWrite(SEVEN, LOW);

      lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // go home
      lcd.print("You rolled a 3!!");
      
     }
     if (randNumber == 2){ //lands on 2
       digitalWrite(ONE, HIGH);
       digitalWrite(SEVEN, HIGH);
       delay(2000);
       digitalWrite(ONE, LOW);
       digitalWrite(SEVEN, LOW);

      lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // go home
      lcd.print("You rolled a 2!!");
     }
     if (randNumber == 1){//lands on 1
       digitalWrite(FOUR, HIGH);
       delay(2000);
       digitalWrite(FOUR, LOW);

      lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // go home
      lcd.print("You rolled a 1!!");
     }
   } //closes all loops
 }
       
 
       
     

