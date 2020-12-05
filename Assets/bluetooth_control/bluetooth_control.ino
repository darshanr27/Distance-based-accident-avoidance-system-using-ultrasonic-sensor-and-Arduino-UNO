#include <SoftwareSerial.h>
#define pinRx_BT 10
#define pinTx_BT 11
int input1 = 3;
int input2 = 4;
int input3 = 5;
int input4 = 6;
const int trigPin = 8;
const int echoPin = 9;
const int red = 12;
const int yellow = 13;
SoftwareSerial serialBT(pinRx_BT, pinTx_BT);
char rchar;
char F;
char B;
char L;
char R;

void setup() {
  Serial.begin(9600);
  serialBT.begin(9600);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(input3, OUTPUT);
  pinMode(input4, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
}
void loop() {
  if (serialBT.available() > 0) {
    rchar = serialBT.read();
    Serial.println(rchar);
    int dist=readDist();
    if(dist<=25){
      digitalWrite(red,HIGH);
      digitalWrite(yellow,LOW);
    }
    else if(dist<=40){
      digitalWrite(red,LOW);
      digitalWrite(yellow,HIGH);
    }
    else{
      digitalWrite(red,LOW);
      digitalWrite(yellow,LOW);
    }

    if(rchar== 'F' && dist>25)
    {
      digitalWrite(input1,HIGH);
      digitalWrite(input2,LOW);
      digitalWrite(input3,HIGH);
      digitalWrite(input4,LOW);
    }
    else if(rchar=='B') 
    {
      digitalWrite(input1,LOW);
      digitalWrite(input2,HIGH);
      digitalWrite(input3,LOW);
      digitalWrite(input4,HIGH);
    }
    else if(rchar=='L' && dist>25)
    {
      digitalWrite(input1,LOW);
      digitalWrite(input2,HIGH);
      digitalWrite(input3,HIGH);
      digitalWrite(input4,LOW);
    }
    else if(rchar=='R' && dist>25)
    {
      digitalWrite(input1,HIGH);
      digitalWrite(input2,LOW);
      digitalWrite(input3,LOW);
      digitalWrite(input4,HIGH );
    }
    else
    {
      digitalWrite(input1,LOW);
      digitalWrite(input2,LOW);
      digitalWrite(input3,LOW); 
      digitalWrite(input4,LOW);
    }
  }
}
int readDist(){
  long duration;
  int distance;
  digitalWrite (trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  duration = pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
  Serial.print("Distance:");
  Serial.println(distance);
  return distance;
}
