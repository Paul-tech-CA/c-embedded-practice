#include <stdio.h>

void setTemperature(int *ptr)
{
    *ptr = 70;
}

int main(void)
{
    int temperature = 25;
    printf("Temperature: %d\n", temperature);

    setTemperature(&temperature);
    
    printf("New temperature: %d\n", temperature);

    return 0;
}