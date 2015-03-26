#define trigPin 12
#define echoPin 13

int led1 = 6;  /* creat variable for ledPin and set it to 6*/
int led2 = 11;
int led3 = 10;
int led4 = 9;
char input = 'X';
char pastInput;

void setup()
{
  pinMode (led1, OUTPUT); /*pinmode read out put only*/
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  pinMode (led4, OUTPUT);
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  
  digitalWrite(led1, HIGH);  /*writemode to low*/  
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  delay(2000);
  
  digitalWrite(led1, LOW);  /*writemode to low*/  
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  
  // serial port communicate in RX and TX also with computer via USB
  Serial.begin(9600);   /* deflaut board rate for the bluetooth module ... initialize serial and wait for port to open*/ 
  Serial.flush();      // wait for the traansmission of outgoing data to complete remove buffered incoming serial data
 
  Serial1.begin(9600);   /* deflaut board rate for the bluetooth module ... initialize serial and wait for port to open*/ 
  while(!Serial1){}
  Serial1.flush();      // wait for the traansmission of outgoing data to complete remove buffered incoming serial data
  
}

long getDistance(){
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  return distance;
}

void blinkLED(int thatLED){
    digitalWrite(thatLED, HIGH);
     delay(300);  
     digitalWrite(thatLED,LOW);
     delay(300);
}
  
void loop ()
{
   long distance = 30;
   if(input != 'X' || Serial1.available() >0){
     if(input == 'X'){
         input = (char) Serial1.read();
         Serial.println("read input" + input);
         
         // wait until ultrasound is close enough
         do{
          distance = getDistance();
          Serial.println("Out of range");
         }while(distance > 15);
         
        Serial.print(distance);        //LED on depends on the input
        Serial.println(" cm");
      }

     if(input == 'A'){
       Serial.print("read input");
       Serial.println(input);
       digitalWrite(led2, LOW);
       digitalWrite(led3, LOW);
       digitalWrite(led4, LOW);
       while(1){
         blinkLED(led1);
         if (Serial1.available()>0){
           input = (char) Serial1.read();
           Serial.print("A: read input ");
           Serial.println(input);
           if (input != 'A'){              // 1-19mL
             do{
               blinkLED(led1);
               distance = getDistance();
                Serial.println("Out of range");
             }while(distance >15);
             Serial.print(distance);        //LED on depends on the input
             Serial.println(" cm");
             break;
           }
         }
       }
     }
     
     else if (input == 'B'){            //20mL
       Serial.print("read input");
       Serial.println(input);
       digitalWrite(led1, HIGH);
       digitalWrite(led2, LOW);
       digitalWrite(led3, LOW);
       digitalWrite(led4, LOW);
       while(input == 'B'){
         if(Serial1.available()>0)
            input = (char) Serial1.read();
        distance = getDistance();
        Serial.print(distance);        //LED on depends on the input
        Serial.println(" cm");
        delay(1000);
       } 
     }
       
       else if (input == 'C'){
         Serial.print("read input");
         Serial.println(input);
         digitalWrite(led1, HIGH);
         digitalWrite(led3, LOW);
         digitalWrite(led4, LOW);
         while(1){
          blinkLED(led2);
          if(Serial1.available()>0){
            input = (char) Serial1.read();
            if (input != 'C'){               // 21-39mL
                 do{
                   blinkLED(led2);
                   distance = getDistance();
                    Serial.println("Out of range");
                 }while(distance > 15);
                 Serial.print(distance);        //LED on depends on the input
                 Serial.println(" cm");
              break;
            }
          }
        }
     }
     
      else if (input == 'D'){              //40mL
         Serial.print("read input");
         Serial.println(input);
         digitalWrite(led1, HIGH);
         digitalWrite(led2, HIGH);
         digitalWrite(led3, LOW);
         digitalWrite(led4, LOW); 
         while(input == 'D'){
           if(Serial1.available()>0)
              input = (char) Serial1.read();
          distance = getDistance();
          Serial.print(distance);        //LED on depends on the input
          Serial.println(" cm");
          delay(1000);
         }        
     }
     else if(input == 'E'){ 
       Serial.print("read input");
       Serial.println(input);
       digitalWrite(led1, HIGH);
       digitalWrite(led2, HIGH);
       digitalWrite(led4, LOW); 
       while(1){
         blinkLED(led3);
         if(Serial1.available()>0){
           input = (char) Serial1.read();
           if (input != 'E'){                // 41-59mL
                 do{
                   blinkLED(led3);
                   distance = getDistance();
                    Serial.println("Out of range");
                 }while(distance > 15);
                 Serial.print(distance);        //LED on depends on the input
                 Serial.println(" cm");
                 break;
            }
         }
       }
     }
      else if (input == 'F'){            //60mL
         Serial.print("read input");
        Serial.println(input);
         digitalWrite(led1, HIGH);
         digitalWrite(led2, HIGH);
         digitalWrite(led3, HIGH);
         digitalWrite(led4, LOW); 
         while(input == 'F'){
           if(Serial1.available()>0)
              input = (char) Serial1.read();
          distance = getDistance();
          Serial.print(distance);        //LED on depends on the input
          Serial.println(" cm");
          delay(1000);
         }  
     }
     
     else if(input == 'G'){
       Serial.print("read input");
       Serial.println(input);
       digitalWrite(led1, HIGH);
       digitalWrite(led2, HIGH);
       digitalWrite(led3, HIGH);
       while(1){
         blinkLED(led4);
         if(Serial1.available()>0){
           input = (char) Serial1.read();
           if (input == 'H') {   // 61-79mL
             do{
               blinkLED(led4);
               distance = getDistance();
               Serial.println("Out of range");
              }while(distance > 15);
              Serial.print(distance);        //LED on depends on the input
              Serial.println(" cm");
              break;
           }
         }
       }
     }
     else if (input == 'H'){            //80mL
       Serial.print("read input");
       Serial.println(input);
       digitalWrite(led1, HIGH);
       digitalWrite(led2, HIGH);
       digitalWrite(led3, HIGH);
       digitalWrite(led4, HIGH);
       while(input == 'H'){
        if(Serial1.available()>0)
          input = (char) Serial1.read();
        distance = getDistance();
        Serial.print(distance);        //LED on depends on the input
        Serial.println(" cm");
        delay(1000);
       } 
     }
    
    else if (input == 'Z'){            //60mL
      Serial.print("read input");
      Serial.println(input);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      while(input == 'Z'){
        if(Serial1.available()>0)
          input = (char) Serial1.read();
        distance = getDistance();
        Serial.print(distance);        //LED on depends on the input
        Serial.println(" cm");
        delay(1000);
      }
     }
     // for shake
     else if (input == 'S'){
       Serial.print("read input");
       Serial.println(input);
       while(input == 'S'){
         if(Serial1.available()>0)
           input = (char) Serial1.read();
           
          digitalWrite(led1, LOW);
          digitalWrite(led2, LOW);
          digitalWrite(led3, LOW);
          digitalWrite(led4, LOW);
          delay(200);
          digitalWrite(led1, HIGH);
          digitalWrite(led2, HIGH);
          digitalWrite(led3, HIGH);
          digitalWrite(led4, HIGH);
          delay(200);
       }
     }
     //for pour out
     else if(input == 'O'){
          Serial.print("read input");
          Serial.println(input);    
          digitalWrite(led1, LOW);
          delay(500);
          digitalWrite(led2, LOW);
          delay(500);
          digitalWrite(led3, LOW);
          delay(500);
          digitalWrite(led4, LOW);
          while(input == 'O'){
            if(Serial1.available()>0)
              input = (char) Serial1.read();
          }
     }
     else{
       Serial.println("Do not recognise input" + input);
       distance = getDistance();
       Serial.print(distance);        //LED on depends on the input
       Serial.println(" cm");
       delay(1000);
       input = 'Z';
   }
   }
}

     
     
     
  /*  else  if(input == 'X')
        {
        digitalWrite(led1,LOW);  
        digitalWrite(led2,LOW);   
        digitalWrite(led3,LOW);   
        digitalWrite(led4,LOW);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
        {
        digitalWrite(led1,LOW);
         delay (500);

        digitalrite(led3,LOW);   
        digitalWrite(led4,LOW);
          
     }*/
   /* else if(input == 'E'){
       digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH); 
         digitalWrite(led4, HIGH); 
       input = (char) Serial1.read();

    } */



