/*--------------------------------------------------------------------------
 * [FILE NAME]:		<LM35.h>
 *
 * [AUTHOR]:		<Marwan Gamal>
 *
 * [DATE CREATED]:	<4/10/2021>
 *
 * [DESCRIPTION]:	<A header file for LM35 sensor driver>
 ---------------------------------------------------------------------------*/

#ifndef LM35_H
#define LM35_H

/*-----------------------------------INCLUDES---------------------------------*/

#include "std_types.h"

/*------------------------DEFINITIONS AND CONFIGURATIONS----------------------*/

#define LM35_PIN			2
#define LM35_MAX_TEMP		150
#define LM35_MAX_VOLT		1.5

/*-----------------------------FUNCTIONS PROTOTYPES---------------------------*/
void LM35_init(void);

uint8 LM35_getTemperature(void);

#endif /* LM35_H */
