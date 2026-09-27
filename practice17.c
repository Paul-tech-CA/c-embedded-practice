#include <stdbool.h>
#include <stdio.h>

float temperatures[8] = {21.5f, 35.2f, 71.8f, 68.0f, 10.5f, 75.3f, 9.5f, 70.0f};

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
   int safeCount = 0;
   int unsafeCount = 0;

   for (int i = 0; i < 8; i++)
   {
        if(isTemperatureSafe(temperatures[i]))
        {
            safeCount++;
        }
        else
        {
            unsafeCount++;
        }
   }
    printf("SAFE: %d\n", safeCount);
    printf("UNSAFE: %d\n", unsafeCount);
    return 0;   
}