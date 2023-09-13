/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: SWITCH_interface.h	**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/

/**
 * @file SWITCH_interface.h
 * @author Ibrahim Tarek
 * @brief This file interfaces the switch module functions.
 * @version 1.00
 */

#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

/*SWITCH_t.Type Options*/
#define SWITCH_u8PULL_UP	1u
#define SWITCH_u8PULL_DOWN	2u

/*State that will be returned through Copy_pu8State*/
#define SWITCH_u8PRESSED	1u
#define SWITCH_u8RELEASED	2u

/**
 * @brief 		Struct type to configure the switch information.
 * @param Type 	Type of the switch pull.
 * @param Port	Port to which the switch is connected.
 * @param Pin	Pin to which the swithc is connected.
 */
typedef struct
{
	uint8 Type;
	uint8 Port;
	uint8 Pin;
}SWITCH_t;

/**
 * @brief 							Function to get the state of a button.
 * @param Copy_pstSwitchInformation	Pointer to struct which carries the button information.
 * @param Copy_pu8State				Pointer to return the state.
 * @return							Error State.
 */
uint8 SWITCH_u8GetState(const SWITCH_t *Copy_pstSwitchInformation, uint8 *Copy_pu8State);

#endif
