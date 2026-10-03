#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t status = 0;

    int temperature = 82;
    int systemEnabled = 1;
    int emergencyStop = 0;

    if (systemEnabled)
    {
        status |= (1u << 0);
    }

    if (temperature > 70)
    {
        status |= (1u << 1);
    }

    if (emergencyStop)
    {
        status |= (1u << 2);
    }

    if ((status & (1u << 1)) || (status & (1u << 2)))
    {
        status |= (1u << 3);
    }

    if (status & (1u << 0))
    {
        printf("SYSTEM: ON\n");
    }
    else
    {
        printf("SYSTEM: OFF\n");
    }

    if (status & (1u << 1))
    {
        printf("OVER_TEMP: ON\n");
    }
    else
    {
        printf("OVER_TEMP: OFF\n");
    }

    if (status & (1u << 2))
    {
        printf("EMERGENCY: ON\n");
    }
    else
    {
        printf("EMERGENCY: OFF\n");
    }

    if (status & (1u << 3))
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