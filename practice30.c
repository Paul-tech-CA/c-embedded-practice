#include <stdio.h>

void updateValues(int *temperature, int *voltage)
{
    *temperature = 70;
    *voltage = 28; 
}

int main(void)
{
    int temperature = 25;
    int voltage = 24;

    updateValues(&temperature, &voltage);

    printf("Temperature: %d\n", temperature);
    printf("Voltage: %d\n", voltage);

    return 0;
}