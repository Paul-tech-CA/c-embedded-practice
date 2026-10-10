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
            printf("STATE: UNKNOWN\n");
    }

    printf("RPM: %d\n", motor.rpm);
    printf("Voltage: %.1f\n", motor.voltage);
}

void startMotor(struct Motor *motor)
{
    motor->rpm = 2200;
    motor->state = MOTOR_RUNNING;
}


int main(void)
{
    struct Motor motor;

    motor.rpm = 0;
    motor.voltage = 24.0f;
    motor.state = MOTOR_READY;

    printMotor(motor);

    startMotor(&motor);

    printMotor(motor);

    return 0;
}