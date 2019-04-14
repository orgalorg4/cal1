#include "hal_encoder.h"
#include "mcal_encoder.h"

T_S16 QEI_s16getElapsed()
{
    T_S16 s16Deplasare = 32000 - QEI_u16getCount();
    QEI_vResetCount();
    return s16Deplasare;
}