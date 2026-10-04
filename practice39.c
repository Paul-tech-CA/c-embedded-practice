#include <stdio.h>

struct MotorData
{
    int rpm;
    float voltage;
    int enabled;
};

void printMotorStatus(struct MotorData motor)
{
    printf("RPM: %d\n", motor.rpm);
    printf("Voltage: %.1f\n", motor.voltage);
    printf("Enabled: %d\n", motor.enabled);
}

int main(void)
{
    struct MotorData motor;

    motor.rpm = 2500;
    motor.voltage = 24.5;
    motor.enabled = 1;

    printMotorStatus(motor);

    return 0;
}