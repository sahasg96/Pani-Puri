
int valve1=12, valve2=13; // valve for paani
int p = 0;

  void setup() {
  // put your setup code here, to run once:
  pinMode(valve1,OUTPUT);
  pinMode(valve2,OUTPUT);
  Serial.begin(9600);

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



void loop() {
  // put your main code here, to run repeatedly:
 
   Valve();
   
  }


