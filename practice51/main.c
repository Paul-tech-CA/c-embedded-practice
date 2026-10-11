#include "motor.h"

int main(void)
{
    struct Motor motor;

    //TEST 1: everything is SAFE
    motor.rpm =0;
    motor.voltage = 24.0f;
    motor.temperature = 50.0f;
    motor.state = MOTOR_READY;

    startMotor(&motor);
    updateSafety(&motor);
    printMotor(motor);

    //TEST 2: voltage is HIGH
    motor.rpm = 0;
    motor.voltage = 30.0f;
    motor.temperature = 50.0f;
    motor.state = MOTOR_READY;

    startMotor(&motor);
    updateSafety(&motor);
    printMotor(motor);

    //TEST 3: temperature is HIGH
    motor.rpm = 0;
    motor.voltage = 24.0f;
    motor.temperature = 250.0f;
    motor.state = MOTOR_READY;

    startMotor(&motor);
    updateSafety(&motor);
    printMotor(motor);

     //TEST 4: voltage is LOW
    motor.rpm = 0;
    motor.voltage = 15.0f;
    motor.temperature = 50.0f;
    motor.state = MOTOR_READY;

    startMotor(&motor);
    updateSafety(&motor);
    printMotor(motor);

     //TEST 5: temperature is LOW
    motor.rpm = 0;
    motor.voltage = 24.0f;
    motor.temperature = -30.0f;
    motor.state = MOTOR_READY;

    startMotor(&motor);
    updateSafety(&motor);
    printMotor(motor);

      //TEST 6: temperature is HIGH and voltage is HIGH
    motor.rpm = 0;
    motor.voltage = 35.0f;
    motor.temperature = 230.0f;
    motor.state = MOTOR_READY;

    startMotor(&motor);
    updateSafety(&motor);
    printMotor(motor);

    return 0;
}