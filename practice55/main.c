#include <stdio.h>
#include "motor.h"

int main(void)
{
    struct Motor motor;

    //Initialize motor 
    initMotor(&motor, 24.0f, 50.0f);

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