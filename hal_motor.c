#include "hal_motor.h"
#include "mcal_gpio.h"
#include "mcal_pwm.h"

void vMotorInit(){

	GPIO_u8SetPortPin(PORT_A,9,DIGITAL,OUTPUT);
	PWM1_vInit();
}
void vSetMotorDir(T_U8 u8Dir){
	switch(u8Dir){
		case INAINTE:
		GPIO_u8WritePortPin(PORT_A,9,HIGH);
			break;
		case INAPOI:
		GPIO_u8WritePortPin(PORT_A,9,LOW);		
			break;
	}
}
void vSetMotorSpeed(T_U8 u8Speed){
	if(u8Speed>=0 && u8Speed<=100)
		PWM1_vSetDuty(u8Speed,2);
}
void vSetMotorDirSpeed(T_U8 u8Dir,T_U8 u8Speed){
	vSetMotorDir(u8Dir);
	vSetMotorSpeed(u8Speed);
}
