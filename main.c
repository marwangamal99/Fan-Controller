#include "lcd.h"
#include "LM35.h"
#include "dcmotor.h"

int main(void)
{
	uint8 temperature = 0;

	LM35_init();
	DcMotor_Init();
	LCD_init();

	LCD_clearScreen();
	LCD_displayStringRowColumn("FAN IS ",0,3);
	LCD_displayStringRowColumn("TEMP =    C",1,3);

	while(1)
	{
		temperature = LM35_getTemperature();	/* take the temperature digital value from the sensor */

		if(temperature < 30) /* If the temperature is less than 30C turn off the fan */
		{
			DcMotor_Rotate(STOP,0);
			LCD_displayStringRowColumn("OFF",0,10);
			LCD_moveCursor(1,10);
			if(temperature >= 100)
			{
				LCD_integerToString(temperature);
			}
			else
			{
				LCD_integerToString(temperature);
				LCD_displayCharacter(' '); /* to clear any additional garbage number */
			}

		}
		else if((temperature >= 30) && (temperature < 60))	/* If the temperature is greater than or equal 30C turn on the fan with 25% of its maximum speed */
		{
			DcMotor_Rotate(CW,25);
			LCD_displayStringRowColumn("ON ",0,10);
			LCD_moveCursor(1,10);
			if(temperature >= 100)
			{
				LCD_integerToString(temperature);
			}
			else
			{
				LCD_integerToString(temperature);
				LCD_displayCharacter(' ');
			}
		}
		else if((temperature >= 60) && (temperature < 90))	/* If the temperature is greater than or equal 60C turn on the fan with 50% of its maximum speed */
		{
			DcMotor_Rotate(CW,50);
			LCD_displayStringRowColumn("ON",0,10);
			LCD_moveCursor(1,10);
			if(temperature >= 100)
			{
				LCD_integerToString(temperature);
			}
			else
			{
				LCD_integerToString(temperature);
				LCD_displayCharacter(' ');
			}
		}
		else if((temperature >= 90) && (temperature < 120))	/* If the temperature is greater than or equal 60C turn on the fan with 50% of its maximum speed */
		{
			DcMotor_Rotate(CW,75);
			LCD_displayStringRowColumn("ON",0,10);
			LCD_moveCursor(1,10);
			if(temperature >= 100)
			{
				LCD_integerToString(temperature);
			}
			else
			{
				LCD_integerToString(temperature);
				LCD_displayCharacter(' ');
			}
		}
		else	/* If the temperature is greater than or equal 90C turn on the fan with 100% of its maximum speed */
		{
			DcMotor_Rotate(CW,100);
			LCD_displayStringRowColumn("ON",0,10);
			LCD_moveCursor(1,10);
			if(temperature >= 100)
			{
				LCD_integerToString(temperature);
			}
			else
			{
				LCD_integerToString(temperature);
				LCD_displayCharacter(' ');
			}
		}
	}
}
