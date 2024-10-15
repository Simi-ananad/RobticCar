const int trig = 12;
const int echo = 11;
const int leftAhead = 7;
const int leftBack = 6;
const int rightAhead = 5;
const int rightBack = 4;

int duration = 0;
int distance = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(leftAhead, OUTPUT);
  pinMode(leftBack, OUTPUT);
  pinMode(rightAhead, OUTPUT);
  pinMode(rightBack, OUTPUT);
}

void loop()
{
  // Trigger the ultrasonic sensor
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  // Measure the echo duration and calculate the distance
  duration = pulseIn(echo, HIGH);
  distance = (duration * 0.034 / 2); // Calculate the distance in cm
  
  // Print the distance for debugging
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if (distance > 30)
  {
    // If the object is far away, move forward
    Serial.println("Moving Forward");
    digitalWrite(leftAhead, HIGH);
    digitalWrite(leftBack, LOW);
    digitalWrite(rightAhead, HIGH);
    digitalWrite(rightBack, LOW);
  }
  else if (distance > 10 && distance <= 30)
  {
    // If the object is near, stop the motors
    Serial.println("Stopping");
    digitalWrite(leftAhead, LOW);
    digitalWrite(leftBack, LOW);
    digitalWrite(rightAhead, LOW);
    digitalWrite(rightBack, LOW);
  }
  else if (distance <= 10) 
  {
    // If the object is very close, move backward
    Serial.println("Reversing");
    digitalWrite(leftAhead, LOW);
    digitalWrite(leftBack, HIGH);
    digitalWrite(rightAhead, LOW);
    digitalWrite(rightBack, HIGH);
  }
  
  delay(100);
}
