#include <Servo.h>
#define trigPin 50
#define echoPin 48
#include <LiquidCrystal.h>


LiquidCrystal lcd(8, 9, 4, 5, 6, 7);           // select the pins used on the LCD panel

// define some values used by the panel and buttons
int lcd_key     = 0;
int adc_key_in  = 0;
int lm35Pin = 35;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

int read_LCD_buttons() {              // read the buttons
  adc_key_in = analogRead(0);       // read the value from the sensor

  // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
  // we add approx 50 to those values and check to see if we are close
  // We make this the 1st option for speed reasons since it will be the most likely result

  if (adc_key_in > 1000) return btnNONE;

  // For V1.1 us this threshold
  if (adc_key_in < 50)   return btnRIGHT;
  if (adc_key_in < 250)  return btnUP;
  if (adc_key_in < 450)  return btnDOWN;
  if (adc_key_in < 650)  return btnLEFT;
  if (adc_key_in < 850)  return btnSELECT;

  // For V1.0 comment the other threshold and use the one below:
  /*
    if (adc_key_in < 50)   return btnRIGHT;
    if (adc_key_in < 195)  return btnUP;
    if (adc_key_in < 380)  return btnDOWN;
    if (adc_key_in < 555)  return btnLEFT;
    if (adc_key_in < 790)  return btnSELECT;
  */

  return btnNONE;                // when all others fail, return this.
}
Servo myservo;
int pos = 0;
int k=32;
int s=30;
int y=28;
int brightness = 255;
int sensor=44;
int deger=0;
 
