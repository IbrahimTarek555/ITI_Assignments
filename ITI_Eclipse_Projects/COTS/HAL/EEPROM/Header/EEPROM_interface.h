/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: EEPROM_interface.h	**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/

/**
 * @file EEPROM_interface.h
 * @author Ibrahim Tarek
 * @brief This file interfaces the EEPROM module functions.
 * @version 1.00
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

/**
 * @brief 							Function to write a byte into the EEPROM.
 * @param Copy_u16LocationAddress 	Address to write into.
 * @param Copy_u8Data				Byte wanted to be written.
 * @return							Error state.
 */
uint8 EEPROM_u8WriteDataByte(uint16 Copy_u16LocationAddress, uint8 Copy_u8Data);

/**
 * @brief 							Function to read a byte from the EEPROM.
 * @param Copy_u16LocationAddress 	Address to read from.
 * @param Copy_pu8Data				Pointer to return the byte data.
 * @return							Error state.
 */
uint8 EEPROM_u8ReadDataByte(uint16 Copy_u16LocationAddress, uint8 *Copy_pu8Data);

#endif
