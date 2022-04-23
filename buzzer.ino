/*
Arduino 1.8.19
*/

int buzzer = 5; // buzzer
int trig = 9;
int echo = 7;
void setup()
{
  Serial.begin(10000);
  pinMode(buzzer, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(3);
  digitalWrite(trig, HIGH);
  delayMicroseconds(3);
  digitalWrite(trig, LOW);
  int a = pulseIn(echo, HIGH);
  int distance = a * 0.0343 / 2;
  Serial.print("Value of US sensor");
  Serial.println(distance);

  if (distance < 50)
  {
    digitalWrite(buzzer, LOW);

  if (distance < 25)
  {
    digitalWrite(buzzer, LOW);
    delay(800);
    digitalWrite(buzzer, LOW);
    delay(800);
  }

  if (distance < 10)
  {
    digitalWrite(buzzer, HIGH);
    delay(600);
    digitalWrite(buzzer, LOW);
    delay(600);
    digitalWrite(buzzer, HIGH);
    delay(600);
    digitalWrite(buzzer, LOW);
    delay(600);
  }

}