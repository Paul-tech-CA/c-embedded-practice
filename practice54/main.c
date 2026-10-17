#include <stdio.h>
#include "motor.h"

int main(void)
{
    struct Motor motor;

    //TEST 1: 
    motor.rpm = 0;
    motor.voltage = 24.0f;
    motor.temperature = 50.0f;
    motor.faultFlags = 0;
    motor.state = MOTOR_READY;

    if (startMotor(&motor))
    {
      printf("Motor started successfully\n");
    }
    else
    {
      printf("Motor start blocked\n");
    }

    printMotor(motor);

    motor.voltage = 35.0f;

    updateSafety(&motor);
    printMotor(motor);

      if (resetFaults(&motor))
    {
      printf("Fault reset successful\n");
    }
    else
    {
      printf("Fault reset blocked\n");
    }

    printMotor(motor);

    motor.voltage = 24.0f;

    updateSafety(&motor);
    printMotor(motor);

    if (resetFaults(&motor))
    {
      printf("Fault reset successful\n");
    }
    else
    {
      printf("Fault reset blocked\n");
    }

    printMotor(motor);

    if (startMotor(&motor))
    {
      printf("Motor started successfully\n");
    }
    else
    {
      printf("Motor start blocked\n");
    }

    printMotor(motor);
    
    return 0;
}