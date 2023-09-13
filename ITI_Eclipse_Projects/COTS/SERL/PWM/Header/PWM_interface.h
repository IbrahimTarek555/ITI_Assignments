/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: PWM_interface.h		**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/

/**
 * @file PWM_interface.h
 * @author Ibrahim Tarek
 * @brief This file interfaces the PWM service functions.
 * @version 1.00
 */

#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_

/*Copy_u8Timer1Ch Options*/
#define PWM_u8Timer1ChA		0u
#define PWM_u8Timer1ChB		1u

/**
 * @brief 				Function to set the frequency of timer 1, with making OCA and OCB disconnected.
 * @param Copy_u8Freq 	Frequency needed to set.
 * @return				Error State.
 */
uint8 PWM_u8SetFreq(uint8 Copy_u8Freq);

/**
 * @brief					Function to set the duty cycle for any of two timer 1 channels.
 * @param Copy_u8Timer1Ch	Timer 1 channel A or channel B.
 * @param Copy_u8Duty		Duty cycle.
 * @return					Error State.
 */
uint8 PWM_u8SetDuty(uint8 Copy_u8Timer1Ch, uint8 Copy_u8Duty);

/**
 * @brief Function to disable hardware PWM signal from OCA.
 */
void PWM_voidDisableChA(void);

/**
 * @brief Function to disable hardware PWM signal from OCB.
 */
void PWM_voidDisableChB(void);

/**
 * @brief 	Function to disable fast PWM mode from timer 1, this function also disable OCA and OCB.
 * @return 	Error State.
 */
uint8 PWM_voidDisable(void);

#endif
