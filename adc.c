/*--------------------------------------------------------------------------------------
 * [FILE NAME]:		<adc.c>
 *
 * [AUTHOR]:		<Marwan Gamal>
 *
 * [DATE CREATED]:	<6/10/2021>
 *
 * [DESCRIPTION]:	<A source file for AVR ADC driver>
 --------------------------------------------------------------------------------------*/

/*----------------------------------------INCLUDES-------------------------------------*/

#include "adc.h"
#include "common_macros.h"
#include <avr/io.h>

/*---------------------------------FUNCTIONS DEFINITIONS-------------------------------*/
/*---------------------------------------------------------------------------------------
 * [FUNCTION NAME]:	ADC_init
 * [DESCRIPTION]:	This Function is used to initialize the ADC driver
 * [ARGS]:		No Arguments
 *	[RETURNS]:	No Returns
 ----------------------------------------------------------------------------------------*/
void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	/* Set the voltage adjust registers (REFS1,REFS0) in the last 2 bits "BIT7,BIT6" */
	ADMUX = (ADMUX & 0x3F) | ((Config_Ptr->ref_volt)<<6);

	/* Set the bits of choosing channel number in the first 5 bits (MUX0 => MUX4) */
	//ADMUX = (ADMUX & 0xE0) | ((Config_Ptr->ch_num));

	/* For ADCSRA register
	 * 1. Enable ADC (ADEN)
	 * 2. Set the prescaler value
	 */
	ADCSRA = (1<<ADEN);
	ADCSRA = (ADCSRA & 0xF8) | (Config_Ptr->prescaler);
}

/*---------------------------------------------------------------------------------------
 * [FUNCTION NAME]:	ADC_readChannel
 * [DESCRIPTION]:	This Function is used to read the Data from ADC channel
 * 					it senses the physical value and convert it into voltage then take the
 * 					voltage(analog value) and converts it into digital value
 * [ARGS]:		uint8 ch_num : This Argument shall indicate the specified channel number
 *	[RETURNS]:	The return shall indicate the read data from channel
 ----------------------------------------------------------------------------------------*/
uint16 ADC_readChannel(uint8 ch_num)
{
	ADMUX &= 0xE0;	/* AND with 0xE0 because we need only the 1st 5 bits MUX(0 -> 4) */
	ch_num &= 0x07;	/* Because the range of channel numbers is 0 to 7 (Max is 111) */

	/*
	 * 1. Insert Channel number to ADMUX
	 * 2. Start the conversion
	 * 3. Polling by which entering while loop when ADIF = 0 until ADIF = 0
	 * 4. Clear interrupt flag (ADIF)
	 * 5. Return ADC register Data
	 */
	ADMUX |= ch_num;
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);	/* The flag is cleared by set 1 in it */

	return ADC;
}
