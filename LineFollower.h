#ifndef __LineFollower__HEADER__
#define __LineFollower__HEADER__

#include "general_types.h"

#define OUT 1
#define IN 0

void LF_vSetPinsDir(BOOL bDir);
void LF_vWritePins(void);
T_U8 LF_u8ReadPins(void);

#endif