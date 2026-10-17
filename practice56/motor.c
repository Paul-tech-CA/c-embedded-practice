#include <stdio.h>
#include "motor.h"

static const char *motorStateToString(enum MotorState state)
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

static uint8_t detectFaults(const struct Motor *motor)
{
    uint8_t faults = 0;
    if (motor->voltage < 20.0f)
    {
        faults |= FAULT_VOLTAGE_LOW_MASK;
    }
    if (motor->voltage > 28.0f)
    {
        faults |= FAULT_VOLTAGE_HIGH_MASK;
    }
    if (motor->temperature < -22.0f)
    {
        faults |= FAULT_TEMPERATURE_LOW_MASK;
    }
    if (motor->temperature > 212.0f)
    {
        faults |= FAULT_TEMPERATURE_HIGH_MASK;
    }

    return faults;
}

static void printFaults(uint8_t faultFlags)
{
    if (faultFlags == 0)
    {
        printf("FAULT: NONE\n");
        return;
    }

    if (faultFlags & FAULT_VOLTAGE_LOW_MASK)
    {
        printf("FAULT: VOLTAGE LOW\n");
    }

    if (faultFlags & FAULT_VOLTAGE_HIGH_MASK)
    {
        printf("FAULT: VOLTAGE HIGH\n");
    }

    if (faultFlags & FAULT_TEMPERATURE_LOW_MASK)
    {
        printf("FAULT: TEMPERATURE LOW\n");
    }

    if (faultFlags & FAULT_TEMPERATURE_HIGH_MASK)
    {
        printf("FAULT: TEMPERATURE HIGH\n");
    }
}

void printMotor(struct Motor motor)
{    
    printf("STATE: %s\n", motorStateToString(motor.state));

    printFaults(motor.faultFlags);

    printf("RPM: %d\n", motor.rpm);
    printf("Voltage: %.1f\n", motor.voltage);
    printf("Temperature: %.1f\n", motor.temperature);
}

bool startMotor(struct Motor *motor)
{
    motor->faultFlags |= detectFaults(motor);

    if (motor->faultFlags != 0)
    {
        motor->rpm = 0;
        motor->state = MOTOR_FAULT;
        return false;
    }
        motor->rpm = 2000;
        motor->state = MOTOR_RUNNING;
        return true;
}

void updateSafety(struct Motor *motor)
{
    motor->faultFlags |= detectFaults(motor);

    if (motor->faultFlags != 0)
    {
        motor->rpm = 0;
        motor->state = MOTOR_FAULT;
    }    
}

bool resetFaults(struct Motor *motor)
{
    uint8_t currentFaults = detectFaults(motor);

    if (currentFaults != 0)
    {
        return false;
    }
    
    motor->faultFlags = 0;
    motor->state = MOTOR_READY;
    motor->rpm = 0;

    return true;
}

void initMotor(struct Motor *motor, float voltage, float temperature)
{
    motor->rpm = 0;
    motor->voltage = voltage;
    motor->temperature = temperature;
    motor->state = MOTOR_READY;
    motor->faultFlags = 0;
}