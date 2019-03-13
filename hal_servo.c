#include "hal_servo.h"
#include "mcal_pwm.h"

void vServoInit(){
	PWM1_vInit();
	PWM1_vSetDuty(8,1);
}
void vSetServoAngle(T_U8 u8Angle){
	//the motor can move 60 degrees(30  left, 30 right)
	//90 is the middle
	//max left=60; max right=120
	
	//limitare
	if(u8Angle<60)u8Angle=60;
	if(u8Angle>120)u8Angle=120;
	
	//formula
	float u8ServoDuty = (float)((u8Angle-10)*7)/160+4;
	
	PWM1_vSetDuty(u8ServoDuty,1);
}
