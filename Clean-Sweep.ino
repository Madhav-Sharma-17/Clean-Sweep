#include <Arduino.h>
#include <Ultrasonic.h>

// Define motor pins
#define IN1 26
#define IN2 27
#define IN3 14
#define IN4 12
#define ENA 25
#define ENB 33

// Define ultrasonic sensor pins
#define TRIG1 2
#define ECHO1 4
#define TRIG2 5
#define ECHO2 18
#define TRIG3 19
#define ECHO3 21
#define TRIG4 22
#define ECHO4 23

// Define relay module pins
#define VACUUM_RELAY 15
#define PUMP_RELAY 32

// Define motor speed
#define SPEED 200

Ultrasonic sensor1(TRIG1, ECHO1);
Ultrasonic sensor2(TRIG2, ECHO2);
Ultrasonic sensor3(TRIG3, ECHO3);
Ultrasonic sensor4(TRIG4, ECHO4);

void setup() {
    Serial.begin(115200);
    
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    
    pinMode(VACUUM_RELAY, OUTPUT);
    pinMode(PUMP_RELAY, OUTPUT);
    
    digitalWrite(VACUUM_RELAY, LOW);
    digitalWrite(PUMP_RELAY, LOW);
}

void moveForward() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, SPEED);
    analogWrite(ENB, SPEED);
}

void moveBackward() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, SPEED);
    analogWrite(ENB, SPEED);
}

void stopMovement() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

void turnLeft() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void turnRight() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void loop() {
    int distance1 = sensor1.read();
    int distance2 = sensor2.read();
    int distance3 = sensor3.read();
    int distance4 = sensor4.read();

    Serial.print("Distances: ");
    Serial.print(distance1); Serial.print(" ");
    Serial.print(distance2); Serial.print(" ");
    Serial.print(distance3); Serial.print(" ");
    Serial.println(distance4);
    
    if (distance1 < 20 || distance2 < 20) {
        stopMovement();
        delay(500);
        moveBackward();
        delay(500);
        turnRight();
        delay(500);
    } else {
        moveForward();
    }

    digitalWrite(VACUUM_RELAY, HIGH);
    digitalWrite(PUMP_RELAY, HIGH);
    delay(1000);
}