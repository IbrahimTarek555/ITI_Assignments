/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: STEPPER_program.c		**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/

/**
 * @file STEPPER_program.c
 * @author Ibrahim Tarek
 * @brief This file implements the stepper module functions.
 * @version 1.00
 */

#include "../../../Common/STD_TYPES.h"
#include "../../../Common/BIT_MATH.h"
#include "../../../Common/DEFINES.h"

#include "../../../MCAL/DIO/Header/DIO_interface.h"

#include <util/delay.h>

#include "../Header/STEPPER_config.h"
#include "../Header/STEPPER_private.h"
#include "../Header/STEPPER_interface.h"

/**
 * @brief					Function to rotate the stepper with a fixed speed (medium) and specific angle.
 * @param Copy_pstMotorInfo	Pointer to struct which carries the stepper information.
 * @param Copy_u16Angle		Angle to rotate with.
 * @param Copy_u8Direction	Direction to rotate with.
 * @return					Error State.
 */
uint8 STEPPER_u8RotateWithMidiumSpeed(const STEPPER_t *Copy_pstMotorInfo, uint16 Copy_u16Angle, uint8 Copy_u8Direction)
{
	/*Define Variables*/
	uint8 Local_u8ErrorState = OK;
	uint16 Local_u16FullSteps;
	uint16 Local_u16Counter;

	/*Validate the pointer address*/
	if(Copy_pstMotorInfo != NULL)
	{
		/*Calculating the full steps to take*/
		Local_u16FullSteps = (uint16) ((((uint32) Copy_u16Angle) * 2048UL) / 360UL);

		/*Taking the steps inside for loop, every loop move for 1 step*/
		if(Copy_u8Direction == STEPPER_u8ROTATE_CCW)
		{
			for(Local_u16Counter = 0; Local_u16Counter < Local_u16FullSteps; Local_u16Counter++)
			{
				switch(Local_u16Counter % 4UL)
				{
				case 0:
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> BluePin, DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> PinkPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> YellowPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> OrangePin, DIO_u8PIN_HIGH);
					break;

				case 1:
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> BluePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> PinkPin, DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> YellowPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> OrangePin, DIO_u8PIN_HIGH);
					break;

				case 2:
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> BluePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> PinkPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> YellowPin, DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> OrangePin, DIO_u8PIN_HIGH);
					break;

				case 3:
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> BluePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> PinkPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> YellowPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> OrangePin, DIO_u8PIN_LOW);
					break;
				}
				_delay_ms(STEPPER_u8SPEED_MEDIUM);
			}
		}
		else if(Copy_u8Direction == STEPPER_u8ROTATE_CW)
		{
			for(Local_u16Counter = 0; Local_u16Counter < Local_u16FullSteps; Local_u16Counter++)
			{
				switch(Local_u16Counter % 4UL)
				{
				case 3:
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> BluePin, DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> PinkPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> YellowPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> OrangePin, DIO_u8PIN_HIGH);
					break;

				case 2:
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> BluePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> PinkPin, DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> YellowPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> OrangePin, DIO_u8PIN_HIGH);
					break;

				case 1:
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> BluePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> PinkPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> YellowPin, DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> OrangePin, DIO_u8PIN_HIGH);
					break;

				case 0:
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> BluePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> PinkPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> YellowPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> OrangePin, DIO_u8PIN_LOW);
					break;
				}
				_delay_ms(STEPPER_u8SPEED_MEDIUM);
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

	/*Return the error state*/
	return Local_u8ErrorState;
}

/**
 * @brief					Function to rotate the stepper with variable angle and speed.
 * @param Copy_pstMotorInfo	Pointer to struct which carries the stepper information.
 * @param Copy_u16Angle		Angle to rotate with.
 * @param Copy_u8Direction	Direction to rotate with.
 * @param Copy_u8Speed		Speed to rotate with.
 * @return					Error State.
 */
