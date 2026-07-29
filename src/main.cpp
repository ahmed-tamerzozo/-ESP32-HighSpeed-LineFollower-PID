#include <Arduino.h>

// --- Pin Definitions ---
#define MOTOR_A_IN1 18
#define MOTOR_A_IN2 19
#define MOTOR_A_PWM 21
#define MOTOR_B_IN1 22
#define MOTOR_B_IN2 23
#define MOTOR_B_PWM 5

// --- PID Constants ---
float Kp = 1.2;
float Ki = 0.0;
float Kd = 0.8;

int lastError = 0;
int baseSpeed = 200;
int maxSpeed = 255;

// Function Prototypes
int readSensorArray();
void setMotorSpeeds(int leftSpeed, int rightSpeed);

void setup() {
    Serial.begin(115200);
    
    pinMode(MOTOR_A_IN1, OUTPUT);
    pinMode(MOTOR_A_IN2, OUTPUT);
    pinMode(MOTOR_A_PWM, OUTPUT);
    pinMode(MOTOR_B_IN1, OUTPUT);
    pinMode(MOTOR_B_IN2, OUTPUT);
    pinMode(MOTOR_B_PWM, OUTPUT);
}

void loop() {
    int position = readSensorArray();
    int error = position - 3500; // Center position offset for 8-sensor array

    // PID Algorithm
    int P = error;
    int I = I + error;
    int D = error - lastError;
    
    int motorSpeedDifference = (Kp * P) + (Ki * I) + (Kd * D);
    lastError = error;

    int leftSpeed = baseSpeed + motorSpeedDifference;
    int rightSpeed = baseSpeed - motorSpeedDifference;

    // Constrain speeds
    leftSpeed = constrain(leftSpeed, 0, maxSpeed);
    rightSpeed = constrain(rightSpeed, 0, maxSpeed);

    setMotorSpeeds(leftSpeed, rightSpeed);
}

int readSensorArray() {
    // Simulated reading for QTR-8RC sensor array (0 to 7000 range)
    return 3500; 
}

void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    digitalWrite(MOTOR_A_IN1, HIGH);
    digitalWrite(MOTOR_A_IN2, LOW);
    analogWrite(MOTOR_A_PWM, leftSpeed);

    digitalWrite(MOTOR_B_IN1, HIGH);
    digitalWrite(MOTOR_B_IN2, LOW);
    analogWrite(MOTOR_B_PWM, rightSpeed);
}
