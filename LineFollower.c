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
	LF_vSetPinsDir(OUT);
	LF_vWritePins();
	__delay_us(10);
	LF_vSetPinsDir(IN);
	__delay_us(250);
	return GPIO_u16ReadPort(PORT_C);
}
