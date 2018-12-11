#include "general.h"
#include "general_types.h"
#include "hal_motor.h"
#include "hal_servo.h"
#include "LineFollower.h"

int main()
{
	TASK_Inits();
    vMotorInit();
	vServoInit();


	TASK_vSchedule();

	/*
	T_U16 i;

	vServoInit();
	for(i=60;i<120;i++){
		vSetServoAngle(i);
		__delay_ms(110);
	}
	for(i=120;i>70;i--){
		vSetServoAngle(i);
		__delay_ms(110);
	}
	*/


    while(1)
    {

/*
		T_U8 u8SensorValues = LF_u8ReadPins();

		T_U8 i,e=0,e2;
		T_U8 b;
		for(i=0;i<6;i++)
		{
			b=1<<i;
			if(u8SensorValues & b)
				e=i;
			
		}
		e2=e*60/5+60;

		if(e2>110)e2=110;
		if(e2<65)e2=65;

		vSetServoAngle(e2);
		/*	
		T_U8 u8Angle;// = u8SensorValues+60;

		if(u8SensorValues==0)u8Angle=110;
		if(u8SensorValues>0)u8Angle=70;

		vSetServoAngle(u8Angle);
*/
    }
    return 0;
}