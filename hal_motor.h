
#include "general_types.h"

#ifndef __hal_motor.h__HEADER
#define __hal_motor.h__HEADER

void vMotorInit();
void vSetMotorDir(T_U8  u8Dir);
void vSetMotorSpeed(T_U8 u8Speed);
void cSetMotorDirSpeed(T_U8 u8Dir,T_U8 u8Speed);

#endif