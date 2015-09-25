// This #include statement was automatically added by the Particle IDE.
#include "HC_SR04.h"

SYSTEM_MODE(SEMI_AUTOMATIC);

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
HC_SR04 rangefinder = HC_SR04(trigger, echo);

//thresh
double thresh = 3.0;

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
    delay(300);
    double L = getDist();
    
    // Check yo right
    head.write(30);
    delay(600);
    double R = getDist();

    // Check yo front-side
    head.write(90);
    delay(300);
    double F = getDist();

    if (F > 15.0 || (L + thresh < F && R + thresh < F)) {
        digitalWrite(leftMotor, HIGH);
        digitalWrite(rightMotor, HIGH);
        delay(2000);
    } else if (L > F + thresh) {
        digitalWrite(leftMotor, HIGH);
        delay(500);

    } else {
        digitalWrite(rightMotor, HIGH);
        delay(500);
    }

    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, LOW);
}

void move_simple() {
    // Check yo front-side
    head.write(90);
    delay(200);
    double middleDist = getDist();

    if (middleDist > 15) {
        digitalWrite(leftMotor, HIGH);
        digitalWrite(rightMotor, HIGH);
    
    } else {
        digitalWrite(rightMotor, HIGH);
    }

    // Move for 1.5 seconds
    delay(1500);
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, LOW);
}

double getDist() {
    // TODO: Maybe do an average of multiple readings to reduce noise.
    return rangefinder.getDistanceCM();
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