void setup() {
  lcd.begin(16, 2);
Serial.begin (9600);
myservo.attach(42);
myservo.write(pos);
pinMode(k,OUTPUT);
pinMode(s,OUTPUT);
pinMode(y,OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(sensor,INPUT);
pinMode(echoPin, INPUT);
}


void loop() {
long sure, mesafe;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
sure = pulseIn(echoPin, HIGH);
digitalWrite(s,LOW);
digitalWrite(y,LOW);
analogWrite(k,brightness);
Serial.println("k");
mesafe = (sure/2) / 29.1;
deger=digitalRead(sensor);
   if (mesafe <= 1){
  // Serial.print("g");
   digitalWrite(k,LOW);
   for (pos = 0; pos <= 90; pos += 1) { 
    Serial.print("ak");
     lcd.setCursor(0, 0); 
    lcd.print("HOSGELDiNiZ");
    digitalWrite(s,HIGH);
    myservo.write(pos);              
    delay(50); 
    }
    Serial.print("a");
    digitalWrite(s,LOW);
    digitalWrite(y,HIGH);
    delay(1500);
    for (pos = 90; pos >= 0; pos -= 1) { 
     Serial.print("ka");
     digitalWrite(s,HIGH);
     digitalWrite(y,LOW);
    myservo.write(pos);              
    delay(50);
    }
    }
  if(deger==LOW){
      digitalWrite(k,LOW);
   for (pos = 0; pos <= 90; pos += 1) { 
    lcd.setCursor(0,0);
    lcd.print("GULE GULE  ");
    
    Serial.print("ak");
    digitalWrite(s,HIGH);
    myservo.write(pos);              
    delay(50); 
    }
    Serial.print("b");
    digitalWrite(s,LOW);
    digitalWrite(y,HIGH);
    delay(1500);
    for (pos = 90; pos >= 0; pos -= 1) { 
     Serial.print("ka");
     digitalWrite(s,HIGH);
     digitalWrite(y,LOW);
    myservo.write(pos);              
    delay(50);
    }
      }
    
}#include <Servo.h>
#define trigPin 50
#define echoPin 48
#include <LiquidCrystal.h>


LiquidCrystal lcd(8, 9, 4, 5, 6, 7);           // select the pins used on the LCD panel

// define some values used by the panel and buttons
int lcd_key     = 0;
int adc_key_in  = 0;
int lm35Pin = 35;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

int read_LCD_buttons() {              // read the buttons
  adc_key_in = analogRead(0);       // read the value from the sensor

  // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
  // we add approx 50 to those values and check to see if we are close
  // We make this the 1st option for speed reasons since it will be the most likely result

  if (adc_key_in > 1000) return btnNONE;

  // For V1.1 us this threshold
  if (adc_key_in < 50)   return btnRIGHT;
  if (adc_key_in < 250)  return btnUP;
  if (adc_key_in < 450)  return btnDOWN;
  if (adc_key_in < 650)  return btnLEFT;
  if (adc_key_in < 850)  return btnSELECT;

  // For V1.0 comment the other threshold and use the one below:
  /*
    if (adc_key_in < 50)   return btnRIGHT;
    if (adc_key_in < 195)  return btnUP;
    if (adc_key_in < 380)  return btnDOWN;
    if (adc_key_in < 555)  return btnLEFT;
    if (adc_key_in < 790)  return btnSELECT;
  */

  return btnNONE;                // when all others fail, return this.
}
Servo myservo;
int pos = 0;
int k=32;
int s=30;
int y=28;
int brightness = 255;
int sensor=44;
int deger=0;
 
void setup() {
  lcd.begin(16, 2);
Serial.begin (9600);
myservo.attach(42);
myservo.write(pos);
pinMode(k,OUTPUT);
pinMode(s,OUTPUT);
pinMode(y,OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(sensor,INPUT);
pinMode(echoPin, INPUT);
}


void loop() {
long sure, mesafe;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
sure = pulseIn(echoPin, HIGH);
digitalWrite(s,LOW);
digitalWrite(y,LOW);
analogWrite(k,brightness);
Serial.println("k");
mesafe = (sure/2) / 29.1;
deger=digitalRead(sensor);
   if (mesafe <= 1){
  // Serial.print("g");
   digitalWrite(k,LOW);
   for (pos = 0; pos <= 90; pos += 1) { 
    Serial.print("ak");
     lcd.setCursor(0, 0); 
    lcd.print("HOSGELDiNiZ");
    digitalWrite(s,HIGH);
    myservo.write(pos);              
    delay(50); 
    }
    Serial.print("a");
    digitalWrite(s,LOW);
    digitalWrite(y,HIGH);
    delay(1500);
    for (pos = 90; pos >= 0; pos -= 1) { 
     Serial.print("ka");
     digitalWrite(s,HIGH);
     digitalWrite(y,LOW);
    myservo.write(pos);              
    delay(50);
    }
    }
  if(deger==LOW){
      digitalWrite(k,LOW);
   for (pos = 0; pos <= 90; pos += 1) { 
    lcd.setCursor(0,0);
    lcd.print("GULE GULE  ");
    
    Serial.print("ak");
    digitalWrite(s,HIGH);
    myservo.write(pos);              
    delay(50); 
    }
    Serial.print("b");
    digitalWrite(s,LOW);
    digitalWrite(y,HIGH);
    delay(1500);
    for (pos = 90; pos >= 0; pos -= 1) { 
     Serial.print("ka");
     digitalWrite(s,HIGH);
     digitalWrite(y,LOW);
    myservo.write(pos);              
    delay(50);
    }
      }
    
}#include <Servo.h>
#define trigPin 50
#define echoPin 48
#include <LiquidCrystal.h>


LiquidCrystal lcd(8, 9, 4, 5, 6, 7);           // select the pins used on the LCD panel

// define some values used by the panel and buttons
int lcd_key     = 0;
int adc_key_in  = 0;
int lm35Pin = 35;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

int read_LCD_buttons() {              // read the buttons
  adc_key_in = analogRead(0);       // read the value from the sensor

  // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
  // we add approx 50 to those values and check to see if we are close
  // We make this the 1st option for speed reasons since it will be the most likely result

  if (adc_key_in > 1000) return btnNONE;

  // For V1.1 us this threshold
  if (adc_key_in < 50)   return btnRIGHT;
  if (adc_key_in < 250)  return btnUP;
  if (adc_key_in < 450)  return btnDOWN;
  if (adc_key_in < 650)  return btnLEFT;
  if (adc_key_in < 850)  return btnSELECT;

  // For V1.0 comment the other threshold and use the one below:
  /*
    if (adc_key_in < 50)   return btnRIGHT;
    if (adc_key_in < 195)  return btnUP;
    if (adc_key_in < 380)  return btnDOWN;
    if (adc_key_in < 555)  return btnLEFT;
    if (adc_key_in < 790)  return btnSELECT;
  */

  return btnNONE;                // when all others fail, return this.
}
Servo myservo;
int pos = 0;
int k=32;
int s=30;
int y=28;
int brightness = 255;
int sensor=44;
int deger=0;
 
void setup() {
  lcd.begin(16, 2);
Serial.begin (9600);
myservo.attach(42);
myservo.write(pos);
pinMode(k,OUTPUT);
pinMode(s,OUTPUT);
pinMode(y,OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(sensor,INPUT);
pinMode(echoPin, INPUT);
}


void loop() {
long sure, mesafe;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
sure = pulseIn(echoPin, HIGH);
digitalWrite(s,LOW);
digitalWrite(y,LOW);
analogWrite(k,brightness);
Serial.println("k");
mesafe = (sure/2) / 29.1;
deger=digitalRead(sensor);
   if (mesafe <= 1){
  // Serial.print("g");
   digitalWrite(k,LOW);
   for (pos = 0; pos <= 90; pos += 1) { 
    Serial.print("ak");
     lcd.setCursor(0, 0); 
    lcd.print("HOSGELDiNiZ");
    digitalWrite(s,HIGH);
    myservo.write(pos);              
    delay(50); 
    }
    Serial.print("a");
    digitalWrite(s,LOW);
    digitalWrite(y,HIGH);
    delay(1500);
    for (pos = 90; pos >= 0; pos -= 1) { 
     Serial.print("ka");
     digitalWrite(s,HIGH);
     digitalWrite(y,LOW);
    myservo.write(pos);              
    delay(50);
    }
    }
  if(deger==LOW){
      digitalWrite(k,LOW);
   for (pos = 0; pos <= 90; pos += 1) { 
    lcd.setCursor(0,0);
    lcd.print("GULE GULE  ");
    
    Serial.print("ak");
    digitalWrite(s,HIGH);
    myservo.write(pos);              
    delay(50); 
    }
    Serial.print("b");
    digitalWrite(s,LOW);
    digitalWrite(y,HIGH);
    delay(1500);
    for (pos = 90; pos >= 0; pos -= 1) { 
     Serial.print("ka");
     digitalWrite(s,HIGH);
     digitalWrite(y,LOW);
    myservo.write(pos);              
    delay(50);
    }
      }
    
}
