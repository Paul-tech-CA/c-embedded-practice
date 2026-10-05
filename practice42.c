#include <stdio.h>

struct DeviceData
{
    int temperature;
    float voltage;
    int enabled;
};

void printDevice(struct DeviceData device)
{
    printf("Temperature: %d\n", device.temperature);
    printf("Voltage: %.1f\n", device.voltage);
    printf("Enabled: %d\n", device.enabled);
}

void updateDevice(struct DeviceData *device)
{
    device->temperature = 75;
    device->voltage = 27.5f;
    device->enabled = 0;
}

int main(void)
{
    struct DeviceData device;

    device.temperature = 25;
    device.voltage = 24.0;
    device.enabled = 1;

    printDevice(device);
    updateDevice(&device);
    printDevice(device);

    return 0;
}