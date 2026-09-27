#include <stdbool.h>
#include <stdio.h>

bool isTemperatureHeigh(int temperature)
{
    if(temperature >= 70)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool shouldFanRun(int temperature, bool fanEnabled)
{
    if(isTemperatureHeigh(temperature) && fanEnabled)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printFanStatus(bool fanRunning)
{
    if(fanRunning)
    {
        printf("FAN RUNNING\n");
    }
    else
    {
        printf("FAN STOPPED\n");
    }
}

int main()
{
    int temperature;
    int fanEnabledInput;

    printf("Enter temperature: ");
    scanf("%d", &temperature);

    printf("Is fanEnabled (0/1): ");
    scanf("%d", &fanEnabledInput);

    bool fanEnabled = fanEnabledInput != 0;
    bool fanRunning = shouldFanRun(temperature, fanEnabled);

    printFanStatus(fanRunning);

    return 0;
}