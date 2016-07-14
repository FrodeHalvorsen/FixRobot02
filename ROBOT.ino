#include <NewPing.h>  // Rangefinder
#include <Servo.h>



// Motor 1
int dir1PinA = 2; // IN1
int dir2PinA = 3; //IN2
int speedPinA = 9; // ENA
int PWM1 = 0; // Set motor speed to 0

// Motor 2
int dir1PinB = 4; //IN3
int dir2PinB = 5; //IN4
int speedPinB = 10; // ENB
int PMW2 = 0; // Set motor speed to 0

// Rangefinder HC-SR04
#define TriggerPin 12
#define EchoPin 11
#define MaxDistance 200



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

void loop() {

// Initialize the Serial interface:

if (Serial.available() > 0) {
int inByte = Serial.read();
int speed; // Local variable

switch (inByte) {

//______________Motor 1______________

case '1': // Motor 1 Forward
analogWrite(speedPinA, 100);//Sets speed variable via PWM
digitalWrite(dir1PinA, LOW);
digitalWrite(dir2PinA, HIGH);
Serial.println("Motor 1 Forward"); // Prints out “Motor 1 Forward” on the serial monitor
Serial.println("   "); // Creates a blank line printed on the serial monitor
break;

case '2': // Motor 1 Stop (Freespin)
analogWrite(speedPinA, 0);
digitalWrite(dir1PinA, LOW);
digitalWrite(dir2PinA, HIGH);
Serial.println("Motor 1 Stop");
Serial.println("   ");
break;

case '3': // Motor 1 Reverse
analogWrite(speedPinA, 100);
digitalWrite(dir1PinA, HIGH);
digitalWrite(dir2PinA, LOW);
Serial.println("Motor 1 Reverse");
Serial.println("   ");
break;

//______________Motor 2______________

case '4': // Motor 2 Forward
analogWrite(speedPinB, 100);
digitalWrite(dir1PinB, LOW);
digitalWrite(dir2PinB, HIGH);
Serial.println("Motor 2 Forward");
Serial.println("   ");
break;

case '5': // Motor 1 Stop (Freespin)
analogWrite(speedPinB, 0);
digitalWrite(dir1PinB, LOW);
digitalWrite(dir2PinB, HIGH);
Serial.println("Motor 2 Stop");
Serial.println("   ");
break;

case '6': // Motor 2 Reverse
analogWrite(speedPinB, 100);
digitalWrite(dir1PinB, HIGH);
digitalWrite(dir2PinB, LOW);
Serial.println("Motor 2 Reverse");
Serial.println("   ");
break;

case '7': // Motor 1 + 2 Reverse
analogWrite(speedPinB, 100);
digitalWrite(dir1PinB, HIGH);
digitalWrite(dir2PinB, LOW);
analogWrite(speedPinA, 100);
digitalWrite(dir1PinA, HIGH);
digitalWrite(dir2PinA, LOW);
delay(1000);
analogWrite(speedPinB, 100);
digitalWrite(dir1PinB, LOW);
digitalWrite(dir2PinB, LOW);
analogWrite(speedPinA, 100);
digitalWrite(dir1PinA, LOW);
digitalWrite(dir2PinA, HIGH);
delay(1000);
analogWrite(speedPinB, 100);
digitalWrite(dir1PinB, LOW);
digitalWrite(dir2PinB, HIGH);
analogWrite(speedPinA, 100);
digitalWrite(dir1PinA, LOW);
digitalWrite(dir2PinA, HIGH);
delay(1000);
analogWrite(speedPinB, 0);
digitalWrite(dir1PinB, LOW);
digitalWrite(dir2PinB, LOW);
analogWrite(speedPinA, 0);
digitalWrite(dir1PinA, LOW);
digitalWrite(dir2PinA, LOW);


break;

default:
// turn all the connections off if an unmapped key is pressed:
for (int thisPin = 2; thisPin < 11; thisPin++) {
digitalWrite(thisPin, LOW);
}
  }
    }
      }
