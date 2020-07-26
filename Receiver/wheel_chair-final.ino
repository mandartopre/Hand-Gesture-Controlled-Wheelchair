String input_data;
//--------------------------------
#define Sensor 12
#define buzzer 13

#define RL_LEFT1 11
#define RL_LEFT2 10
#define RL_RIGHT1 9
#define RL_RIGHT2 8
//--------------------------------- 

void setup() {
 Serial.begin(9600);
 pinMode(Sensor, INPUT);
 pinMode(buzzer, OUTPUT);
 
 pinMode(RL_LEFT1, OUTPUT);
 pinMode(RL_LEFT2, OUTPUT);
 pinMode(RL_RIGHT1, OUTPUT);
 pinMode(RL_RIGHT2, OUTPUT);
 
 digitalWrite(RL_LEFT1, LOW);
 digitalWrite(RL_LEFT2, LOW);
 digitalWrite(RL_RIGHT1, LOW);
 digitalWrite(RL_RIGHT2, LOW);
 digitalWrite(buzzer, HIGH);
  
 delay(3000);
}
//==================================================================

void loop() {

    if(Serial.available()>0){
        input_data = Serial.readStringUntil('\n');
          // Serial.print(String(input_data));
          // Serial.println();
        
       //------------------------------------- MOVE FORWARD
            if(input_data.indexOf("Fwheelcar")!=-1){
                  //------------------------
                if(digitalRead(Sensor)==LOW){
                Relay_Off();
                digitalWrite(buzzer, LOW);
                Serial.println("em----STOP");
                delay(1000);
                }
                
                
                  //------------------------
                Serial.print("FORWARD");
                Serial.println();
                digitalWrite(RL_LEFT1, HIGH);
                digitalWrite(RL_LEFT2, LOW);

                digitalWrite(RL_RIGHT1, HIGH);
                digitalWrite(RL_RIGHT2, LOW);
       }
      //------------------------------------- MOVE BACKWAORD
     else if(input_data.indexOf("Bwheelcar")!=-1){
      
              Serial.print("BACKWAORD");
              Serial.println();
              digitalWrite(RL_LEFT1, LOW);
              digitalWrite(RL_LEFT2, HIGH);

              digitalWrite(RL_RIGHT1, LOW);
              digitalWrite(RL_RIGHT2, HIGH);
       }
      //------------------------------------- RIGHT          
        else if(input_data.indexOf("Rwheelcar")!=-1){ 
              Serial.print("RIGHT");
              Serial.println();
              digitalWrite(RL_LEFT1, HIGH);
              digitalWrite(RL_LEFT2, LOW);

              digitalWrite(RL_RIGHT1, LOW);
              digitalWrite(RL_RIGHT2, LOW);
       }
      //------------------------------------- 
        else if(input_data.indexOf("Lwheelcar")!=-1){ 
              Serial.print("LEFT");
              Serial.println();
              digitalWrite(RL_LEFT1, LOW);
              digitalWrite(RL_LEFT2, LOW);

              digitalWrite(RL_RIGHT1, HIGH);
              digitalWrite(RL_RIGHT2, LOW);
       }
        else if(input_data.indexOf("STOPwheel")!=-1){ 
          Serial.print("STOP");
          Serial.println();
          Relay_Off();
          digitalWrite(buzzer, HIGH);
          Serial.print("receive STOP");
       }
       
       else{
        Relay_Off();
        digitalWrite(buzzer, HIGH);
        Serial.print("else STOP");
        Serial.println();
        delay(500);
       }       

    }
   
}
//----------------------------------------------


void Relay_Off(){
 digitalWrite(RL_LEFT1, LOW);
 digitalWrite(RL_LEFT2, LOW);
 digitalWrite(RL_RIGHT1, LOW);
 digitalWrite(RL_RIGHT2, LOW);
}
