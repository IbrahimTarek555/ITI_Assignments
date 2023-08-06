/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: IR_program.c			**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/


#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "IR_config.h"
#include "IR_private.h"
#include "IR_interface.h"


IR_REFLECT_STATE_t IR_enCheckState(IR_t *Copy_stSensorData)
{
	IR_REFLECT_STATE_t Local_enReflectState;
	uint8 Local_u8PinState;

	DIO_u8GetPinValue(Copy_stSensorData -> Port, Copy_stSensorData -> Pin, &Local_u8PinState);

	if(Local_u8PinState == DIO_u8PIN_HIGH)
	{
		Local_enReflectState = REFLECTED;
	}
	else if (Local_u8PinState == DIO_u8PIN_LOW)
	{
		Local_enReflectState = NOT_REFLECTED;
	}

	return Local_enReflectState;
}
