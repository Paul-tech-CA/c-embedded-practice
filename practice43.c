#include <stdio.h>

enum MotorState
{
    MOTOR_OFF,
    MOTOR_READY,
    MOTOR_RUNNING,
    MOTOR_FAULT
};

int main(void)
{
    enum MotorState state = MOTOR_READY;

    if (state == MOTOR_READY)
    {
        printf("Motor ready\n");
    }

    state = MOTOR_RUNNING;

    if (state == MOTOR_RUNNING)
    {
        printf("Motor running\n");
    }

    return 0;
}