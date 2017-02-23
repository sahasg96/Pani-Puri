#include <Servo.h>

Servo Prick;
  int CD = 1;
  int prick = 9; // Servo Motor done.
  int Aloo = 7;  //DC motor with gear done.
  int Pani = 4; 
  int Button = 5; 

void setup() {
  // put your setup code here, to run once:
  pinMode(CD, OUTPUT);
  Prick.attach(prick);
  pinMode(Aloo,OUTPUT);
  pinMode(Pani,OUTPUT);
  pinMode(Button,INPUT);

}

void Hole()
{
  Prick.write(0);  //HIGH
  delay(100);
  Prick.write(90); //LOW
  delay(500);
  Prick.write(0);
}

void Stuffing()
{
  digitalWrite(Aloo,HIGH);
  delay(4000);
  digitalWrite(Aloo,LOW);
}

void Valve()
{
  
}

void Rotate()
{
  digitalWrite(CD,HIGH);
  delay(1000);
  digitalWrite(CD,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
if (digitalRead(Button) == HIGH) // If button is pressed execute below code.
{
  Rotate();
  Hole();
  Rotate();
  Stuffing();
  Rotate();
  Valve();
  Rotate();
}

}
