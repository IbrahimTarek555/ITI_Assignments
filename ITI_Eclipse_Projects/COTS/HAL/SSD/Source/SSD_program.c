/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: SSD_program.c			**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/

/**
 * @file SSD_program.c
 * @author Ibrahim Tarek
 * @brief This file implements the SSD module functions.
 * @version 1.00
 */

#include "../../../Common/STD_TYPES.h"
#include "../../../Common/BIT_MATH.h"
#include "../../../Common/DEFINES.h"

#include "../../../MCAL/DIO/Header/DIO_interface.h"

#include "../Header/SSD_config.h"
#include "../Header/SSD_private.h"
#include "../Header/SSD_interface.h"

/**
 * @brief 							Function to display a number into the display.
 * @param Copy_pssdtSSDInformation	Pointer to struct that carries the SSD information.
 * @param Copy_u8Number				Number needed to be displayed.
 * @return							Error State.
 */
uint8 SSD_u8SetNumber(const SSD_t *Copy_pstSSDInformation, uint8 Copy_u8Number)
{
	uint8 Local_u8ErrorState = OK;

	/*Validate the pointer address*/
	if(Copy_pstSSDInformation != NULL)
	{

		/*Set the number to the SSD according to the type of it*/
		if(Copy_pstSSDInformation -> Type == SSD_u8CATHODE)
		{
			/*Set enable pin to HIGH*/
			DIO_u8SetPinValue(Copy_pstSSDInformation -> EnablePort, Copy_pstSSDInformation -> EnablePin, DIO_u8PIN_LOW);

			/*Set the first of the pins*/
			if(Copy_pstSSDInformation -> LedPin == 0)
			{
				DIO_u8SetPortValue(Copy_pstSSDInformation -> Port, SSD_u8NumbersArray[Copy_u8Number]);
			}
			else if(Copy_pstSSDInformation -> LedPin == 1)
			{
				DIO_u8SetPortValue(Copy_pstSSDInformation -> Port, (SSD_u8NumbersArray[Copy_u8Number] << 1));
			}
			else
			{
				Local_u8ErrorState = NOK;
			}
		}
		else if(Copy_pstSSDInformation -> Type == SSD_u8ANODE)
		{
			/*Set enable pin to LOW*/
			DIO_u8SetPinValue(Copy_pstSSDInformation -> EnablePort, Copy_pstSSDInformation -> EnablePin, DIO_u8PIN_HIGH);

			/*Set the first of the pins*/
			if(Copy_pstSSDInformation -> LedPin == 0)
			{
				DIO_u8SetPortValue(Copy_pstSSDInformation -> Port, ~SSD_u8NumbersArray[Copy_u8Number]);
			}
			else if(Copy_pstSSDInformation -> LedPin == 1)
			{
				DIO_u8SetPortValue(Copy_pstSSDInformation -> Port, ~(SSD_u8NumbersArray[Copy_u8Number] << 1));
			}
			else
			{
				Local_u8ErrorState = NOK;
			}
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

	/*Return error state*/
	return Local_u8ErrorState;
}


/**
 * @brief 							Function to disable a SSD.
 * @param Copy_pssdtSSDInformation	Pointer to struct that carries the SSD information.
 * @return							Error State.
 */
uint8 SSD_u8Disable(const SSD_t *Copy_pstSSDInformation)
{
	uint8 Local_u8ErrorState = OK;

	/*Validate the pointer address*/
	if(Copy_pstSSDInformation != NULL)
	{
		/*Disable the SSD by reset its enable pin to zero*/
		if(Copy_pstSSDInformation -> Type == SSD_u8CATHODE)
		{
			DIO_u8SetPinValue(Copy_pstSSDInformation -> EnablePort, Copy_pstSSDInformation -> EnablePin, DIO_u8PIN_HIGH);
		}
		else if(Copy_pstSSDInformation -> Type == SSD_u8ANODE)
		{
			DIO_u8SetPinValue(Copy_pstSSDInformation -> EnablePort, Copy_pstSSDInformation -> EnablePin, DIO_u8PIN_LOW);
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

	/*Return error state*/
	return Local_u8ErrorState;
}
