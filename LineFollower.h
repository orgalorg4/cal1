#ifndef __LineFollower__HEADER__
#define __LineFollower__HEADER__

#include "general_types.h"

enum{RFar=0,RNear,RCenter,LCenter,LNear,LFar};

void LF_vSetPinsDir(BOOL bDir);
void LF_vWritePins(void);
T_U8 LF_u8ReadPins(void);
BOOL LF_bReadPin(T_U8 sensor);

#endif