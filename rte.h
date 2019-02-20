#include "hal_motor.h"
#include "hal_servo.h"
#include "LineFollower.h"
#include "hal_battery.h"

#ifndef __rte__HEADER__
#define __rte__HEADER__

void RTE_TASK_Inits();
void RTE_TASK_1ms();
void RTE_TASK_5ms();
void RTE_TASK_10ms();
void RTE_TASK_100ms();
void RTE_TASK_500ms();
void RTE_TASK_1000ms();

//motor dc
#define RTE_vMotorInit() vMotorInit()
#define RTE_vSetMotorDir(u8Dir) vSetMotorDir(u8Dir)
#define RTE_vSetMotorSpeed(u8Speed) vSetMotorSpeed(u8Speed)
#define RTE_vSetMotorDirSpeed(u8Dir,u8Speed) vSetMotorDirSpeed(u8Dir,u8Speed)

//servo
#define RTE_vServoInit() vServoInit()
#define RTE_vSetServoAngle(u8Angle) vSetServoAngle(u8Angle)

//line following
#define RTE_LF_vSetPinsDir(bDir) LF_vSetPinsDir(bDir)
#define RTE_LF_vWritePins(void) LF_vWritePins(void)
#define RTE_LF_u8ReadPins(void) LF_u8ReadPins(void)
/*
#define RTE_
#define RTE_
#define RTE_
#define RTE_
#define RTE_
#define RTE_
#define RTE_
#define RTE_
*/

#endif