/* 
 * File:   asw_statem.h
 * Author: student
 *
 * Created on April 3, 2019, 6:12 PM
 */

#ifndef ASW_STATEM_H
#define	ASW_STATEM_H

#ifdef	__cplusplus
extern "C" {
#endif

    enum{StandBy,ReadRoad,chooseDir,ComStart,Str8,Left,Right,ComEnd,cm20Str8};
    void stateM(void);
    void vGo_str8();
    void vRreadRoad();
    


#ifdef	__cplusplus
}
#endif

#endif	/* ASW_STATEM_H */

