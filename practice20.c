#include <stdio.h>
#include <stdbool.h>

float temperatures[10] = {
    21.5f, 72.0f, 18.0f, 69.5f, 75.0f,
    10.0f, 8.5f, 55.0f, 70.0f, 80.0f
};

bool isTemperatureSafe(float temperature)
{
    if(temperature >= 10.0 && temperature <= 70.0)
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
    int count = sizeof(temperatures) / sizeof(temperatures[0]);
    int safe = 0;
    int unsafe = 0; 
    float max = temperatures[0];
    float min = temperatures[0];
    float sum = 0.0f;

    for (int i = 0; i < count; i++)
    {
        if(temperatures[i] > max)
        {
            max = temperatures[i];
        }
        if(temperatures[i] < min)
        {
            min = temperatures[i];
        }
        if(isTemperatureSafe(temperatures[i]))
        {
            safe++;
        }
        else
        {
            unsafe++;
        }
        sum += temperatures[i];
    }
    
    float average = sum / count;
    
    printf("SAFE: %d\n", safe);
    printf("UNSAFE: %d\n", unsafe);
    printf("MAX: %.1f\n", max);
    printf("MIN: %.1f\n", min);
    printf("AVERAGE: %.1f\n", average);

    return 0;
}