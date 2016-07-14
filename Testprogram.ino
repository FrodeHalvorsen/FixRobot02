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

int scanList = 0; // 0, 30, 90, 120, 150, 180 deg
int scanCount = 6;

// Servo
Servo servoA;
Servo servoB;
int servoAPos = 0;
int servoBPos = 0;
int servoBScan[6] = {0,30,90,120,150,180};

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

servoA.attach(A0);
servoB.attach(A1);
servoA.write(0);
servoB.write(0);

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

void search (){
  stopp();
  servoA.write(180);
  for (int servoBPos = 0; servoBPos < scanCount; servoBPos ++){
    servoB.write(servoBScan[servoBPos]);
    delay(100);
  }




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
