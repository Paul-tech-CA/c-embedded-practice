#include <stdio.h>

float voltage[6] = {24.5f, 21.0f, 27.8f, 19.5f, 25.2f, 28.0f};

int main(void)
{
    float min = voltage[0];
    int minIndex = 0;

    float max = voltage[0];
    int maxIndex = 0;

    int count = sizeof(voltage) / sizeof(voltage[0]);
    float sum = 0.0f;

    for (int i = 0; i < count; i++)
    {
        if(voltage[i] < min)
        {
            min = voltage[i];
            minIndex = i;
        }
        if(voltage[i] > max)
        {
            max = voltage[i];
            maxIndex = i;
        }
        sum += voltage[i];
    }
    float average = sum / count;

    printf("MIN: %.1f\n", min);
    printf("MIN INDEX: %d\n", minIndex);
    printf("MAX: %.1f\n", max);
    printf("MAX INDEX: %d\n", maxIndex);
    printf("AVERAGE: %.1f\n", average);

    return 0;
}