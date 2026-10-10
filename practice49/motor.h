#ifndef MOTOR_H
#define MOTOR_H
#include <stdbool.h>

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
bool isVoltageSafe(const struct Motor *motor);
bool isTemperatureSafe(const struct Motor *motor);
void updateSafety(struct Motor *motor);

#endif