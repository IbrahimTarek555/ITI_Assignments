/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: LED_interface.h		**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/

/**
 * @file LED_interface.h
 * @author Ibrahim Tarek
 * @brief This file interfaces the LED module functions.
 * @version 1.00
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

/*LED_t.Type Options*/
#define LED_u8ACTIVE_HIGH	1u
#define LED_u8ACTIVE_LOW	2u

/**
 * @brief 		Struct type for configure the LED information.
 * @param Type 	The LED type.
 * @param Port 	The port to which the LED is connected.
 * @param Pin 	The pin to which the LED is connected.
 */
typedef struct
{
	uint8 Type;
	uint8 Port;
	uint8 Pin;
}LED_t;

/**
 * @brief 							Function to turn on a LED.
 * @param Copy_pledtLEDInformation	Pointer to a struct which carries the LED data.
 * @return 						  	Error state.
 */
uint8 LED_u8On(const LED_t *Copy_pstLEDInformation);

/**
 * @brief 							Function to turn off a LED.
 * @param Copy_pledtLEDInformation	Pointer to a struct which carries the LED data.
 * @return 						  	Error state.
 */
uint8 LED_u8Off(const LED_t *Copy_pstLEDInformation);

/**
 * @brief 							Function to toggle a LED.
 * @param Copy_pledtLEDInformation	Pointer to a struct which carries the LED data.
 * @return 						  	Error state.
 */
uint8 LED_u8Toggle(const LED_t *Copy_pstLEDInformation);

#endif
