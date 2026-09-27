#include <stdbool.h>
#include <stdio.h>

bool isVoltageSafe(int voltage)
{
    if(voltage >= 20 && voltage <= 28)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isTemperatureSafe(int temperature)
{
    if(temperature >= 10 && temperature <= 70)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool canMotorRun(int voltage, int temperature, bool emergencyStop)
{
    if(isVoltageSafe(voltage) && isTemperatureSafe(temperature) && !emergencyStop)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printMotorStatus(bool canRun)
{
    if(canRun)
    {
        printf("MOTOR RUNNING\n");
    }
    else
    {
        printf("MOTOR STOPPED\n");
    }
}

int main(void)
{
    int voltage;
    int temperature;
    int emergencyStopInput;

    printf("Enter voltage: ");
    scanf("%d", &voltage);

    printf("Enter temperature: ");
    scanf("%d", &temperature);

    printf("Enter emergencyStopInput (0/1): ");
    scanf("%d", &emergencyStopInput);

    bool emergencyStop = emergencyStopInput != 0;   
    bool canRun = canMotorRun(voltage, temperature, emergencyStop);

    printMotorStatus(canRun);

    return 0;
}