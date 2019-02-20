#include "hal_battery.h"
#include "mcal_adc.h"
const T_F16 TensPercent[2][5]={{8.4,7,6.5,6},{100,20,10,0}};

T_U8 BAT_f16GetLevel()
{
    T_U16 u16ReadValRaw = ADC_u16Read(0);
    T_F16 u16ReadValVoltage = u16ReadValRaw * 3.07 / 4095;
    T_F16 u16BatVoltage = u16ReadValVoltage * 4;
    
    if(u16BatVoltage>8.4) return 100;
    
    if(u16BatVoltage<6) return 0;
    
    T_U8 contor=0;
    while(u16ReadValVoltage < TensPercent[0][contor])contor++;
    //contor e capat superior. 0 e pt tensiune
    
    T_F16 f16Rez = ( TensPercent[0][contor] + TensPercent[0][contor+1] ) / ( TensPercent[1][contor] + TensPercent[1][contor+1] );
    
    T_F16 u16VoltDif = TensPercent[0][contor] - u16ReadValVoltage;
    
    T_U8 u8Per = u16VoltDif * f16Rez;
    
    return TensPercent[1][contor] - u8Per;
    
    
}
