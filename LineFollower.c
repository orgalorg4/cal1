#include "LineFollower.h"
#include "mcal_gpio.h"

void LF_vSetPinsDir(BOOL bDir)
{
	T_U8 i;
	for(i=0;i<6;i++)
		GPIO_u8SetPortPin(PORT_C,i,DIGITAL,bDir);
}
void LF_vWritePins(void)
{
	T_U8 i;
	for(i=0;i<6;i++)
		GPIO_u8WritePortPin(PORT_C,i,HIGH);
}
T_U8 LF_u8ReadPins(void)
{
	LF_vSetPinsDir(OUTPUT);
	LF_vWritePins();
	__delay_us(10);
	LF_vSetPinsDir(INPUT);
	__delay_us(250);
	return GPIO_u16ReadPort(PORT_C)&0x3F;
}
BOOL LF_bReadPin(T_U8 sensor)
{
    //0 pt drepta
    T_U8 value = LF_u8ReadPins();
    if(sensor>=0 && sensor <6)
        if((1<<sensor)&value)
            return 1;
    return 0;
    
}