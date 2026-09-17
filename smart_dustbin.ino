#include <Servo.h>

Servo servo;
int trigPin = 5;
int echoPin = 6;
int servoPin = 7;
long duration;
int distance;

void setup() {
  servo.attach(servoPin);
  servo.write(0); // Close lid initially
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance < 20) {
    servo.write(90); // Open lid
    delay(3000);     // Keep open for 3 seconds
  } else {
    servo.write(0);  // Close lid
  }
  delay(100);
}
