/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: KEYPAD_program.c		**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/

/**
 * @file KEYPAD_program.c
 * @author Ibrahim Tarek
 * @brief This file implements the keypad module functions.
 * @version 1.00
 */

#include "../../../Common/STD_TYPES.h"
#include "../../../Common/BIT_MATH.h"
#include "../../../Common/DEFINES.h"

#include "../../../MCAL/DIO/Header/DIO_interface.h"

#include "../Header/KEYPAD_private.h"
#include "../Header/KEYPAD_interface.h"
#include "../Header/KEYPAD_config.h"

/**
 * @brief Function to return data of the pressed key
 * @return data of the pressed key
 */
uint8 KEYPAD_u8GetPressedKey(void)
{
	uint8 Local_u8ColumnCounter;
	uint8 Local_u8RowCounter;
	uint8 Local_u8KeyState;
	uint8 Local_u8PressedKey = KEYPAD_u8NO_PRESSED_KEY;

	static uint8 Local_u8ColumnArr[KEYPAD_u8COLUMNS_NUM] = KEYPAD_u8COLUMNS_ARR;
	static uint8 Local_u8RowArr[KEYPAD_u8ROWS_NUM] = KEYPAD_u8ROWS_ARR;
	static uint8 Local_u8KeypadArr[KEYPAD_u8ROWS_NUM][KEYPAD_u8COLUMNS_NUM] = KEYPAD_u8BUTTON_ARR;

	/*Activate column pins and read the rows*/
	for(Local_u8ColumnCounter = 0; Local_u8ColumnCounter < KEYPAD_u8COLUMNS_NUM; Local_u8ColumnCounter++)
	{
		/*Activate the current column*/
		DIO_u8SetPinValue(KEYPAD_u8COLUMNS_PORT, Local_u8ColumnArr[Local_u8ColumnCounter], DIO_u8PIN_LOW);

		/*Get values of rows and check for signals from them*/
		for(Local_u8RowCounter = 0; Local_u8RowCounter < KEYPAD_u8ROWS_NUM; Local_u8RowCounter++)
		{
			/*Get the value of the current row*/
			DIO_u8GetPinValue(KEYPAD_u8ROWS_PORT, Local_u8RowArr[Local_u8RowCounter], &Local_u8KeyState);

			/*If the current row is low, then button is pressed*/
			if(Local_u8KeyState == DIO_u8PIN_LOW)
			{
				/*Wait until the key is released*/
				while(Local_u8KeyState == DIO_u8PIN_LOW)
				{
					DIO_u8GetPinValue(KEYPAD_u8ROWS_PORT, Local_u8RowArr[Local_u8RowCounter], &Local_u8KeyState);
				}

				/*Return the corresponding value of the key from the buttons array*/
				Local_u8PressedKey = Local_u8KeypadArr[Local_u8RowCounter][Local_u8ColumnCounter];

				/*Deactivate the current column*/
				DIO_u8SetPinValue(KEYPAD_u8COLUMNS_PORT, Local_u8ColumnArr[Local_u8ColumnCounter], DIO_u8PIN_HIGH);

				/*Return the pressed key*/
				return Local_u8PressedKey;
			}
		}

		/*Deactivate the current column*/
		DIO_u8SetPinValue(KEYPAD_u8COLUMNS_PORT, Local_u8ColumnArr[Local_u8ColumnCounter], DIO_u8PIN_HIGH);
	}

	/*Return that is no pressed key*/
	return Local_u8PressedKey;
}
