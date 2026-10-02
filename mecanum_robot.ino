/**
 * @file mecanum_robot.ino
 * @brief 4-Wheel Mecanum Omnidirectional Mobile Platform
 * @target Arduino Uno R3 + L293D Motor Driver Shield + HC-05 Bluetooth
 */

#include <AFMotor.h>

// Motor Channel Configuration
// Motor 1: Front-Left | Motor 2: Rear-Left
// Motor 3: Rear-Right | Motor 4: Front-Right
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

int motorSpeed = 255; // 0 to 255 PWM

// Function Prototypes
void forward();
void backward();
void left();
void right();
void topLeft();
void topRight();
void bottomLeft();
void bottomRight();
void stopRobot();

void setup() {
  Serial.begin(9600); // Baud rate for HC-05 Bluetooth module
  stopRobot();
}

void loop() {
  if (Serial.available() > 0) {
    char cmd = Serial.read();

    switch (cmd) {
      case 'F': forward();     break;
      case 'B': backward();    break;
      case 'L': left();        break; // Lateral strafe left
      case 'R': right();       break; // Lateral strafe right
      case 'G': topLeft();     break; // Diagonal forward-left
      case 'I': topRight();    break; // Diagonal forward-right
      case 'H': bottomLeft();  break; // Diagonal backward-left
      case 'J': bottomRight(); break; // Diagonal backward-right
      case 'S': stopRobot();   break;
      default:  break;
    }
  }
}

void forward() {
  motor1.setSpeed(motorSpeed); motor1.run(FORWARD);
  motor2.setSpeed(motorSpeed); motor2.run(BACKWARD);
  motor3.setSpeed(motorSpeed); motor3.run(FORWARD);
  motor4.setSpeed(motorSpeed); motor4.run(BACKWARD);
}

void backward() {
  motor1.setSpeed(motorSpeed); motor1.run(BACKWARD);
  motor2.setSpeed(motorSpeed); motor2.run(FORWARD);
  motor3.setSpeed(motorSpeed); motor3.run(BACKWARD);
  motor4.setSpeed(motorSpeed); motor4.run(FORWARD);
}

void left() {
  motor1.setSpeed(motorSpeed); motor1.run(BACKWARD);
  motor2.setSpeed(motorSpeed); motor2.run(BACKWARD);
  motor3.setSpeed(motorSpeed); motor3.run(BACKWARD);
  motor4.setSpeed(motorSpeed); motor4.run(BACKWARD);
}

void right() {
  motor1.setSpeed(motorSpeed); motor1.run(FORWARD);
  motor2.setSpeed(motorSpeed); motor2.run(FORWARD);
  motor3.setSpeed(motorSpeed); motor3.run(FORWARD);
  motor4.setSpeed(motorSpeed); motor4.run(FORWARD);
}

void topLeft() {
  motor1.setSpeed(motorSpeed); motor1.run(FORWARD);
  motor2.setSpeed(0);          motor2.run(RELEASE);
  motor3.setSpeed(motorSpeed); motor3.run(FORWARD);
  motor4.setSpeed(0);          motor4.run(RELEASE);
}

void topRight() {
  motor1.setSpeed(0);          motor1.run(RELEASE);
  motor2.setSpeed(motorSpeed); motor2.run(BACKWARD);
  motor3.setSpeed(0);          motor3.run(RELEASE);
  motor4.setSpeed(motorSpeed); motor4.run(BACKWARD);
}

void bottomLeft() {
  motor1.setSpeed(0);          motor1.run(RELEASE);
  motor2.setSpeed(motorSpeed); motor2.run(FORWARD);
  motor3.setSpeed(0);          motor3.run(RELEASE);
  motor4.setSpeed(motorSpeed); motor4.run(FORWARD);
}

void bottomRight() {
  motor1.setSpeed(motorSpeed); motor1.run(BACKWARD);
  motor2.setSpeed(0);          motor2.run(RELEASE);
  motor3.setSpeed(motorSpeed); motor3.run(BACKWARD);
  motor4.setSpeed(0);          motor4.run(RELEASE);
}

void stopRobot() {
  motor1.setSpeed(0); motor1.run(RELEASE);
  motor2.setSpeed(0); motor2.run(RELEASE);
  motor3.setSpeed(0); motor3.run(RELEASE);
  motor4.setSpeed(0); motor4.run(RELEASE);
}
