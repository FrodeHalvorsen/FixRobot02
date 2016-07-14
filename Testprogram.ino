#include <NewPing.h>  // Rangefinder
#include <Servo.h>


// Motor A
int dir1PinA = 2; // IN1
int dir2PinA = 3; //IN2
int speedPinA = 9; // ENA
int PWM1 = 0; // Set motor speed to 0

// Motor B
int dir1PinB = 4; //IN3
int dir2PinB = 5; //IN4
int speedPinB = 10; // ENB
int PMW2 = 0; // Set motor speed to 0

// Rangefinder HC-SR04
#define TriggerPin 12
#define EchoPin 11
#define MaxDistance 200

NewPing sonar (TriggerPin, EchoPin, MaxDistance);


void setup() {  // Setup runs once per reset
// initialize serial communication @ 9600 baud:
Serial.begin(9600);

//Define L298N Dual H-Bridge Motor Controller Pins

pinMode(dir1PinA,OUTPUT);
pinMode(dir2PinA,OUTPUT);
pinMode(speedPinA,OUTPUT);
pinMode(dir1PinB,OUTPUT);
pinMode(dir2PinB,OUTPUT);
pinMode(speedPinB,OUTPUT);

}

void forward (){
  analogWrite(speedPinB, 100);
  digitalWrite(dir1PinB, LOW);
  digitalWrite(dir2PinB, HIGH);
  analogWrite(speedPinA, 100);
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir2PinA, HIGH);
}

void stopp (){
  analogWrite(speedPinB, 0);
  digitalWrite(dir1PinB, HIGH);
  digitalWrite(dir2PinB, LOW);
  analogWrite(speedPinA, 0);
  digitalWrite(dir1PinA, HIGH);
  digitalWrite(dir2PinA, LOW);
}

void turnRight (){
  analogWrite(speedPinB, 100);
  digitalWrite(dir1PinB, HIGH);
  digitalWrite(dir2PinB, LOW);
  analogWrite(speedPinA, 0);
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir2PinA, LOW);

}

void loop() {

// Initialize the Serial interface:

Serial.println(sonar.ping_cm());
/*
while (sonar.ping_cm() > 50){
forward();
Serial.println(sonar.ping_cm());
}
*/

if (sonar.ping_cm() < 50){
  stopp();
  delay(500);
  while(sonar.ping_cm() < 50){
  turnRight();
  }
}
else if (sonar.ping_cm() > 50){
  forward();
}



}
