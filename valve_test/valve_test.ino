
int valve1=12, valve2=13; // valve for paani
int p = 0;

 void Valve(){ 


    // Serial.print("P - ON");
   // Serial.println(p);
    
     //to open the valve
     
     for(int i=1; i<=6; i++)
     {
       digitalWrite(valve1,LOW);
       digitalWrite(valve2,HIGH);
       delay(211);
     }
     digitalWrite(valve1,LOW);
     digitalWrite(valve2,LOW);    
     delay(15000);       //******************************CHANGE*******************************

     //to close the valve
     
     for(int i=1;i<=6;i++)
     {
       digitalWrite(valve1,HIGH);
       digitalWrite(valve2,LOW);
       delay(211);
     }
     digitalWrite(valve1,LOW);
     digitalWrite(valve2,LOW);
  }


  void setup() {
  // put your setup code here, to run once:
  pinMode(valve1,OUTPUT);
  pinMode(valve2,OUTPUT);
 // Serial.begin(9600);
  Valve();

}

 

void loop() {
 
   
   
  }


