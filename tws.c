#include "rte.h"

T_U8 readline()
{
	T_U8 on_line = 0;
	T_U8 i;
	T_F16 avg=0,sum=0;
	static T_U8 last_value=0;
	
	T_U8 value = RTE_LF_u8ReadPins();
	for(i=0;i<6;i++)
	{
		T_U8 pin = value & (1<<i);
		if(pin)
		{
			on_line=1;
			avg = avg + i*10;
			sum = sum + 1;
		}
	}
	if(!on_line)
	{
		if(last_value<10)
			return 0;
		else if(last_value>40)
			return 50;
		else
			return last_value;
	}
	last_value = avg/sum;
	return last_value;
}

void go()
{
	T_U8 sensors = 50-readline();
	T_U8 angle = sensors +65;
	RTE_vSetServoAngle(angle);
	RTE_vSetMotorDirSpeed(INAINTE,25);
}