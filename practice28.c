#include <stdio.h>

int main(void)
{
    int number = 42;

    int *ptr = &number;

    printf("Number: %d\n", number);
    printf("Through pointer: %d\n", *ptr);

    *ptr = 100;

    printf("Number2: %d\n", number);

    printf("Adress: %p\n", (void *)ptr);

    return 0;
}

