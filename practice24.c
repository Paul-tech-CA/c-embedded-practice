#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t control = 0b01010110;

    control |= (1u << 0);

    control &= ~(1u << 2);

    control ^= (1u << 6);

    if(control & (1u << 4))
    {
        printf("BIT 4: ON\n");
    }
    else
    {
        printf("BIT 4: OFF\n");
    }

    if(control & (1u << 1))
    {
        printf("BIT 1: ON\n");
    }
    else
    {
        printf("BIT 1: OFF\n");
    }

    printf("FINAL: %u\n", (unsigned)control);

    return 0;
}


//1. SET bit 0
//2. CLEAR bit 2
//3. TOGGLE bit 6
//4. CHECK bit 4 → print ON/OFF
//5. CHECK bit 1 → print ON/OFF
//6. Print final decimal value of control