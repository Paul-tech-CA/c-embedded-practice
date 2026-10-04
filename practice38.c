#include <stdio.h>

struct SensorData
{
    float temperature;
    float voltage;
    int sensorEnabled;
};

int main(void)
{
    struct SensorData sensor;
    sensor.temperature = 72.5f;
    sensor.voltage = 24.8f;
    sensor.sensorEnabled = 1;

    printf("Temperature: %.1f\n", sensor.temperature);
    printf("Voltage: %.1f\n", sensor.voltage);
    printf("Sensor enable: %d\n", sensor.sensorEnabled);

    return 0;
}