/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: EEPROM_program.c		**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/

/**
 * @file EEPROM_program.c
 * @author Ibrahim Tarek
 * @brief This file implements the EEPROM module functions.
 * @version 1.00
 */

#include "../../../Common/STD_TYPES.h"
#include "../../../Common/BIT_MATH.h"
#include "../../../Common/DEFINES.h"

#include "../../../MCAL/DIO/Header/DIO_interface.h"

#include <util/delay.h>

#include "../Header/EEPROM_config.h"
#include "../Header/EEPROM_private.h"
#include "../Header/EEPROM_interface.h"

/**
 * @brief 							Function to write a byte into the EEPROM.
 * @param Copy_u16LocationAddress 	Address to write into.
 * @param Copy_u8Data				Byte wanted to be written.
 * @return							Error state.
 */
uint8 EEPROM_u8WriteDataByte(uint16 Copy_u16LocationAddress, uint8 Copy_u8Data)
{
	/*Define Variables*/
	uint8 Local_u8ErrorState = OK;

	/*Validate the address*/
	if(Copy_u16LocationAddress <= EEPROM_MAX_ADDRESS)
	{
		/*Form the slave address to call*/
		uint8 Local_u8SlaveAddressPacket = EEPROM_FIXED_ADDRESS | (EEPROM_A2_CONNECTION << 2u) | ((uint8) (Copy_u16LocationAddress >> 8u));

		/*Start the communication*/
		TWI_enSendStartCondition();

		/*Send Write Request*/
		TWI_enSendSlaveAddressWithWrite(Local_u8SlaveAddressPacket);

		/*Send the location address through data byte message*/
		TWI_enMasterWriteDataByte((uint8) Copy_u16LocationAddress);

		/*Send the data byte message*/
		TWI_enMasterWriteDataByte(Copy_u8Data);

		/*Stop the communication*/
		TWI_enSendStopCondition();

		/*Wait for 10 millisecond for the EEPROM write cycle*/
		_delay_ms(10);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	/*Return Error State*/
	return Local_u8ErrorState;
}

/**
 * @brief 							Function to read a byte from the EEPROM.
 * @param Copy_u16LocationAddress 	Address to read from.
 * @param Copy_pu8Data				Pointer to return the byte data.
 * @return							Error state.
 */
uint8 EEPROM_u8ReadDataByte(uint16 Copy_u16LocationAddress, uint8 *Copy_pu8Data)
{
	/*Define Variables*/
	uint8 Local_u8ErrorState = OK;

	/*Validate the address*/
	if(Copy_u16LocationAddress <= EEPROM_MAX_ADDRESS)
	{
		/*Form the slave address to call*/
		uint8 Local_u8SlaveAddressPacket = EEPROM_FIXED_ADDRESS | (EEPROM_A2_CONNECTION << 2u) | ((uint8) (Copy_u16LocationAddress >> 8u));

		/*Start the communication*/
		TWI_enSendStartCondition();

		/*Send Write Request*/
		TWI_enSendSlaveAddressWithWrite(Local_u8SlaveAddressPacket);

		/*Send the location address through data byte message*/
		TWI_enMasterWriteDataByte((uint8) Copy_u16LocationAddress);

		/*Repeat the start condition to change the operation to read*/
		TWI_enSendRepeatedStart();

		/*Send read Request*/
		TWI_enSendSlaveAddressWithRead(Local_u8SlaveAddressPacket);

		/*Read the data byte*/
		TWI_enMasterReadDataByte(Copy_pu8Data);

		/*Stop the communication*/
		TWI_enSendStopCondition();

	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	/*Return Error State*/
	return Local_u8ErrorState;
}
