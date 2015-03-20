#define trigPin 12
#define echoPin 13


int led6 = 6;  /* creat variable for ledPin and set it to 13*/
int led11 = 11;
int led10 = 10;
int led9 = 9;
//int trigPin = 12;
int i=0;
int x=0;

//int state=0; /* variable to store data serial.read*/
//int flag=0;
//digitalRead(pin) is to reads the value from a specified digital pin , either HiGH or LOW

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

void loop ()
{ 
  
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  if (distance >= 15)
  {
    Serial.println("Out of range");
    digitalWrite(led11, LOW);
    digitalWrite(led10, LOW);
    digitalWrite(led9,LOW);
    digitalWrite(led6, LOW);
    
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    delay(1000);
       // digitalQrite
       // String input = "";
       //loop function
     while (Serial.available() >0)
         {
          String input = "";
          input += (char) Serial.read();   // Read in one char at a time    
       x= digitalRead (6)  ;
         Serial.println(x );
        if (input == "A")
           {
            //  while(input != "B")
              //{
             digitalWrite(led6, HIGH);
            // delay(500);  //on pin 13
             //digitalWrite(led6,LOW);
             //delay(500);
             //if (input == "B") 
            // {
                 //break;
                // }
            //  }
            }   
        if (input == "B")
        {
         digitalWrite(led6, HIGH);
          digitalWrite(led11, HIGH);
        }
              // for (int i=0;i<=100;i++)
        // if (input == "C")
          // {
         //digitalWrite(led6, HIGH);  //on pin 13
         //digitalWrite(led11, HIGH);
         //delay (1000);
        // digitalWrite(led6, LOW);
        //delay (1000);
        //on pin 9
        //delay (1000);
        // digitalWrite(led11, LOW);
        //delay (1000);
           // }
          if (input == "C")
             {
            digitalWrite(led6, HIGH);  //on pin 13
            digitalWrite(led11, HIGH);  //on pin 13
            digitalWrite(led10, HIGH);  //on pin 13
             }
         if (input == "D")
            {
            digitalWrite(led6, HIGH);  //on pin 13
            digitalWrite(led11, HIGH);  //on pin 13
            digitalWrite(led10, HIGH);  //on pin 13
            digitalWrite(led9, HIGH);
            }
      else if (input == "E")
      {
     digitalWrite(led6, LOW);  //off pin 13
     digitalWrite(led11, LOW);   //off pin 9
     digitalWrite(led10, LOW);   //off pin 9
     digitalWrite(led9,LOW);
      }
         }
   }
 }
