#include <stdio.h>
#include "motor.h"
#include <stdbool.h>

void printMotor(struct Motor motor)
{
    switch (motor.state)
    {
        case MOTOR_OFF:
            printf("STATE: OFF\n");
            break;

        case MOTOR_READY:
            printf("STATE: READY\n");
            break;

        case MOTOR_RUNNING:
            printf("STATE: RUNNING\n");
            break;

        case MOTOR_FAULT:
            printf("STATE: FAULT\n");
            break;

        default:
            printf("STATE: UNDEFINED\n");
            break;
    }

    printf("RPM: %d\n", motor.rpm);
    printf("Voltage: %.1f\n", motor.voltage);
    printf("Temperature: %.1f\n", motor.temperature);
}

void startMotor(struct Motor *motor)
{
    motor->rpm = 2000;
    motor->state = MOTOR_RUNNING;
}

bool isVoltageSafe(const struct Motor *motor)
{
    return motor->voltage >= 20.0f && motor->voltage <= 28.0f;
    //if (motor->voltage >= 20.0f && motor->voltage <= 28.0f)
    //{
    //    return true;
    //}
    //else
    //{
    //    return false;
    //}
}

bool isTemperatureSafe(const struct Motor *motor)
{
    return motor->temperature >= -22.0f && motor->temperature <= 212.0f;
    //if (motor->temperature >= -22.0f && motor->temperature <= 212.0f)
    //{
    //    return true;
    //}
    //else
    //{
    //    return false;
    //}
}

void updateSafety(struct Motor *motor)
{
    if (!isTemperatureSafe(motor) || !isVoltageSafe(motor))
    {
        motor->rpm = 0;
        motor->state = MOTOR_FAULT;
    }
}