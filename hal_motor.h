
#ifndef __hal_motor__HEADER__
#define __hal_motor__HEADER__

#include "general_types.h"

//directie
#define INAINTE 1
#define INAPOI 0

void vMotorInit();
void vSetMotorDir(T_U8 u8Dir);
void vSetMotorSpeed(T_U8 u8Speed);
void vSetMotorDirSpeed(T_U8 u8Dir,T_U8 u8Speed);

#endif