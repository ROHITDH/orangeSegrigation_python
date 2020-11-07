
#include <LiquidCrystal.h>
#include <Servo.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int servo1 = A2;//orange
int servo2 = A5;//green
int val1=0;
int val2=0;
int c1=0;
int c2=0;
Servo myservo1;
Servo myservo2;

int pos = 0;




void setup () {
  lcd.begin(16, 2);
  Serial.begin(9600);
 myservo1.attach(6);
 myservo2.attach(7);
}

void loop () {  

  val1=analogRead(servo1);
val2=analogRead(servo2);
Serial.print("value 1   ");
float v1=val1*(5.0/1023.0);
float v2=val2*(5.0/1023.0);
Serial.println(v1);

Serial.print("value 2   ");
Serial.println(v2);
if(v1>2.7)
{
  c1+=1;

 lcd.setCursor(1, 0);
 lcd.print("D ORANGE ");
 lcd.setCursor(10, 0);
 lcd.print(c1);
 delay(500);

   for (pos = 180; pos >= 30; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
 
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 30; pos <= 180; pos += 1) { // goes from 180 degrees to 0 degrees
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(2);                       // waits 15ms for the servo to reach the position
  }
}

else if(v2>2.7)
{c2+=1;
lcd.setCursor(1, 1);
 lcd.print("D GREEN  ");
 lcd.setCursor(10, 1);
 lcd.print(c2);

   for (pos = 180; pos >= 30; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(3);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 30; pos <= 180; pos += 1) { // goes from 180 degrees to 0 degrees
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
}
 lcd.setCursor(1, 0);
 lcd.print("  ORANGE ");
 lcd.setCursor(10, 0);
 lcd.print(c1);



 lcd.setCursor(1, 1);
 lcd.print("  GREEN  ");
 lcd.setCursor(10, 1);
 lcd.print(c2);
delay(1000);
}

         
         
         
        
    
