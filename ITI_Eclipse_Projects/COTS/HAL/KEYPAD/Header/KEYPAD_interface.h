/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: KEYPAD_interface.h	**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/

/**
 * @file KEYPAD_interface.h
 * @author Ibrahim Tarek
 * @brief This file interfaces the keypad module functions.
 * @version 1.00
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

/**
 * @details The return of KEYPAD_u8GetPressedKey if no key is pressed.
 */
#define KEYPAD_u8NO_PRESSED_KEY		0xFF

/**
 * @brief Function to return data of the pressed key
 * @return data of the pressed key
 */
uint8 KEYPAD_u8GetPressedKey(void);

#endif


