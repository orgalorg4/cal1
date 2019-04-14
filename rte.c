#include "rte.h"
#include "tsw.h"
#include "asw_statem.h"

void RTE_TASK_Inits()
{
	
}
void RTE_TASK_1ms()
{
//    COM_vCheckIRQ();
//    COM_vStartListening();
}
void RTE_TASK_5ms()
{

}
void RTE_TASK_10ms()
{
//    COM_vProcessFIFO();
//    BOOL u8NewRX;
//    if(u8NewRX)
//    {
//        COM_vProcessFIFO();
//    }

}
void RTE_TASK_100ms()
{
//    go();
//    battery();
//    LineAndStop();
//    caramida();
    stateM();
}
void RTE_TASK_500ms()
{

}
void RTE_TASK_1000ms()
{
		//RTE_vSetMotorDirSpeed(INAINTE,50);
//    static int i=0;
//    if(i==7)
//    {
//        COM_vSendMessage(0x50);
//        i=0;
//    }
//    i++;
}
