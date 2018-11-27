#include "general.h"
#include "general_types.h"
#include "hal_motor.h"
#include "hal_servo.h"
int main()
{
    //vMotorInit();
	//vSetMotorDirSpeed(INAINTE,50);
	
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

    while(1)
    {
    }
    return 0;
}