#include <stdio.h>

float findMin(float values[], int count)
{
    float min = values[0];
    
    for (int i = 1; i < count; i++)
    {
        if(values[i] < min)
        {
            min = values[i];
        }
    }
    return min;
}

float calculateAverage(float values[], int count)
{
    float sum = 0.0f;

    for (int i = 0; i < count; i++)
    {
        sum += values[i];
    }

    float average = sum / count;
    return average;
}

int main(void)
{
    float values[7] = {18.5f, 42.0f, 11.2f, 37.5f, 9.8f, 26.0f, 33.3f};

    int count = sizeof(values) / sizeof(values[0]);

    float minimal = findMin(values, count);

    float average = calculateAverage(values, count);

    printf("MIN: %.1f\n", minimal);
    printf("AVERAGE: %.1f\n", average);

    return 0;
}