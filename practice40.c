#include <stdio.h>

struct MotorData
{
    int rpm;
    float voltage;
    int enabled;
};

void changeByValue(struct MotorData motor)
{
    motor.rpm = 3000;
}

void changeByPointer(struct MotorData *motor)
{
    //(*motor).rpm = 4000;
    motor->rpm = 4000;
}

int main(void)
{
    struct MotorData motor;

    motor.rpm = 2500;
    motor.voltage = 24.5;
    motor.enabled = 1;

    printf("START: %d\n", motor.rpm);

    changeByValue(motor);
    printf("AFTER BY VALUE: %d\n", motor.rpm);

    changeByPointer(&motor);
    printf("AFTER BY POINTER: %d\n", motor.rpm);

    return 0;
}