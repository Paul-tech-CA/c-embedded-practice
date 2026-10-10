#include <stdio.h>

enum FanState
{
    FAN_OFF,
    FAN_READY,
    FAN_RUNNING,
    FAN_FAULT
};

struct Fan
{
    int speed;
    float temperature;
    enum FanState state;
};

void printFan(struct Fan fan)
{
    switch (fan.state)
    {
        case FAN_OFF:
            printf("STATE: OFF\n");
            break;

        case FAN_READY:
            printf("STATE: READY\n");
            break;

        case FAN_RUNNING:
            printf("STATE: RUNNING\n");
            break;

        case FAN_FAULT:
            printf("STATUS: FAULT\n");
            break;

        default:
            printf("STATUS: UNKNOWN\n");
    }    

    printf("Speed: %d\n", fan.speed);
    printf("Temperature: %.1f\n", fan.temperature);
}

void startFan(struct Fan *fan)
{
    fan->speed = 1500;
    fan->state = FAN_RUNNING;
}

void checkTemperature(struct Fan *fan)
{
    if (fan->temperature > 70.0)
    {
        fan->speed = 0;
        fan->state = FAN_FAULT;
    }
}

int main(void)
{
    struct Fan fan;
    
    fan.speed = 0;
    fan.temperature = 35.0f;
    fan.state = FAN_READY;

    printFan(fan);

    startFan(&fan);

    printFan(fan);

    fan.temperature = 85.0f;

    checkTemperature(&fan);

    printFan(fan);

    return 0;
}