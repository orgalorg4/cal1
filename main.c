#include "general.h"
#include "hal_motor.h"
int main()
{
    vMotorInit();
	vSetMotorDirSpeed(INAINTE,50);
	
    while(1)
    {
    }
    return 0;
}