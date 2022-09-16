/*--------------------------------------------------------------------------
 * [FILE NAME]:		<timer.h>
 *
 * [AUTHOR]:		<Marwan Gamal>
 *
 * [DATE CREATED]:	<11/10/2021>
 *
 * [DESCRIPTION]:	<A header file for AVR Timer driver>
 ---------------------------------------------------------------------------*/

#ifndef TIMER_H
#define TIMER_H

/*-----------------------------------INCLUDES---------------------------------*/

#include "std_types.h"

/*-----------------------------FUNCTIONS PROTOTYPES---------------------------*/
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* TIMER_H */
