#include <stdio.h>

struct MotorData
{
    int rpm;
    float voltage;
    int enabled;
};

void printMotor(struct MotorData motor)
{
    printf("RPM: %d\n", motor.rpm);
    printf("Voltage: %.1f\n", motor.voltage);
    printf("Enabled: %d\n", motor.enabled);
}
void updateMotor(struct MotorData *motor)
{
   motor->rpm = 3200;
   motor->voltage = 27.5;
   motor->enabled = 0; 
}

int main(void){
   
    struct MotorData motor;

    motor.rpm = 2200;
    motor.voltage = 24.0;
    motor.enabled = 1;

    printMotor(motor);
    updateMotor(&motor);
    printMotor(motor);

    return 0;
}