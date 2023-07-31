/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: TWI_interface.h		**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/

/**
 * @file TWI_interface.h
 * @author Ibrahim Tarek
 * @brief This file interfaces the TWI module functions.
 * @version 1.00
 */

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_


typedef enum
{
	NO_ERROR,
	FETAL_ERROR,
	RESERVED_ADDRESS_ERROR,
	START_CONDITION_ERROR,
	REP_START_CONDITION_ERROR,
	SLAVE_ADD_WITH_WR_ERROR,
	SLAVE_ADD_WITH_RD_ERROR,
	MASTER_WR_BYTE_WITH_ACK_ERROR,
	MASTER_RD_BYTE_WITH_ACK_ERROR,
	NULL_PTR_ERROR
}
TWI_ERROR_STATUS_t;

TWI_ERROR_STATUS_t TWI_enMasterInit(uint8 Copy_u8Address);
TWI_ERROR_STATUS_t TWI_enSlaveInit(uint8 Copy_u8Address);

TWI_ERROR_STATUS_t TWI_enSendStartCondition(void);

TWI_ERROR_STATUS_t TWI_enSendRepeatedStart(void);

TWI_ERROR_STATUS_t TWI_enSendSlaveAddressWithWrite(uint8 Copy_u8SlaveAddress);
TWI_ERROR_STATUS_t TWI_enSendSlaveAddressWithRead(uint8 Copy_u8SlaveAddress);

TWI_ERROR_STATUS_t TWI_enMasterWriteDataByte(uint8 Copy_u8Data);
TWI_ERROR_STATUS_t TWI_enMasterReadDataByte(uint8 *Copy_u8Data);

void TWI_enSendStopCondition(void);

#endif
