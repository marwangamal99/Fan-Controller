/*--------------------------------------------------------------------------------------
 * [FILE NAME]:		<LM35.c>
 *
 * [AUTHOR]:		<Marwan Gamal>
 *
 * [DATE CREATED]:	<8/10/2021>
 *
 * [DESCRIPTION]:	<A source file for LM35 sensor driver>
 --------------------------------------------------------------------------------------*/
/*----------------------------------------INCLUDES-------------------------------------*/

#include "LM35.h"
#include "adc.h"

/*---------------------------------FUNCTIONS DEFINITIONS-------------------------------*/
/*---------------------------------------------------------------------------------------
 * [FUNCTION NAME]:	LM35_init
 * [DESCRIPTION]:	This Function is used to initiate the sensor by initiating the ADC
 * [ARGS]:		No Arguments
 *	[RETURNS]:	No Return
 ----------------------------------------------------------------------------------------*/
void LM35_init(void)
{
	ADC_ConfigType ADC_config = {LM35_ADC_VOLT,LM35_ADC_PRESCALAR};
	ADC_init(&ADC_config);
}

/*---------------------------------------------------------------------------------------
 * [FUNCTION NAME]:	LM35_getTemperature
 * [DESCRIPTION]:	This Function is used to get the temperature from the sensor
 * 					it takes the ADC value and by calculations gives the temperature output
 * [ARGS]:		No Arguments
 *	[RETURNS]:	This return shall indicates the temperature reading of the sensor
 ----------------------------------------------------------------------------------------*/
uint8 LM35_getTemperature(void)
{
	uint16 adc_value = 0;
	uint8 temp_value = 0;

	adc_value = ADC_readChannel(LM35_PIN);

	temp_value = (uint8)(((uint32)adc_value*LM35_MAX_TEMP*ADC_VREF)/(ADC_MAXIMUM_VALUE*LM35_MAX_VOLT));

	return temp_value;
}
