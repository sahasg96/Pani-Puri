#include <Servo.h>

  Servo Prick; // creating servo object
  int CD = 8;   // CD Motor control pin
  int prick = 9; // Servo Motor done.
  int Aloo = 10;  //DC motor with gear done.
 // int Pani = 4;   
  int ButtonPin = 4;
  int p = 0 , a = 0, h = 0;  //function counters.
  int button_count = 0;
  int valve1=12, valve2=13; // valve for paani
  
void setup() {
  // put your setup code here, to run once:
  pinMode(CD, OUTPUT);
  Prick.attach(prick);
  pinMode(Aloo,OUTPUT);
  pinMode(valve1,OUTPUT);
  pinMode(valve2,OUTPUT);
  //pinMode(Pani,OUTPUT);
  pinMode(ButtonPin,INPUT);
  Serial.begin(9600);

}

void Hole()
  {
    Serial.print("H");
    Serial.println(h);
    
    Prick.write(0);  //HIGH
    delay(1000);
    Prick.write(90); //LOW
    delay(1000);
    Prick.write(0);
  }

void Stuffing()
  {
    Serial.print("A-On");
    Serial.println(a);
    
    digitalWrite(Aloo,HIGH);
    delay(3000);
    digitalWrite(Aloo,LOW);
    Serial.println("A-Off");
  }

   void Valve(){ 


     Serial.print("P - ON");
    Serial.println(p);
    
     //to close the valve
      digitalWrite(valve1,LOW);
     digitalWrite(valve2,HIGH);
     delay(900);
    
      delay(10000);//delay for the amount of time it takes to fill a puri with paani

     //to open the valve
     digitalWrite(valve1,HIGH);
     digitalWrite(valve2,LOW);
     delay(900);
    
     //finish
     digitalWrite(valve1,LOW);
     digitalWrite(valve2,LOW);

     Serial.println("P - OFF");
  }

void Rotate()
  {
    Serial.println("R");
    digitalWrite(CD,HIGH);
    delay(545);
    digitalWrite(CD,LOW);
  }

void startup()
  {
    Serial.println("Startup");
    
    Rotate();
    Hole();
    Rotate();
    Stuffing();
    Hole();
    Rotate();
    Valve();
    Stuffing();
    Hole();
    Rotate();
    Stuffing();
    Hole();

    p=2;
    a=4;
    h=5;
  }

int buttonpress()
  {
      int state=0;
      if(digitalRead(ButtonPin)==HIGH)
      {
        delay(10);
        if(digitalRead(ButtonPin)==HIGH)
        {
           state=1;
           button_count++;
           Serial.println("ButtonPress");
        }
      }
      return(state);
  }

void loop()
  {
    if(buttonpress())
      {
        Serial.print("button_count=");
        Serial.println(button_count);
        
        if(button_count == 1)
          {
            startup();
          }

        if(button_count<=6 && button_count >1)
          {
            if(p<=6)
              {
                Valve();
                p++;
              }

            Rotate();

            if(a<=6)
              {
                Stuffing();
                a++;
              }

            if(h<=6)
              {
                Hole();
                h++;
              }
          }

        if(button_count == 6)
          button_count=0;
      
      Serial.println(" ");
      }
  }

