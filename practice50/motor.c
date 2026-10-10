#include <stdio.h>
#include "motor.h"

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

    switch (motor.fault)
    {
    case FAULT_NONE:
        printf("FAULT: NONE\n");
        break;

     case FAULT_VOLTAGE_LOW:
        printf("FAULT: VOLTAGE LOW\n");
        break;

    case FAULT_VOLTAGE_HIGH:
        printf("FAULT: VOLTAGE HIGH\n");
        break;

    case FAULT_TEMPERATURE_LOW:
        printf("FAULT: TEMPERATURE LOW\n");
        break;

    case FAULT_TEMPERATURE_HIGH:
        printf("FAULT: TEMPERATURE HIGH\n");
        break;
    
    default:
        printf("FAULT: UNKNOWN\n");
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
    motor->fault = FAULT_NONE;
}

enum MotorFault detectFault(const struct Motor *motor)
{
     if (motor->voltage < 20.0f)
    {
        return FAULT_VOLTAGE_LOW;
    }

    if (motor->voltage > 28.0f)
    {
        return FAULT_VOLTAGE_HIGH;
    }

    if (motor->temperature < -22.0f)
    {
        return FAULT_TEMPERATURE_LOW;
    }
    
     if (motor->temperature > 212.0f)
    {
        return FAULT_TEMPERATURE_HIGH;
    }

    return FAULT_NONE;
}

void updateSafety(struct Motor *motor)
{
    motor->fault = detectFault(motor);

    if (motor->fault != FAULT_NONE)
    {
        motor->rpm = 0;
        motor->state = MOTOR_FAULT;
    }    
}