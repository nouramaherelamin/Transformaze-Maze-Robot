#include <Arduino.h>

const int motor1Pin1 = 5;
const int motor1Pin2 = 6;
const int motor2Pin1 = 7;
const int motor2Pin2 = 8;
const int motor1SpeedPin = 3;
const int motor2SpeedPin = 11;

const int triggerPinFront = 9;
const int echoPinFront = 10;
const int triggerPinLeft = A0;
const int echoPinLeft = A1;
const int triggerPinRight = A2;
const int echoPinRight = A3;

const int threshold = 20;

void setup() {
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(motor1SpeedPin, OUTPUT);
  pinMode(motor2SpeedPin, OUTPUT);
  
  pinMode(triggerPinFront, OUTPUT);
  pinMode(echoPinFront, INPUT);
  pinMode(triggerPinLeft, OUTPUT);
  pinMode(echoPinLeft, INPUT);
  pinMode(triggerPinRight, OUTPUT);
  pinMode(echoPinRight, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  long frontDistance = measureDistance(triggerPinFront, echoPinFront);
  long leftDistance = measureDistance(triggerPinLeft, echoPinLeft);
  long rightDistance = measureDistance(triggerPinRight, echoPinRight);

  Serial.print("Front: ");
  Serial.print(frontDistance);
  Serial.print(" cm, Left: ");
  Serial.print(leftDistance);
  Serial.print(" cm, Right: ");
  Serial.println(rightDistance);

  if (frontDistance < threshold) {
    stopMotors();
    delay(500);
    reverseMotors();
    delay(500);
    if (leftDistance > rightDistance) {
      turnLeft();
    } else {
      turnRight();
    }
  } else if (leftDistance < threshold) {
    stopMotors();
    delay(200);
    turnRight();
  } else if (rightDistance < threshold) {
    stopMotors();
    delay(200);
    turnLeft();
  } else {
    forwardMotors();
  }
}

long measureDistance(int triggerPin, int echoPin) {
  long totalDistance = 0;
  for (int i = 0; i < 5; i++) {
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    long duration = pulseIn(echoPin, HIGH, 20000);
    long distance = (duration / 2) / 29.1;

    if (distance > 0 && distance < 400) {
      totalDistance += distance;
    }
  }
  return totalDistance / 5;
}

void forwardMotors() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);

  analogWrite(motor1SpeedPin, 200);
  analogWrite(motor2SpeedPin, 200);
}

void stopMotors() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);

  analogWrite(motor1SpeedPin, 0);
  analogWrite(motor2SpeedPin, 0);
}

void reverseMotors() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);

  analogWrite(motor1SpeedPin, 200);
  analogWrite(motor2SpeedPin, 200);
}

void turnRight() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);

  analogWrite(motor1SpeedPin, 200);
  analogWrite(motor2SpeedPin, 0);
  delay(500);
}

void turnLeft() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);

  analogWrite(motor1SpeedPin, 0);
  analogWrite(motor2SpeedPin, 200);
  delay(500);
}
