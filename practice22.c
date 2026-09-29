#include <stdio.h>
#include <stdint.h>

uint8_t reg = 0;

int main(void)
{
    reg |= (1u << 2);
    printf("1: %u\n", (unsigned)reg);

    reg |= (1u << 5);
    printf("2: %u\n", (unsigned)reg);
    
    reg &= ~(1u << 2);
    printf("3: %u\n", (unsigned)reg);

    reg ^= (1u << 5);
    printf("4: %u\n", (unsigned)reg);

    return 0;
}
