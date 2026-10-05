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
    enum MotorState state = MOTOR_FAULT;

    switch (state)
    {
        case MOTOR_OFF:
            printf("Motor off\n");
            break;

        case MOTOR_READY:
            printf("Motor ready\n");
            break;

        case MOTOR_RUNNING:
            printf("Motor running\n");
            break;

        case MOTOR_FAULT:
            printf("Motor fault\n");
            break;
    }

    return 0;
}