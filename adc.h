/*--------------------------------------------------------------------------
 * [FILE NAME]:		<adc.h>
 *
 * [AUTHOR]:		<Marwan Gamal>
 *
 * [DATE CREATED]:	<6/10/2021>
 *
 * [DESCRIPTION]:	<A header file for AVR ADC driver>
 ---------------------------------------------------------------------------*/

#ifndef ADC_H
#define ADC_H

/*-----------------------------------INCLUDES---------------------------------*/

#include "std_types.h"

/*------------------------DEFINITIONS AND CONFIGURATIONS----------------------*/

#define ADC_MAXIMUM_VALUE   1023
#define ADC_VREF   			2.56

#define LM35_ADC_VOLT		AREF_HALF_VOLT
#define	LM35_ADC_PRESCALAR	D_8

/*-----------------------------TYPES DECLEARATION-----------------------------*/

typedef enum
{
	AREF_FULL_VOLT,AVCC,RESERVED,AREF_HALF_VOLT
}ADC_ReferenceVolatge;

typedef enum
{
	D_2,D_2h,D_4,D_8,D_16,D_32,D_64,D_128
}ADC_Prescaler;

typedef struct
{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/*-----------------------------FUNCTIONS PROTOTYPES---------------------------*/

void ADC_init(const ADC_ConfigType * Config_Ptr);

uint16 ADC_readChannel(uint8 ch_num);

#endif /* ADC_H */
