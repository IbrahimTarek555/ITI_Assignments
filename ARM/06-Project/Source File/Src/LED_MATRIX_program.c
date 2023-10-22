#include <stdint.h>

#include "../Inc/Defines.h"

#include "../Inc/Stm32F401cc.h"

#include "../Inc/GPIO_interface.h"
#include "../Inc/SYSTICK_interface.h"

#include "../Inc/LED_MATRIX_interface.h"
#include "../Inc/LED_MATRIX_private.h"
#include "../Inc/LED_MATRIX_config.h"

GPIO_PinConfig_t LED_MATRIX_stRowsArr[8] = LED_MATRIX_ROWS_PINS;
GPIO_PinConfig_t LED_MATRIX_stColumnsArr[8] = LED_MATRIX_COLUMNS_PINS;


void LED_MATRIX_voidInit(void)
{
	/* Define a counter*/
	uint8_t Local_u8Counter;

	/*Initialize all the led matrix pins*/
	for(Local_u8Counter = 0; Local_u8Counter < 8; Local_u8Counter++)
	{
		GPIO_enPinInit(&LED_MATRIX_stRowsArr[Local_u8Counter]);
		GPIO_enPinInit(&LED_MATRIX_stColumnsArr[Local_u8Counter]);
	}
}

void LED_MATRIX_voidDisableRows(void)
{
	/* Define a counter*/
	uint8_t Local_u8Counter;

	/*Make all the columns' pins high*/
	for(Local_u8Counter = 0; Local_u8Counter < 8; Local_u8Counter++)
	{
		GPIO_enSetPinValue(&LED_MATRIX_stRowsArr[Local_u8Counter], GPIO_PIN_LOW);
	}
}

void LED_MATRIX_voidSetColumnVlaue(uint8_t Copy_u8ColumnValue)
{
	/* Define a counter*/
	uint8_t Local_u8Counter;

	/*Make all the columns' pins high*/
	for(Local_u8Counter = 0; Local_u8Counter < 8; Local_u8Counter++)
	{
		GPIO_enSetPinValue(&LED_MATRIX_stColumnsArr[Local_u8Counter], ((Copy_u8ColumnValue >> Local_u8Counter) & 0b1u));
	}
}

void LED_MATRIX_voidDisplayAsynch(uint8_t Copy_u8Arr[])
{
	/*Increment the counter*/
	static uint8_t Local_u8Counter = 0;

	if(Local_u8Counter == 8u)
	{
		Local_u8Counter = 0u;
	}

	/* Make all the columns' pins high */
	LED_MATRIX_voidDisableRows();
	LED_MATRIX_voidSetColumnVlaue(Copy_u8Arr[Local_u8Counter]);
	GPIO_enSetPinValue(&LED_MATRIX_stRowsArr[Local_u8Counter], GPIO_PIN_HIGH);

	Local_u8Counter++;
}

void LED_MATRIX_voidDisplaySynch(uint8_t Copy_u8Arr[])
{
	/* Define a counter*/
	uint8_t Local_u8Counter;

	/* Make all the columns' pins high */
	for(Local_u8Counter = 0; Local_u8Counter < 8; Local_u8Counter++)
	{
		LED_MATRIX_voidDisableRows();
		LED_MATRIX_voidSetColumnVlaue(Copy_u8Arr[Local_u8Counter]);
		GPIO_enSetPinValue(&LED_MATRIX_stRowsArr[Local_u8Counter], GPIO_PIN_HIGH);
		SYSTICK_voidDelayUS(2500);
	}
}

















