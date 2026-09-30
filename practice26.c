#include <stdio.h>

float findMax(float values[], int count)
{
    float max = values[0];

    for (int i = 0; i < count; i++)
    {
        if(values[i] > max)
        {
            max = values[i];
        }
    }
    return max;
}

int main(void)
{
    float values[6] = {12.5f, 31.0f, 7.8f, 44.2f, 19.0f, 40.5f};

    int count = sizeof(values) / sizeof(values[0]);
    
    float maximal = findMax(values, count);
    
    printf("MAX: %.1f\n", maximal);
    
    return 0;
}