uint8 STEPPER_u8RotateWithAngle(const STEPPER_t *Copy_pstMotorInfo, uint16 Copy_u16Angle, uint8 Copy_u8Direction, uint8 Copy_u8Speed)
{
	/*Define Variables*/
	uint8 Local_u8ErrorState = OK;
	uint16 Local_u16FullSteps;
	uint16 Local_u16Counter;

	/*Validate the pointer address*/
	if(Copy_pstMotorInfo != NULL)
	{
		/*Calculating the full steps to take*/
		Local_u16FullSteps = (uint16) ((((uint32) Copy_u16Angle) * 2048UL) / 360UL);

		/*Taking the steps inside for loop, every loop move for 1 step*/
		if(Copy_u8Direction == STEPPER_u8ROTATE_CCW)
		{
			for(Local_u16Counter = 0; Local_u16Counter < Local_u16FullSteps; Local_u16Counter++)
			{
				switch(Local_u16Counter % 4UL)
				{
				case 0:
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> BluePin, DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> PinkPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> YellowPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> OrangePin, DIO_u8PIN_HIGH);
					break;

				case 1:
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> BluePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> PinkPin, DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> YellowPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> OrangePin, DIO_u8PIN_HIGH);
					break;

				case 2:
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> BluePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> PinkPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> YellowPin, DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> OrangePin, DIO_u8PIN_HIGH);
					break;

				case 3:
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> BluePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> PinkPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> YellowPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> OrangePin, DIO_u8PIN_LOW);
					break;
				}
				_delay_ms(Copy_u8Speed);
			}
		}
		else if(Copy_u8Direction == STEPPER_u8ROTATE_CW)
		{
			for(Local_u16Counter = 0; Local_u16Counter < Local_u16FullSteps; Local_u16Counter++)
			{
				switch(Local_u16Counter % 4UL)
				{
				case 3:
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> BluePin, DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> PinkPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> YellowPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> OrangePin, DIO_u8PIN_HIGH);
					break;

				case 2:
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> BluePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> PinkPin, DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> YellowPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> OrangePin, DIO_u8PIN_HIGH);
					break;

				case 1:
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> BluePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> PinkPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> YellowPin, DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> OrangePin, DIO_u8PIN_HIGH);
					break;

				case 0:
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> BluePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> PinkPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> YellowPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> OrangePin, DIO_u8PIN_LOW);
					break;
				}
				_delay_ms(Copy_u8Speed);
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

	/*Return the error state*/
	return Local_u8ErrorState;
}

/**
 * @brief						Function to rotate the stepper with variable speed and number of complete rolls.
 * @param Copy_pstMotorInfo		Pointer to struct which carries the stepper information.
 * @param Copy_u8RollsNumber	Number of rolls.
 * @param Copy_u8Direction		Direction to rotate with.
 * @param Copy_u8Speed			Speed to rotate with.
 * @return						Error State.
 */
uint8 STEPPER_u8RotateWithRolls(const STEPPER_t *Copy_pstMotorInfo, uint8 Copy_u8RollsNumber, uint8 Copy_u8Direction, uint8 Copy_u8Speed)
{
	/*Define Variables*/
	uint8 Local_u8ErrorState = OK;
	uint32 Local_u32Counter;
	uint32 Local_u32FullSteps;

	/*Validate the pointer address*/
	if(Copy_pstMotorInfo != NULL)
	{
		/*Calculating the full steps to take*/
		Local_u32FullSteps = (uint32) Copy_u8RollsNumber * 2048UL;

		/*Taking the steps inside for loop, every loop move for 1 step*/
		if(Copy_u8Direction == STEPPER_u8ROTATE_CCW)
		{
			for(Local_u32Counter = 0; Local_u32Counter < Local_u32FullSteps; Local_u32Counter++)
			{
				switch(Local_u32Counter % 4UL)
				{
				case 0:
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> BluePin, DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> PinkPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> YellowPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> OrangePin, DIO_u8PIN_HIGH);
					break;

				case 1:
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> BluePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> PinkPin, DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> YellowPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> OrangePin, DIO_u8PIN_HIGH);
					break;

				case 2:
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> BluePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> PinkPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> YellowPin, DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> OrangePin, DIO_u8PIN_HIGH);
					break;

				case 3:
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> BluePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> PinkPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> YellowPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> OrangePin, DIO_u8PIN_LOW);
					break;
				}
				_delay_ms(Copy_u8Speed);
			}
		}
		else if(Copy_u8Direction == STEPPER_u8ROTATE_CW)
		{
			for(Local_u32Counter = 0; Local_u32Counter < Local_u32FullSteps; Local_u32Counter++)
			{
				switch(Local_u32Counter % 4UL)
				{
				case 3:
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> BluePin, DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> PinkPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> YellowPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> OrangePin, DIO_u8PIN_HIGH);
					break;

				case 2:
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> BluePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> PinkPin, DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> YellowPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> OrangePin, DIO_u8PIN_HIGH);
					break;

				case 1:
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> BluePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> PinkPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> YellowPin, DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> OrangePin, DIO_u8PIN_HIGH);
					break;

				case 0:
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> BluePin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> PinkPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> YellowPin, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pstMotorInfo -> Port, Copy_pstMotorInfo -> OrangePin, DIO_u8PIN_LOW);
					break;
				}
				_delay_ms(Copy_u8Speed);
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

	/*Return the error state*/
	return Local_u8ErrorState;
}
