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

/**
 * @brief Enum has macros of TWI error states.
 */
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

/**
 * @brief 					Function to initialize the TWI peripheral as master.
 * @param Copy_u8Address	Address which represent the peripheral.
 * @return					Error State.
 */
TWI_ERROR_STATUS_t TWI_enMasterInit(uint8 Copy_u8Address);

/**
 * @brief					Function to initialize the TWI peripheral as slave.
 * @param Copy_u8Address	Address which represent the peripheral.
 * @return					Error State.
 */
TWI_ERROR_STATUS_t TWI_enSlaveInit(uint8 Copy_u8Address);

/**
 * @brief 	Function to send start condition.
 * @return	Error State.
 */
TWI_ERROR_STATUS_t TWI_enSendStartCondition(void);

/**
 * @brief	Function to send a repeated start.
 * @return	Error State.
 */
TWI_ERROR_STATUS_t TWI_enSendRepeatedStart(void);

/**
 * @brief						Function to send slave address with write.
 * @param Copy_u8SlaveAddress	Slave Address.
 * @return						Error state.
 */
TWI_ERROR_STATUS_t TWI_enSendSlaveAddressWithWrite(uint8 Copy_u8SlaveAddress);

/**
 * @brief						Function to send slave address with read.
 * @param Copy_u8SlaveAddress	Slave Address.
 * @return						Error State.
 */
TWI_ERROR_STATUS_t TWI_enSendSlaveAddressWithRead(uint8 Copy_u8SlaveAddress);

/**
 * @brief				Function to send data byte.
 * @param Copy_u8Data	Data Byte.
 * @return				Error State.
 */
TWI_ERROR_STATUS_t TWI_enMasterWriteDataByte(uint8 Copy_u8Data);

/**
 * @brief 				Function to read data byte.
 * @param Copy_pu8Data	Pointer to return the data byte read.
 * @return				Error State.
 */
TWI_ERROR_STATUS_t TWI_enMasterReadDataByte(uint8 *Copy_pu8Data);

/**
 * @brief Function to send stop condition.
 */
void TWI_enSendStopCondition(void);

#endif
