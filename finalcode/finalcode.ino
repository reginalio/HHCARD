#define trigPin 12
#define echoPin 13

int led6 = 6;  /* creat variable for ledPin and set it to 13*/
int led11 = 11;
int led10 = 10;
int led9 = 9;
char input = 'X';
char pastInput;

void setup()
{
  pinMode (led6, OUTPUT); /*pinmode read out put only*/
  pinMode (led11, OUTPUT);
  pinMode (led10, OUTPUT);
  pinMode (led9, OUTPUT);
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  digitalWrite(led6, LOW);  /*writemode to low*/  
  digitalWrite(led11, LOW);
  digitalWrite(led10, LOW);
  digitalWrite(led9, LOW);
  
  // serial port communicate in RX and TX also with computer via USB
  Serial.begin(9600);   /* deflaut board rate for the bluetooth module ... initialize serial and wait for port to open*/ 
  Serial.flush();      // wait for the traansmission of outgoing data to complete remove buffered incoming serial data
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
     delay(500);  
     digitalWrite(thatLED,LOW);
     delay(500);
}
  
void loop ()
{
   long distance = 30;
   if(input != 'X' || Serial.available() >0){
     if(input == 'X')
         input = (char) Serial.read();
         
     // wait until ultrasound is close enough
     do{
      distance = getDistance();
      Serial.println("Out of range");
     }while(distance > 15);
     
    Serial.print(distance);        //LED on depends on the input
    Serial.println(" cm");

     if(input == 'A'){
       while(1){
          blinkLED(led6);
         input = (char) Serial.read();
         if (input == 'B'){   // 20mL
               do{
                 blinkLED(led6);
                 distance = getDistance();
               }while(distance >15);
           break;
         }
       }
     }else if (input == 'B'){
       digitalWrite(led6, HIGH);
       while(1){
          blinkLED(led11);
          input = (char) Serial.read();
          if (input == 'C'){   // 40mL
               do{
                 blinkLED(led11);
                 distance = getDistance();
               }while(distance > 15);
               break;
          }
        }
     }else if(input == 'C'){
       digitalWrite(led6, HIGH);
        digitalWrite(led11, HIGH);  
        while(1)
         {
          blinkLED(led10);
          input = (char) Serial.read();
          if (input == 'D'){   // 60mL
               do{
                 blinkLED(led10);
                 distance = getDistance();
               }while(distance > 15);
               break;
          }
         }
     }else if(input == 'D'){
       digitalWrite(led6, HIGH);
        digitalWrite(led11, HIGH);
        digitalWrite(led10, HIGH);  
        while(1)
         {
          blinkLED(led9);
          input = (char) Serial.read();
          if (input == 'E') {   // 80mL
               do{
                 blinkLED(led9);
                 distance = getDistance();
               }while(distance > 15);
               break;
          }
         }
     }else if(input == 'E'){
       digitalWrite(led6, HIGH);
        digitalWrite(led11, HIGH);
        digitalWrite(led10, HIGH); 
         digitalWrite(led9, HIGH); 
       input = (char) Serial.read();

    } 
    else  if(input == 'X')
        {
        digitalWrite(led6,LOW);  
        digitalWrite(led11,LOW);   
        digitalWrite(led10,LOW);   
        digitalWrite(led9,LOW);
        }
     }
}
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
//                digitalWrite(led6, HIGH);
//                delay(500);  
//                digitalWrite(led6,LOW);
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
//         digitalWrite(led6, HIGH);
//        }
//               if (input == 'C')   // 21-39mL
//           {
//              while(1)
//               {
//                digitalWrite(led11, HIGH);
//                delay(500);  
//                digitalWrite(led11,LOW);
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
//            digitalWrite(led6, HIGH);  
//            digitalWrite(led11, HIGH);  
//             }
//             if (input == 'E')   // 41-59mL
//           {
//              while(1)
//               {
//                digitalWrite(led10, HIGH);
//                delay(500);  
//                digitalWrite(led10,LOW);
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
//            digitalWrite(led6, HIGH);  
//            digitalWrite(led11, HIGH);  
//            digitalWrite(led10, HIGH);  
//             }
//             if (input == 'G')   // 61-79mL
//           {
//              while(1)
//               {
//                digitalWrite(led9, HIGH);
//                delay(500);  
//                digitalWrite(led9,LOW);
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
//            digitalWrite(led6,HIGH);  
//            digitalWrite(led11,HIGH);  
//            digitalWrite(led10,HIGH); 
//            digitalWrite(led9,HIGH);
//            }
//         else if (input == 'I')   //0mL
//            {
//            digitalWrite(led6,LOW);  
//            digitalWrite(led11,LOW);   
//            digitalWrite(led10,LOW);   
//            digitalWrite(led9,LOW);
//            }
//         }
//   }
// }
