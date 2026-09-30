#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t status = 0b00100100;
    
    printf("1. decimal value: %u\n", (unsigned)status);

    status |= (1u << 3);
    printf("2. SET bit 3: %u\n", (unsigned)status);

    status &= ~(1u << 2);
    printf("4. CLEAR bit 2: %u\n", (unsigned)status);

    status ^= (1u << 5);
    printf("6. TOGGLE bit 5: %u\n", (unsigned)status);

    if(status & (1u << 3))
    {
        printf("BIT 3: ON\n");
    }
    else
    {
        printf("BIT 3: OFF\n");
    }
    
    if(status & (1u << 2))
    {
        printf("BIT 2: ON\n");
    }
    else
    {
        printf("BIT 2: OFF\n");
    }

    return 0;
}


//1. Надрукуй початкове decimal value status.
//2. Set bit 3.
//3. Надрукуй status.
//4. Clear bit 2.
//5. Надрукуй status.
//6. Toggle bit 5.
//7. Надрукуй status.
//8. Check bit 3 → BIT 3: ON/OFF.
//9. Check bit 2 → BIT 2: ON/OFF.S