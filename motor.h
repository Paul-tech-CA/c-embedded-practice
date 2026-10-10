#ifndef MOTOR_H
#define MOTOR_H

enum MotorState
{
    MOTOR_OFF,
    MOTOR_READY,
    MOTOR_RUNNING,
    MOTOR_FAULT
};

struct Motor
{
    int rpm;
    float voltage;
    float temperature;
    enum MotorState state;
};

void printMotor(struct Motor motor);
void startMotor(struct Motor *motor);
void checkVoltage(struct Motor *motor);
void checkTemperature(struct Motor *motor);

#endif