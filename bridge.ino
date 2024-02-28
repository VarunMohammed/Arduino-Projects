#include<Servo.h>

Servo myServo1;
Servo myServo2;

int sensorPower = 6;
int sensorReading = 0;
int angle = 0;

void setup()
{
  Serial.begin(9600);
  myServo1.attach(7);
  myServo2.attach(13);
  pinMode(sensorPower, OUTPUT);
  myServo1.write(90); //90 -> 0
  myServo2.write(90); //90 -> 180
}

void loop()
{
  digitalWrite(sensorPower, HIGH);
  sensorReading = analogRead(A5);
  angle = calculateAngle(sensorReading);
  int servo1Angle = 180 - angle;
  int servo2Angle = angle;
  turnServo1(myServo1.read(),servo1Angle);
  turnServo2(myServo2.read(),servo2Angle);
}

int calculateAngle(int reading)
{
  if(reading > 900 && reading < 1000)
  {
    return 90;
  } else if(reading > 800 && reading < 900) {
    return 110;
  } else if(reading > 700 && reading < 800) {
    return 130;
  } else if(reading > 600 && reading < 700) {
    return 150;
  } else if(reading > 400 && reading < 500) {
    return 180;
  }
}

void turnServo1(int currentAngle, int targetAngle)
{
  if(currentAngle > targetAngle)
  {
    for(int i = currentAngle; i >= targetAngle; i--)
    {
      myServo1.write(i);
      delay(100);
    }
  } else {
    for(int i = currentAngle; i <= targetAngle; i++)
    {
      myServo1.write(i);
      delay(100);
    }
  }
}

void turnServo2(int currentAngle, int targetAngle)
{
  if(currentAngle > targetAngle)
  {
    for(int i = currentAngle; i >= targetAngle; i--)
    {
      myServo2.write(i);
      delay(100);
    }
  } else {
    for(int i = currentAngle; i <= targetAngle; i++)
    {
      myServo2.write(i);
      delay(100);
    }
  }
}