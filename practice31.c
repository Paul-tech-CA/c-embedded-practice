#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t control = 0b00100100;

    control |= (1u << 1);
    printf("After SET: %u\n", (unsigned)control);

    control &= ~(1u << 5);
    printf("After CLEAR: %u\n", (unsigned)control);

    control ^= (1u << 2);
    printf("After TOGGLE: %u\n", (unsigned)control);

    if (control & (1u << 4))
    {
        printf("BIT 4: ON\n");
    }
    else
    {
        printf("BIT 4: OFF\n");
    }

    return 0;
}