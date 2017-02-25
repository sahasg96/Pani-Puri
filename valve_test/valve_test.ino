int valve1, valve2;
int count;

  void setup() {
  // put your setup code here, to run once:
   valve1=13, valve2=12;
   count=0;

}


  void stopV(){
    digitalWrite(valve1,LOW);
     digitalWrite(valve2,LOW);
     delay(500); 
    }

    void releaseTheWater(){ 
     
     //to close the valve
     count=0;
     while(count<7)
    {
      digitalWrite(valve1,LOW);
     digitalWrite(valve2,HIGH);
     delay(100);
     count++;
     delay(900);
    }
    
    delay(1000);//delay for the amount of time it takes to fill a puri

   //to open the valve
   count=0;
    while(count<7)
    {
     digitalWrite(valve1,HIGH);
     digitalWrite(valve2,LOW);
     delay(100);
     count++;
     delay(900);
    }
    
     //finish
     digitalWrite(valve1,LOW);
     digitalWrite(valve2,LOW);
  }


void loop() {
  // put your main code here, to run repeatedly:
 
   releaseTheWater();
   
  }


