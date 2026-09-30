#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t flags = 0b10100110;

    if(flags & (1u << 7))
    {
        printf("BIT 7: ON\n");
    }
    else
    {
        printf("BIT 7: OFF\n");
    }

    flags |= (1u << 4);
    flags &= ~(1u << 2);
    flags ^= (1u << 1);
    
    if(flags & (1u << 1))
    {
        printf("BIT 1: ON\n");
    }
    else
    {
        printf("BIT 1: OFF\n");
    }

    if(flags & (1u << 2))
    {
        printf("BIT 2: ON\n");
    }
    else
    {
        printf("BIT 2: OFF\n");
    }

    printf("FINAL: %u\n", (unsigned)flags);

    return 0;
}


//1. CHECK bit 7 → ON/OFF
//2. SET bit 4
//3. CLEAR bit 2
//4. TOGGLE bit 1
//5. CHECK bit 1 → ON/OFF
//6. CHECK bit 2 → ON/OFF
//7. Print final decimal value