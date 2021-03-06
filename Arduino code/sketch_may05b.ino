#include <HCSR04.h>
HCSR04 hc(9,8);

const int trigPin = 9;
const int echoPin = 8;
const int LEDlampOne = 6;
const int LEDlampTwo = 5;
const int LEDlampThree = 4; 
const int LEDlampFour = 3;
const int alarm = 11;

long duration;
int safetyDistance;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDlampOne, OUTPUT);
  pinMode(LEDlampTwo, OUTPUT);
  pinMode(LEDlampThree, OUTPUT);
  pinMode(LEDlampFour, OUTPUT);
  pinMode(alarm, OUTPUT);
  Serial.begin(9600);
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance = duration*0.034/2;

safetyDistance = distance;

if (safetyDistance < 10) {
    tone (alarm, 600);
    delay (150);
}
if (safetyDistance < 20) {
    tone (alarm, 400);
    delay (150);
}
if (safetyDistance < 30) {
    tone (alarm, 200);
    delay (150);
}
if (safetyDistance < 40) {
    digitalWrite(LEDlampFour, HIGH);
    digitalWrite(LEDlampThree, HIGH);
    digitalWrite(LEDlampTwo, HIGH);
    digitalWrite(LEDlampOne, HIGH);
    delay (150);
}
  else {
    noTone(alarm);
    digitalWrite(LEDlampFour, LOW);
    digitalWrite(LEDlampThree, LOW);
    digitalWrite(LEDlampTwo,LOW);
    digitalWrite(LEDlampOne,LOW);
    delay(150);                
}
}