//
//
//
//
//
//
//  if (distance >= 15)               //no LED will on 
//  {
//    Serial.println("Out of range");
//  }
//  
//  else {                           
//    Serial.print(distance);        //LED on depends on the input
//    Serial.println(" cm");
//    delay(50);
//    
//  //loop function
//     while (Serial.available() >0)
//         {
//          char input;
//          input = (char) Serial.read();   // Read in one char at a time    
//    
//        if (input == 'A')   // 1-19mL
//           {
//              while(1)
//               {
//                digitalWrite(led1, HIGH);
//                delay(500);  
//                digitalWrite(led1,LOW);
//                delay(500);
//                input = (char) Serial.read();
//                if (input == 'B')   // 20mL
//                   {
//                     break;
//                   }
//                 }
//            }   
//        if (input == 'B')         //20mL
//        {
//         digitalWrite(led1, HIGH);
//        }
//               if (input == 'C')   // 21-39mL
//           {
//              while(1)
//               {
//                digitalWrite(led2, HIGH);
//                delay(500);  
//                digitalWrite(led2,LOW);
//                delay(500);
//                input = (char) Serial.read();
//                if (input == 'D')   // 40mL
//                   {
//                     break;
//                   }
//                 }
//            }   
//          if (input == 'D')      // 40mL
//             {
//            digitalWrite(led1, HIGH);  
//            digitalWrite(led2, HIGH);  
//             }
//             if (input == 'E')   // 41-59mL
//           {
//              while(1)
//               {
//                digitalWrite(led3, HIGH);
//                delay(500);  
//                digitalWrite(led3,LOW);
//                delay(500);
//                input = (char) Serial.read();
//                if (input == 'F')   // 60mL
//                   {
//                     break;
//                   }
//                 }
//            }   
//             if (input == 'F')     //60mL
//             {
//            digitalWrite(led1, HIGH);  
//            digitalWrite(led2, HIGH);  
//            digitalWrite(led3, HIGH);  
//             }
//             if (input == 'G')   // 61-79mL
//           {
//              while(1)
//               {
//                digitalWrite(led4, HIGH);
//                delay(500);  
//                digitalWrite(led4,LOW);
//                delay(500);
//                input = (char) Serial.read();
//                if (input == 'H')   // 80mL
//                   {
//                     break;
//                   }
//                 }
//            }
//        
//         if (input == 'H')    //80mL
//            {
//            digitalWrite(led1,HIGH);  
//            digitalWrite(led2,HIGH);  
//            digitalWrite(led3,HIGH); 
//            digitalWrite(led4,HIGH);
//            }
//         else if (input == 'I')   //0mL
//            {
//            digitalWrite(led1,LOW);  
//            digitalWrite(led2,LOW);   
//            digitalWrite(led3,LOW);   
//            digitalWrite(led4,LOW);
//            }
//         }
//   }
// }
