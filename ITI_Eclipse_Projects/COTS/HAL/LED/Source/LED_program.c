/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: LED_program.c			**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/

/**
 * @file LED_program.c
 * @author Ibrahim Tarek
 * @brief This file implements the LED module functions.
 * @version 1.00
 */

#include "../../../Common/STD_TYPES.h"
#include "../../../Common/BIT_MATH.h"
#include "../../../Common/DEFINES.h"

#include "../../../MCAL/DIO/Header/DIO_interface.h"

#include "../Header/LED_config.h"
#include "../Header/LED_private.h"
#include "../Header/LED_interface.h"

/**
 * @brief 							Function to turn on a LED.
 * @param Copy_pledtLEDInformation	Pointer to a struct which carries the LED data.
 * @return 						  	Error state.
 */
uint8 LED_u8On(const LED_t *Copy_pstLEDInformation)
{
	uint8 Local_u8ErrorState = OK;

	/*Validate the pointer address*/
	if(Copy_pstLEDInformation != NULL)
	{
		if(Copy_pstLEDInformation -> Type == LED_u8ACTIVE_HIGH)
		{
			DIO_u8SetPinValue(Copy_pstLEDInformation -> Port, Copy_pstLEDInformation -> Pin, DIO_u8PIN_HIGH);
		}
		else if(Copy_pstLEDInformation -> Type == LED_u8ACTIVE_LOW)
		{
			DIO_u8SetPinValue(Copy_pstLEDInformation -> Port, Copy_pstLEDInformation -> Pin, DIO_u8PIN_LOW);
		}
		else
		{
			Local_u8ErrorState = NOK;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}

/**
 * @brief 							Function to turn off a LED.
 * @param Copy_pledtLEDInformation	Pointer to a struct which carries the LED data.
 * @return 						  	Error state.
 */
uint8 LED_u8Off(const LED_t *Copy_pstLEDInformation)
{
	uint8 Local_u8ErrorState = OK;

	/*Validate the pointer address*/
	if(Copy_pstLEDInformation != NULL)
	{
		if(Copy_pstLEDInformation -> Type == LED_u8ACTIVE_HIGH)
		{
			DIO_u8SetPinValue(Copy_pstLEDInformation -> Port, Copy_pstLEDInformation -> Pin, DIO_u8PIN_LOW);
		}
		else if(Copy_pstLEDInformation -> Type == LED_u8ACTIVE_LOW)
		{
			DIO_u8SetPinValue(Copy_pstLEDInformation -> Port, Copy_pstLEDInformation -> Pin, DIO_u8PIN_HIGH);
		}
		else
		{
			Local_u8ErrorState = NOK;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}

/**
 * @brief 							Function to toggle a LED.
 * @param Copy_pledtLEDInformation	Pointer to a struct which carries the LED data.
 * @return 						  	Error state.
 */
uint8 LED_u8Toggle(const LED_t *Copy_pstLEDInformation)
{
	uint8 Local_u8ErrorState = OK;

	/*Validate the pointer address*/
	if(Copy_pstLEDInformation != NULL)
	{
		DIO_u8TogglePinValue(Copy_pstLEDInformation -> Port, Copy_pstLEDInformation -> Pin);
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}
