#define echoPin 2
#define trigPin 3

long duration;
int distance;

void setup() {
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(5,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);

  distance=duration*0.034/2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm");
  if(distance<=3)
  {
    digitalWrite(5,HIGH);
    Serial.print("PUMP ON ");
    digitalWrite(5,LOW);
    Serial.print("PUMP OFF ");
    delay(2000);
  }
  else
  {
    digitalWrite(5,LOW);
    Serial.print("PUMP OFF ");
  }
  delay(50); 
}
