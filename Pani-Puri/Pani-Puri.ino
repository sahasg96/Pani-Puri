#include <Servo.h>

  Servo Prick;
  int CD = 1;
  int prick = 9; // Servo Motor done.
  int Aloo = 7;  //DC motor with gear done.
  int Pani = 4;
  int Button = 5;
  int p = 0 , a = 0, h = 0;  //function counters.
  int button_count = 0;

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

void startup()
  {
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
    //button_count++;
  }

boolean buttonpress()
  {
    /*if(Button.read()==1)
      return true;
     else
      return false; */

      // after debouce it gives a true or false for whether the button was pressed. If true the button_count is incremented.

  }


void loop()
  {
    if(buttonpress())
      {
        if(button_count == 1)
          {
            startup();
          }

        if(button_count<=6 && button_count >1)
          {
            if(p<=6)
              Valve();

            Rotate();

            if(a<=6)
              Stuffing();

            if(h<=6)
              Hole();
          }

        if(button_count == 6)
          button_count=0;
      }
  }
