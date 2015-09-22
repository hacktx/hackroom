// This #include statement was automatically added by the Particle IDE.
#include "HC_SR04/HC_SR04.h"

/*
   I AM JAMBOT.
   I HAVE ONE GOAL.
   TO ROCK 'N' ROLL.
*/

// Wheeeeels
int leftMotor = D0;
int rightMotor = D1;

// Head pivot
// Use the Servo class to set angle at 0-180 degrees reliably.
// Use analogWrite(head_pin, x) to set continuous rotation, where x is small (~0-20).
// These are general servo instructions...do not turn the head past 180 degrees or jambot will be decapitated.
Servo head;
int head_pin = A4;

// All-seeing eyes
int trigger = D2;
int echo = D3;
HC_SR04 rangefinder = HC_SR04(trigger, echo, 3.0, 300.0);

// Do a little setup on start
void setup() {
    pinMode(leftMotor, OUTPUT);
    pinMode(rightMotor, OUTPUT);
    head.attach(head_pin);
}

// Keep on movin'
void loop() {
    move();
}

void move() {
    // Check yo left
    head.write(150);
    double leftDist = getDist();
    delay(200);
    
    // Check yo front-side
    head.write(90);
    double middleDist = getDist();
    delay(200);
    
    // Check yo right
    head.write(30);
    double rightDist = getDist();
    delay(200);
    
    // Look forward when you're walkin'
    head.write(90);
    
    // Turn away from left obstacle
    if (leftDist < 5) {
        digitalWrite(leftMotor, HIGH);
    
    // Turn away from right obstacle
    } else if (rightDist < 5) {
        digitalWrite(rightMotor, HIGH);
    
    // Looks pretty good...
    /// If distance is out of range, it's probably far (> 300) instead of near (< 3).
    } else if (middleDist > 5 || middleDist == -1) {
        digitalWrite(leftMotor, HIGH);
        digitalWrite(leftMotor, HIGH);
    
    // Looks like we should turn, I guess. I don't know, I'm a robot
    } else if (leftDist < rightDist) {
        digitalWrite(leftMotor, HIGH);
    
    } else {
        digitalWrite(rightMotor, HIGH);
    }

    // Move for 2 seconds
    delay(2000);
}

double getDist() {
    // TODO: Maybe do an average of multiple readings to reduce noise.
    return rangefinder.getDistanceInch();
}

/*
// Jambot used to have drumsticks. Not anymore...
void tap_left(int wait) {
    left_servo.write(80);
    delay(wait);
    left_servo.write(60);
    delay(wait);
}

void tap_right(int wait) {
    right_servo.write(80);
    delay(wait);
    right_servo.write(60);
    delay(wait);
}

void sample() {
    tap_left(100);
    tap_left(100);
    tap_left(100);
    tap_right(100);
    
    tap_left(100);
    tap_left(100);
    tap_left(100);
    tap_right(100);
    
    tap_left(100);
    tap_left(100);
    tap_left(100);
    tap_right(100);
    
    tap_left(50);
    tap_right(50);
    tap_left(100);
    tap_right(100);
}
*/