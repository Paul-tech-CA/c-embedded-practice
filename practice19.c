#include <stdio.h>

float values[8] = {14.5f, 9.2f, 21.0f, 7.8f, 21.0f, 18.4f, 6.5f, 19.9f};

int main(void)
{
    float max = values[0];
    int maxIndex = 0;

    float min = values[0];
    int minIndex = 0;

    float sum = 0.0f;

    int count = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < count; i++)
    {
        if(values[i] > max)
        {
            max = values[i];
            maxIndex = i;
        }
        if(values[i] < min)
        {
            min = values[i];
            minIndex = i;
        }

        sum += values[i];    
    }   
    
    float average = sum / count;

    printf("MAX: %.1f\n", max);
    printf("MAX INDEX: %d\n", maxIndex);
    printf("MIN: %.1f\n", min);
    printf("MIN INDEX: %d\n", minIndex);
    printf("SUM: %.1f\n", sum);
    printf("AVERAGE: %.1f\n", average);

    return 0;
}