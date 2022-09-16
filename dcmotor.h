/*--------------------------------------------------------------------------
 * [FILE NAME]:		<dcmotor.h>
 *
 * [AUTHOR]:		<Marwan Gamal>
 *
 * [DATE CREATED]:	<10/10/2021>
 *
 * [DESCRIPTION]:	<A header file for DC Motor driver>
 ---------------------------------------------------------------------------*/

#ifndef DCMOTOR_H
#define DCMOTOR_H

/*-----------------------------------INCLUDES---------------------------------*/

#include "std_types.h"

/*------------------------DEFINITIONS AND CONFIGURATIONS----------------------*/

#define IN1_PORT_ID		PORTD_ID
#define IN1_PIN_ID		PIN3_ID

#define	IN2_PORT_ID		PORTD_ID
#define IN2_PIN_ID		PIN4_ID

/*-----------------------------TYPES DECLEARATION-----------------------------*/

typedef enum
{
	STOP,CW,CCW
}DcMotor_State;

/*-----------------------------FUNCTIONS PROTOTYPES---------------------------*/
void DcMotor_Init(void);

void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DCMOTOR_H */
