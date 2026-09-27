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

bool canDeviceRun(int voltage, bool emergencyStop)
{
    if(isVoltageSafe(voltage) && !emergencyStop)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

void printDeviceStatus(bool canRun)
{
    if(canRun)
    {
        printf("DEVICE RUNNING\n");
    }
    else
    {
        printf("DEVICE STOPPED\n");
    }
}

int main()
{
    int voltage;
    int emergencyInput;

    printf("Enter voltage: ");
    scanf("%d", &voltage);

    printf("Emergency stop (0/1): ");
    scanf("%d", &emergencyInput);

    bool emergencyStop = emergencyInput != 0;

    bool canRun = canDeviceRun(voltage, emergencyStop);

    printDeviceStatus(canRun);

    return 0;
}