/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: SWITCH_program.c		**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/

/**
 * @file SWITCH_program.c
 * @author Ibrahim Tarek
 * @brief This file implements the switch module functions.
 * @version 1.00
 */

#include "../../../Common/STD_TYPES.h"
#include "../../../Common/BIT_MATH.h"
#include "../../../Common/DEFINES.h"

#include "../../../MCAL/DIO/Header/DIO_interface.h"

#include "../Header/SWITCH_config.h"
#include "../Header/SWITCH_private.h"
#include "../Header/SWITCH_interface.h"

/**
 * @brief 							Function to get the state of a button.
 * @param Copy_pstSwitchInformation	Pointer to struct which carries the button information.
 * @param Copy_pu8State				Pointer to return the state.
 * @return							Error State.
 */
uint8 SWITCH_u8GetState(const SWITCH_t *Copy_pstSwitchInformation, uint8 *Copy_pu8State)
{
	uint8 Local_u8ErrorState = OK;
	uint8 Local_u8SwitchState;

	/*Validate the pointer address*/
	if((Copy_pstSwitchInformation != NULL) && (Copy_pu8State != NULL))
	{
		DIO_u8GetPinValue(Copy_pstSwitchInformation -> Port, Copy_pstSwitchInformation -> Pin, &Local_u8SwitchState);


		if(Copy_pstSwitchInformation -> Type == SWITCH_u8PULL_UP)
		{
			switch(Local_u8SwitchState)
			{
				case DIO_u8PIN_HIGH: *Copy_pu8State = SWITCH_u8RELEASED;	break;
				case DIO_u8PIN_LOW: *Copy_pu8State = SWITCH_u8PRESSED;		break;
				default: Local_u8ErrorState = NOK;	break;
			}
		}
		else if(Copy_pstSwitchInformation -> Type == SWITCH_u8PULL_DOWN)
		{
			switch(Local_u8SwitchState)
			{
				case DIO_u8PIN_HIGH: *Copy_pu8State = SWITCH_u8PRESSED;		break;
				case DIO_u8PIN_LOW: *Copy_pu8State = SWITCH_u8RELEASED;		break;
				default: Local_u8ErrorState = NOK;	break;
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

	return Local_u8ErrorState;
}
