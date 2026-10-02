#include <stdio.h>
#include <stdint.h>



int main(void)
{
    uint8_t status = 0b00000000;

    status |= (1u << 0);
    status |= (1u << 1);
    status |= (1u << 2);

    if (status & (1u << 2))
    {
        status |= (1u << 3);
        status &= ~(1u << 1);
    }

    printf("Final status: %u\n", (unsigned)status);

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
        printf("FAN: ON\n");
    }
    else
    {
        printf("FAN: OFF\n");
    }

    if (status & (1u << 2))
    {
        printf("OVER_TEMP: ON\n");
    }
    else
    {
        printf("OVER_TEMP: OFF\n");
    }

    if (status & (1u << 3))
    {
        printf("ERROR: ON\n");
    }
    else
    {
        printf("ERROR: OFF\n");
    }

    return 0;
}