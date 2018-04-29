const int pinBuz = 6; //Buzzer Pin



    const int pinSwi = 9; // potentialmeter pin
   
  
    const int greensafe=5;
    const int reddanger=4;
    const int bluehelpcoming=3;
        
    void setup() {
      
        Serial.begin(9600); // Opens Serial communication 
        pinMode(pinBuz,OUTPUT); //Defines pinBuz as an Output 
        
        
        pinMode(pinSwi,INPUT); // Defines pinSwi as an input
         
        pinMode(greensafe,OUTPUT); 
        pinMode(reddanger,OUTPUT);
        pinMode(bluehelpcoming,OUTPUT);
              }
              
    void loop () {
      
      int botao; // To save the last logic state of the button
      botao = digitalRead(pinSwi); //Put the reading value of the switch on botao
     // Serial.println(botao); //Shows the logic state of the input on Serial Monitor 

 if (botao == 1){

   if (Serial.available() > 0) {

     String incomingByte = Serial.readString();
      
//HELP IS COMING
        if (botao == 1 && incomingByte.equals("911")) // Pressed button, logic State HIGH (5V)
        {
           digitalWrite(greensafe,LOW);
        digitalWrite(bluehelpcoming,HIGH);
        digitalWrite(reddanger,LOW);
           Serial.println("HELP is coming"); 
       
         tone(pinBuz, 10000); // Send sound signal
         delay(2000); 
  
       noTone(pinBuz);     // Stop sound
     delay(1000);        // 

       tone(pinBuz, 10000); // Send sound signal
      delay(2000); 
          
          noTone(pinBuz);     // Stop sound
        delay(1000);        // for 1sec

         }// close of if condition of inputting 911

     
 } //closing of serial if


// THERE IS DANGER
    else 
      {
       digitalWrite(greensafe,LOW);
        digitalWrite(bluehelpcoming,LOW);
        digitalWrite(reddanger,HIGH);
      digitalWrite(pinBuz,1); //Switch pressed, buzzer on 
       Serial.println("ALERT");
      
     
       tone(pinBuz, 5000); // Send 1KHz sound signal
       delay(2000); 
       
       noTone(pinBuz);     // Stop sound
      delay(1000);        // for 1sec
       
       tone(pinBuz, 5000); // Send 1KHz sound signal
        delay(2000); 
      }// close of else

      
 } //close of if when reading


//YOU ARE SAFE
 else
      { 
         Serial.println("SAFE");
        digitalWrite(greensafe,HIGH);
        digitalWrite(bluehelpcoming,LOW);
        digitalWrite(reddanger,LOW);
      digitalWrite(pinBuz,0); //If the switch isn’t pressed, buzzer off. 
      noTone(pinBuz);
      } 

 
       }// end of void loop
     
