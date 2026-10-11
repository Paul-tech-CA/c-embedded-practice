#include <stdio.h>
#include "motor.h"

const char *motorStateToString(enum MotorState state)
{
    switch (state)
    {
        case MOTOR_OFF:
            return "OFF";

        case MOTOR_READY:
            return "READY";

        case MOTOR_RUNNING:
            return "RUNNING";

        case MOTOR_FAULT:
            return "FAULT";

        default:
            return "UNDEFINED";
    }
}

const char *motorFaultToString(enum MotorFault fault)
{
    switch (fault)
    {
    case FAULT_NONE:
        return "NONE";

     case FAULT_VOLTAGE_LOW:
        return "VOLTAGE LOW";

    case FAULT_VOLTAGE_HIGH:
        return "VOLTAGE HIGH";

    case FAULT_TEMPERATURE_LOW:
        return "TEMPERATURE LOW";

    case FAULT_TEMPERATURE_HIGH:
        return "TEMPERATURE HIGH";
    
    default:
        return "UNKNOWN";
    }
}

void printMotor(struct Motor motor)
{    
    printf("STATE: %s\n", motorStateToString(motor.state));
    printf("FAULT: %s\n", motorFaultToString(motor.fault));
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