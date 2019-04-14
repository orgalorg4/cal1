#include "rte.h"

#include "general.h"

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
	RTE_vSetMotorDirSpeed(INAINTE,10);
}


void battery()
{
    T_F16 p=BAT_f16GetLevel();
    
    if(p<90) LEDr_TOG;
}

void LineAndStop()
{//nu merge
//    T_U8 value = RTE_LF_u8ReadPins();
//    static T_U8 nrLinii=0;
//    if((value&1) && (value&(1<<5)))nrLinii++;
//    if(nrLinii>1)RTE_vSetServoAngle(110);
    go();
    if(1)
    {
        static T_S16 s16elapsed = 0;
        s16elapsed += QEI_s16getElapsed();
        if(s16elapsed > 20*100)
        {
            RTE_vSetMotorDirSpeed(INAINTE,0);
            while(3);
        }
    }
}
BOOL bObstDetectedExtern;

void caramida()
{
    if(bObstDetectedExtern == 0)
        go();
    else
        RTE_vSetMotorDirSpeed(INAINTE,0);
}