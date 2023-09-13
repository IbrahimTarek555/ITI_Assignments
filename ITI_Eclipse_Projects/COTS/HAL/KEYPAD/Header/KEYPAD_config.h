/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: KEYPAD_config.h		**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/

/**
 * @file KEYPAD_config.h
 * @author Ibrahim Tarek
 * @brief This file configures the keypad module in prebuild configuration method.
 * @version 1.00
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

/**
 * @details Configure the keypad rows number.
 */
#define KEYPAD_u8ROWS_NUM			4u

/**
 * @details Configure the keypad columns number.
 */
#define KEYPAD_u8COLUMNS_NUM		4u

/**
 * @details Configure the port number to which rows are connected,
 * 			Options: 1- DIO_u8PORTA
 * 					 2- DIO_u8PORTB
 * 					 3- DIO_u8PORTC
 * 					 4- DIO_u8PORTD
 */
#define KEYPAD_u8ROWS_PORT			DIO_u8PORTA

/**
 * @details Configure pins to connect rows pins starting from row 0 till rows number,
 * 			Options: 1- DIO_u8PIN0
 * 					 2- DIO_u8PIN1
 * 					 3- DIO_u8PIN2
 * 					 4- DIO_u8PIN3
 * 					 5- DIO_u8PIN4
 * 					 6- DIO_u8PIN5
 * 					 7- DIO_u8PIN6
 * 					 8- DIO_u8PIN7
 */
#define KEYPAD_u8ROWS_ARR			{DIO_u8PIN0,\
									 DIO_u8PIN1,\
									 DIO_u8PIN2,\
									 DIO_u8PIN3}

/**
 * @details Configure the port number to which columns are connected,
 * 			Options: 1- DIO_u8PORTA
 * 					 2- DIO_u8PORTB
 * 					 3- DIO_u8PORTC
 * 					 4- DIO_u8PORTD
 */
#define KEYPAD_u8COLUMNS_PORT		DIO_u8PORTA

/**
 * @details Configure pins to connect columns pins starting from row 0 till rows number,
 * 			Options: 1- DIO_u8PIN0
 * 					 2- DIO_u8PIN1
 * 					 3- DIO_u8PIN2
 * 					 4- DIO_u8PIN3
 * 					 5- DIO_u8PIN4
 * 					 6- DIO_u8PIN5
 * 					 7- DIO_u8PIN6
 * 					 8- DIO_u8PIN7
 */
#define KEYPAD_u8COLUMNS_ARR		{DIO_u8PIN5,\
									 DIO_u8PIN4,\
									 DIO_u8PIN6,\
									 DIO_u8PIN7}

/**
 * @details Configure data that will returned if its corresponding button is pressed,
 * 			This array length is KEYPAD_u8ROWS_NUM x KEYPAD_u8COLUMNS_NUM.
 * @note	You are free to set a value from 0 till 254,
 * 			255 is reserved for a macro (KEYPAD_u8NO_PRESSED_KEY).
 */
#define KEYPAD_u8BUTTON_ARR			{{1,  2,  3,  10},\
									 {4,  5,  6,  11},\
									 {7,  8,  9,  12},\
									 {13, 14, 15, 16}}

#endif
