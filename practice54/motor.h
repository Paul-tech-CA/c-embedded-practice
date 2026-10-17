#ifndef MOTOR_H
#define MOTOR_H

#include <stdint.h>
#include <stdbool.h>

#define FAULT_VOLTAGE_LOW_MASK       (1u << 0)
#define FAULT_VOLTAGE_HIGH_MASK      (1u << 1)
#define FAULT_TEMPERATURE_LOW_MASK   (1u << 2)
#define FAULT_TEMPERATURE_HIGH_MASK  (1u << 3)

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
    uint8_t faultFlags;
};

void printMotor(struct Motor motor);
bool startMotor(struct Motor *motor);
void updateSafety(struct Motor *motor);

uint8_t detectFaults(const struct Motor *motor);

const char *motorStateToString(enum MotorState state);
void printFaults(uint8_t faultFlags);
bool resetFaults(struct Motor *motor);

#endif