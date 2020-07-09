#include <Servo.h>
#include <LiquidCrystal.h>
Servo servo_12;
Servo servo_13;
LiquidCrystal lcd (11, 10, 5, 4 , 3, 2);
//Q are the angles in radian
//q are the angles in degrees 
//L are the lengths in inches 
int L1 = 10;
int L2 = 10;
float x=5;
float y=18.66;
int q1;
int q2;
float Q1; 
float Q2;
float q =90; 
float COSQ2;


void setup()
{
  //Set number of rows and columns for LCD
  lcd.begin(16,2);
  servo_12.attach(12);
  servo_13.attach(13);
  COSQ2 = ( sq(x) + sq(y) - sq(L1) - sq(L2)) / (2*L1*L2);
  Q2 = acos ( COSQ2 );
  q2= Q2*180/PI;
  q1 = q-q2;
  
  Serial.begin(9600); 
}

void loop()
{
  servo_12.write(q1);
  servo_13.write(q2);
  delay(20); // Wait for 20 millisecond(s)
  lcd.setCursor (0,1);
  lcd.print ("Q1=");
  lcd.setCursor (4,1);
  lcd.print (q1);
  delay(3000);
  lcd.setCursor (0,1);
  lcd.print ("Q2=");
  lcd.setCursor (4,1);
  lcd.print (q2);
  delay(3000);
}