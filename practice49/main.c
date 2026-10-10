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

    //TEST 2: voltage is UNSAFE
    motor.rpm = 0;
    motor.voltage = 30.0f;
    motor.temperature = 50.0f;
    motor.state = MOTOR_READY;

    startMotor(&motor);
    updateSafety(&motor);
    printMotor(motor);

    //TEST 3: temperature is UNSAFE
    motor.rpm = 0;
    motor.voltage = 24.0f;
    motor.temperature = 250.0f;
    motor.state = MOTOR_READY;

    startMotor(&motor);
    updateSafety(&motor);
    printMotor(motor);

    return 0;
}