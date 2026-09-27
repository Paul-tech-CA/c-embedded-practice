#include <stdio.h>
#include <stdbool.h>

float voltages[10] = {24.0f, 18.5f, 27.2f, 30.0f, 20.0f, 28.0f, 19.9f, 25.5f, 29.1f, 21.0f};

bool isVoltageSafe(float voltage){
    if (voltage >= 20.0f && voltage <= 28.0f)
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
    for (int i = 0; i < 10; i++)
    {
        if(isVoltageSafe(voltages[i]))
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