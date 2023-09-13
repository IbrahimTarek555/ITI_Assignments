/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: SSD_interface.h		**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/

/**
 * @file SSD_interface.h
 * @author Ibrahim Tarek
 * @brief This file interfaces the SSD module functions.
 * @version 1.00
 */

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

/*SSD_t.Type Options*/
#define SSD_u8ANODE		1u
#define SSD_u8CATHODE	2u

/**
 * @brief 				Struct to configure the SSD information.
 * @param Type 			The type of SSD.
 * @param Port 			Port to which SSD is connected.
 * @param LedPin 		The first pin connected with the port, options is: 0 or 1.
 * @param EnablePort 	Port to which the enable pin is connected.
 * @param EnablePin 	Pin to which the enable pin is connected.
 */
typedef struct
{
	uint8 Type;
	uint8 Port;
	uint8 LedPin;
	uint8 EnablePort;
	uint8 EnablePin;
}SSD_t;

/**
 * @brief 							Function to display a number into the display.
 * @param Copy_pstSSDInformation	Pointer to struct that carries the SSD information.
 * @param Copy_u8Number				Number needed to be displayed.
 * @return							Error State.
 */
uint8 SSD_u8SetNumber(const SSD_t *Copy_pstSSDInformation, uint8 Copy_u8Number);

/**
 * @brief 							Function to disable a SSD.
 * @param Copy_pstSSDInformation	Pointer to struct that carries the SSD information.
 * @return							Error State.
 */
uint8 SSD_u8Disable(const SSD_t *Copy_pstSSDInformation);

#endif
