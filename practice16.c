#include <stdio.h>
#include <stdbool.h>

float temperatures[6] = {21.5f, 32.5f, 71.8f, 68.0f, 10.5f, 75.3f};

bool isTemperatureSafe(float temperature)
{
    if(temperature >= 10.0f && temperature <= 70.0f)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

int main(void)
{
    for (int i = 0; i < 6; i++)
    {
        if(isTemperatureSafe(temperatures[i]))
        {
            printf("%.1f SAFE\n", temperatures[i]);
        }
        else 
        {
            printf("%.1f UNSAFE\n", temperatures[i]);
        }
    }
    return 0;
}