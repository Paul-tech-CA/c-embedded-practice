#include <stdio.h>

enum MotorState
{
    MOTOR_OFF,
    MOTOR_READY,
    MOTOR_RUNNING,
    MOTOR_FAULT
};

struct Motor
{
    int rpm;
    float voltage;
    enum MotorState state;
};

void printMotor(struct Motor motor)
{
    switch (motor.state)
    {
        case MOTOR_OFF:
            printf("STATUS: OFF\n");
            break;

        case MOTOR_READY:
            printf("STATUS: READY\n");
            break;

        case MOTOR_RUNNING:
            printf("STATUS: RUNNING\n");
            break;

        case MOTOR_FAULT:
            printf("STATUS: FAULT\n");
            break;

        default:
            printf("STATUS: UNKNOWN\n");
            break;
    }

    printf("RPM: %d\n", motor.rpm);
    printf("Voltage: %.1f\n", motor.voltage);
}

void runMotor(struct Motor *motor)
{
    motor->rpm = 2000;
    motor->state = MOTOR_RUNNING;
}

void checkVoltage(struct Motor *motor)
{
    if (motor->voltage < 20.0 || motor->voltage > 28.0)
    {
        motor->rpm = 0;
        motor->state = MOTOR_FAULT;
    }
}

int main(void)
{
    struct Motor motor;

    motor.rpm = 0;
    motor.voltage = 24.0f;
    motor.state = MOTOR_READY;

    printMotor(motor);

    runMotor(&motor);

    printMotor(motor);

    motor.voltage = 30.0f;

    checkVoltage(&motor);

    printMotor(motor);

    return 0;
}