#define echo 10
#define trig 9
int motor = 3;
int buzzer=7;
long distance;
long time;
void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(motor, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trig, HIGH);
  delayMicroseconds(2);
  digitalWrite(trig, LOW); 
  time = pulseIn(echo,HIGH);
  delayMicroseconds(10);
  distance = time*0.034/2;
  Serial.println(distance);
  if (distance <=100)
  {
    tone(buzzer,450);
    delay(50);
    noTone(buzzer);
    delay(50);
    digitalWrite(3,HIGH);
  }
  if (distance >=100 & distance <=200)
  {
    tone(buzzer,250);
    delay(200);
    noTone(buzzer);
    delay(200);
    digitalWrite(3,HIGH);
  }
   if (distance >=200 & distance <=300)
  {
    tone(buzzer,50);
    delay(500);
    noTone(buzzer);
    delay(500);
    digitalWrite(motor,HIGH);
  }
}
