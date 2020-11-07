#include <Servo.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int servo1 = A2;//orange//20
const int servo2 = A3;//green//21
int val1 = 0;
int val2 = 0;
int c1=0;
int c2=0;
Servo myservo1;
Servo myservo2;

int pos = 0;

void setup() {
    lcd.begin(16, 2);

 Serial.begin(9600);
 myservo1.attach(6);//orange
 myservo2.attach(7);//green
 pinMode(A2,INPUT);
 pinMode(A3,INPUT);
 }

void loop() {
  // put your main code here, to run repeatedly:
val1=analogRead(servo1);
val2=analogRead(servo2);

float v1=val1*(5.0/1023.0);
float v2=val2*(5.0/1023.0);

lcd.setCursor(1, 0);
  lcd.print(" ORANGE ");
  lcd.setCursor(10, 0);
  lcd.print(c1);
 
 lcd.setCursor(1, 1);
 lcd.print(" GREEN  ");
 lcd.setCursor(10, 1);
 lcd.print(c2);


Serial.print("VALUE 1 = ");
Serial.println(v1);
Serial.print("VALUE 2   ");
Serial.println(v2);

if(v1>2)
{  c1+=1;
  lcd.setCursor(1, 0);
  lcd.print("D ORANGE ");
  lcd.setCursor(10, 0);
  lcd.print(c1);
 
  for(pos = 135 ; pos >=30 ; pos -=1) { 
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(2);                       // waits 15ms for the servo to reach the position
           }
  for (pos = 30; pos <= 135; pos += 1) { // goes from 180 degrees to 0 degrees
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  lcd.clear();
}


if(v2>2)
{ c2+=1;
  lcd.setCursor(1, 1);
 lcd.print("D GREEN  ");
 lcd.setCursor(10, 1);
 lcd.print(c2);

   for (pos = 135; pos >= 30; pos -= 1) { 
    myservo2.write(pos);          
    delay(5);                     
  }
  for (pos = 30; pos <= 135; pos += 1) { // goes from 180 degrees to 0 degrees
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  lcd.clear();
}
delay(200);
}
