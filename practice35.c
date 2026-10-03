#include <stdio.h>
#include <stdint.h>

#define SYSTEM_ON_MASK (1u << 0)
#define OVER_TEMP_MASK (1u << 1)
#define EMERGENCY_MASK (1u << 2)
#define ALARM_MASK (1u << 3)

int main(void)
{
    uint8_t status = 0;

    int temperature = 82;
    int systemEnabled = 1;
    int emergencyStop = 0;

    if (systemEnabled)
    {
        status |= SYSTEM_ON_MASK;
    }

    if (temperature > 70)
    {
        status |= OVER_TEMP_MASK;
    }

    if (emergencyStop)
    {
        status |= EMERGENCY_MASK;
    }

    if ((status & OVER_TEMP_MASK) || (status & EMERGENCY_MASK))
    {
        status |= ALARM_MASK;
    }

    if (status & SYSTEM_ON_MASK)
    {
        printf("SYSTEM: ON\n");
    }
    else
    {
        printf("SYSTEM: OFF\n");
    }

    if (status & OVER_TEMP_MASK)
    {
        printf("OVER_TEMP: ON\n");
    }
    else
    {
        printf("OVER_TEMP: OFF\n");
    }

    if (status & EMERGENCY_MASK)
    {
        printf("EMERGENCY: ON\n");
    }
    else
    {
        printf("EMERGENCY: OFF\n");
    }

    if (status & ALARM_MASK)
    {
        printf("ALARM: ON\n");
    }
    else
    {
        printf("ALARM: OFF\n");
    }

    printf("FINAL STATUS: %u\n", (unsigned)status);
    return 0;
}