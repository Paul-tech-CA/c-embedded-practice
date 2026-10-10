#ifndef MOTOR_H
#define MOTOR_H

enum MotorState
{
    MOTOR_OFF,
    MOTOR_READY,
    MOTOR_RUNNING,
    MOTOR_FAULT
};

enum MotorFault
{
    FAULT_NONE,
    FAULT_VOLTAGE_LOW,
    FAULT_VOLTAGE_HIGH,
    FAULT_TEMPERATURE_LOW,
    FAULT_TEMPERATURE_HIGH
};

struct Motor
{
    int rpm;
    float voltage;
    float temperature;
    enum MotorState state;
    enum MotorFault fault;
};

void printMotor(struct Motor motor);
void startMotor(struct Motor *motor);
void updateSafety(struct Motor *motor);
enum MotorFault detectFault(const struct Motor *motor);

#endif