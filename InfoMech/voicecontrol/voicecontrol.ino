#include <SoftwareSerial.h>
#define pinRx_BT 10
#define pinTx_BT 11

String readvoice;
SoftwareSerial serialBT(pinRx_BT,pinTx_BT);

const int trigPin = 8;
const int echoPin = 9;

void setup() {
 serialBT.begin(9600);
 Serial.begin(9600 );
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
//-----------------------------------------------------------------------//  
void loop() {
  while (serialBT.available()){
    delay(10);
    char c = serialBT.read();
    readvoice += c;
  }
  if (readvoice.length() > 0) {
    Serial.println(readvoice);

    if(readvoice == "forward"){
      digitalWrite(3, HIGH);
      digitalWrite (4, LOW);
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      delay(100);
    } else if(readvoice == "backward"){
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(6,HIGH);
      delay(100);
    } else if (readvoice == "right"){
      digitalWrite (3,HIGH);
      digitalWrite (4,LOW);
      digitalWrite (5,LOW);
      digitalWrite (6,LOW);
      delay (100);
    } else if ( readvoice == "left"){
      digitalWrite (3, LOW);
      digitalWrite (4, LOW);
      digitalWrite (5, HIGH);
      digitalWrite (6, LOW);
      delay (100);
    } else if (readvoice == "stop"){
      digitalWrite (3, LOW);
      digitalWrite (4, LOW);
      digitalWrite (5, LOW);
      digitalWrite (6, LOW);
      delay (100);
    }
    readvoice=""; 
  }

  int dist = readDist();
  if(dist <= 20) {
    digitalWrite (3, LOW);
    digitalWrite (4, LOW);
    digitalWrite (5, LOW);
    digitalWrite (6, LOW);
    delay (100);
  }
}

int readDist(){
  long duration;
  int distance;
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   duration = pulseIn(echoPin, HIGH);
   distance= duration*0.034/2;
   Serial.print("Distance: ");
   Serial.println(distance);
   return distance;
}
