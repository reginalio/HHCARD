int led = 6;

void setup() {
  pinMode(led,OUTPUT);
  digitalWrite(led, LOW);
  
  // I read online that you may need to use Serial1 instead of Serial
  // if you are using the Arduino micro for rx input
  // (Serial worked fine for Arduino Uno)
  Serial.begin(9600);
  Serial1.begin(9600); 
  while(!Serial1){}
  Serial1.flush(); 
}

void loop() {
  // Check bluetooth input if available, else just blink
  if(Serial1.available() > 0){
    char input = (char)Serial1.read();
    Serial.println(input);
    
    // if input is A, keep LED on until input changes
    if(input == 'A'){
      digitalWrite(led, HIGH);
      Serial.println("I see A");    
      while(1){
        Serial.println("Waiting to blink again");
        Serial.println(input);
        if(Serial1.available() > 0){
           input = (char)Serial1.read();
           Serial.println("I read");
           Serial.println(input);
           if(input != 'A'){
             break;
           }
        }else{
          delay(100);
        }
      }
    }
  }
  else{
    // input not available
    blinkLED(led);
  }
}

void blinkLED(int thatLED){
    digitalWrite(thatLED, HIGH);
     delay(200);  
     digitalWrite(thatLED,LOW);
     delay(200);
}
