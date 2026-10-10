#include "motor.h"

int main(void)
{
    struct Motor motor;

    motor.rpm =0;
    motor.voltage = 24.0f;
    motor.temperature = 50.0f;
    motor.state = MOTOR_READY;

    printMotor(motor);

    startMotor(&motor);

    printMotor(motor);

    motor.voltage = 28.0f;

    checkVoltage(&motor);

    printMotor(motor);

    motor.temperature = 250.0f;

    checkTemperature(&motor);

    printMotor(motor);

    return 0;
}