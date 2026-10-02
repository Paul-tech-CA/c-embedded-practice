#include <stdint.h>
#include <stdio.h>

int main(void)
{
    uint8_t control = 0u;

    int temperature = 78;
    int systemEnabled = 1;
    int emergencyStop = 1;

    if (systemEnabled == 1)
    {
        control |= (1u << 0);
    }

    if (temperature > 70)
    {
        control |= (1u << 2);
        control |= (1u << 1);
    }  

    if (emergencyStop == 1)
    {
        control |= (1u << 3);
        control |= (1u << 4);
        control &= ~(1u << 0);
        control &= ~(1u << 1);        
    }

    if ((control & (1u << 2)) && !(control & (1u << 1)))
    {
        control |= (1u << 4);
    }

    printf("Final control: %u\n", (unsigned)control);
    
    if (control & (1u << 0)) 
    {
        printf("SYSTEM: ON\n");
    }
    else
    {
        printf("SYSTEM: OFF\n");
    }

    if (control & (1u << 1))
    {
        printf("FAN: ON\n");
    }
    else
    {
        printf("FAN: OFF\n");
    }

    if (control & (1u << 2))
    {
        printf("OVER_TEMP: ON\n");   
    }
    else
    {
        printf("OVER_TEMP: OFF\n");
    }

    if (control & (1u << 3))
    {
        printf("EMERGENCY: ON\n");
    }
    else
    {
        printf("EMERGENCY: OFF\n");
    }

    if (control & (1u << 4))
    {
        printf("ALARM: ON\n");
    }
    else
    {
        printf("ALARM: OFF\n");
    }

    return 0;
}