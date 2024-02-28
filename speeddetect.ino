int irSensor1 = 12;
int irSensor2 = 2;
int led = 8;
int buzzer = 4;

int motion_Sensor1;
int motion_Sensor2;

int executed = 0;
double speed = 0;
double time_s1 = 0;
double time_s2 = 0;
double time = 0;
double distance = 10;

void setup()
{
  Serial.begin(9600);
  pinMode(irSensor1, INPUT);
  pinMode(irSensor2, INPUT);
  pinMode(led, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  if(executed == 0)
  {
    if(digitalRead(irSensor1) == LOW)
    {
      if(time_s1 == 0)
      {
        Serial.println("Motion detected in Sesnor 1");
        time_s1 = millis();
        digitalWrite(led, HIGH);
        tone(buzzer, 500);
        delay(500);
        digitalWrite(led, LOW);
        noTone(buzzer);
      }
    }
    if(digitalRead(irSensor2) == LOW)
    {
      if(time_s2 == 0)
      {
        Serial.println("Motion detected in Sesnor 2");
        time_s2 = millis();
        digitalWrite(led, HIGH);
        tone(buzzer, 250);
        delay(250);
        digitalWrite(led, LOW);
        noTone(buzzer);
        delay(250);
        digitalWrite(led, HIGH);
        tone(buzzer, 250);
        delay(250);
        digitalWrite(led, LOW);
        noTone(buzzer);
      }
    }
    if((time_s1 != 0) && (time_s2 != 0))
    {
      Serial.println("");
      Serial.println("Vehicle crossed both Sensors");
      delay(500);
      time = (time_s2 - time_s1) / 1000.0;
      speed = distance / time;
      Serial.print(speed);
      Serial.print(" m/s");
      Serial.println("");
      if(speed > 6.0)
      {
        Serial.println("Overspeed");
        tone(buzzer, 1000);
        digitalWrite(led, HIGH);
        delay(2000);
        digitalWrite(led, LOW);
        noTone(buzzer);
      }
      else 
      {
        Serial.println("Normal Speed");
        digitalWrite(led,HIGH);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(1000);
        digitalWrite(led, LOW);
        digitalWrite(LED_BUILTIN, LOW);
      }
      executed = 1;
    }
  }
}
