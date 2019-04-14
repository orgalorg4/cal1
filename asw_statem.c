
#include "general.h"
#include "rte.h"
#include "asw_statem.h"
#include "tsw.h"

static T_U8 state=ReadRoad;

void stateM(void)
{
//    static T_U8 state;
//    state=ReadRoad;
    
    switch(state)
    {
        case StandBy:
            RTE_vSetMotorDirSpeed(INAINTE,0);
            while(1);
            break;
        case ReadRoad:
            vRreadRoad();
            break;
        case chooseDir:
            break;
        case ComStart:
            break;
        case Str8:
            vGo_str8();
            break;
        case Left:
            break;
        case Right:
            break;
        case ComEnd:
            state=StandBy;
            break;
        case cm20Str8:
            break;        
    }
}
void vGo_str8()
{
    static T_U8 nrLinii=0;
    static BOOL sensVal=0,sensValOld=0;
    
    sensVal = LF_bReadPin(LFar);
    if(sensVal!=1)
        go();
    if(sensVal!=sensValOld)
    {
        if(sensVal==1)
            nrLinii++;
        sensValOld=sensVal;
    }
    if(nrLinii>5)
    {
        nrLinii=0;
//        RTE_vSetMotorDirSpeed(INAINTE,0);
        state=StandBy;
    }
}

void vRreadRoad()
{
    static T_U8 nrDrum=0;
    static BOOL sensVal=0,sensValOld=0;
    
    sensVal = LF_bReadPin(RCenter);

    go();
    if(sensVal!=sensValOld)
    {
        if(sensVal==0)
            nrDrum++;
        sensValOld=sensVal;
    }
    
    if(LF_bReadPin(RFar)&&LF_bReadPin(LFar))
        state=Str8;
//        state=StandBy;
    
//    if(nrLinii>0)
//    {
//        nrLinii=0;
//        state=Str8;
//    }
}