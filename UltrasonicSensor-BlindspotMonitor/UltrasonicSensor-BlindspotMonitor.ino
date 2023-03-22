//Programmer:Alex Thornton
//Date:2.16.23
//Program:Blind Spot Monitor
//Resource:https://projecthub.arduino.cc/Krepak/a6ea3ad5-fd23-49c9-a96c-5e6fcf97f2cc?ref=search&ref_id=red%20green%20yellow%20light%20echo%20sensor&offset=1

/*
 * This program will determine the distance of approaching 
 * vehicles that are in your blind spot and turn on a warning light
 */


int trigPin = 7;
int echoPin = 6;
int LEDlampRed = 9;
int LEDlampBlue = 10;
int LEDlampClear = 11;
int soundbuzzer 3;
int sound  = 500;
8
9
10void setup() {
11  Serial.begin (9600);
12  pinMode(trigPin,  OUTPUT);
13  pinMode(echoPin, INPUT);
14  pinMode(LEDlampRed, OUTPUT);
15  pinMode(LEDlampYellow,  OUTPUT);
16  pinMode(LEDlampGreen, OUTPUT);
17  pinMode(soundbuzzer, OUTPUT);
18}
19void  loop() {
20  long durationindigit, distanceincm;
21  digitalWrite(trigPin, LOW);  
22  delayMicroseconds(2);
23  digitalWrite(trigPin, HIGH);
24  delayMicroseconds(10);
25  digitalWrite(trigPin, LOW);
26  durationindigit = pulseIn(echoPin, HIGH);
27  distanceincm = (durationindigit/5) / 29.1;
28 
29  if (distanceincm < 50) {
30      digitalWrite(LEDlampGreen, HIGH);
31}
32  else {
33      digitalWrite(LEDlampGreen,  LOW);
34  }
35  
36  if (distance < 20) {
37    digitalWrite(LEDlampYellow,  HIGH);
38}
39  else {
40    digitalWrite(LEDlampYellow,LOW);
41  }
42  if (distance  < 5) {
43    digitalWrite(LEDlampRed, HIGH);
44    sound = 1000;
45}
46  else  {
47    digitalWrite(LEDlampRed,LOW);
48  }
49 
50  if (distanceincm > 5 ||  distanceinsm <= 0){
51    Serial.println("Outside the permissible range of distances");
52    noTone(soundbuzzer);
53  }
54  else {
55    Serial.print(distance);
56    Serial.println("  cm");
57    tone(buzzer, sound);
58  }
59  
60  delay(300);
61}
