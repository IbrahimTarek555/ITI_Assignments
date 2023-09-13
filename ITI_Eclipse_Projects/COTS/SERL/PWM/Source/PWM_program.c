/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: PWM_program.c			**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/

/**
 * @file PWM_program.c
 * @author Ibrahim Tarek
 * @brief This file implements the PWM service functions.
 * @version 1.00
 */

#include "../../../Common/STD_TYPES.h"
#include "../../../Common/BIT_MATH.h"
#include "../../../Common/DEFINES.h"

#include "../../../MCAL/TIMERS/Header/TIMERS_interface.h"

#include "../Header/PWM_interface.h"
#include "../Header/PWM_config.h"
#include "../Header/PWM_private.h"

/*Define global variables*/
static uint8 PWM_u8SetFlag = UNINITIALZED;
static uint16 PWM_u16OvfValue = 0u;
static uint8 PWM_u8InitializedFlagChA = UNINITIALZED;
static uint8 PWM_u8InitializedFlagChB = UNINITIALZED;
static TIMER1_CFG_t *PWM_pstTimer1Cfg = NULL;

/**
 * @brief 				Function to set the frequency of timer 1, with making OCA and OCB disconnected.
 * @param Copy_u8Freq 	Frequency needed to set.
 * @return				Error State.
 */
uint8 PWM_u8SetFreq(uint8 Copy_u8Freq)
{
	/*Define Variables*/
	uint16 Local_u16OvfValue = ((f32) 1 / (f32) Copy_u8Freq) * ((f32) 1000000);
	uint8 Local_u8ErrorState = OK;
	uint8 Local_u8ErrorFounder = OK;

	/*Set the initialized flag*/
	PWM_u8SetFlag = INITIALIZED;

	/*Make the OVF value a global value*/
	PWM_u16OvfValue = Local_u16OvfValue;

	/*Set Timer 1 Configurations*/
	static TIMER1_CFG_t Local_stTimer1Cfg;
	Local_stTimer1Cfg.ClkSelect = TIMER1_u8SYS_CLK_BY_8;
	Local_stTimer1Cfg.WGM = FAST_PWM_ICR1;
	Local_stTimer1Cfg.OCAMode = OC_DISCONNECTED;
	Local_stTimer1Cfg.OCBMode = OC_DISCONNECTED;

	/*Make the Timer 1 configuration struct as a global struct*/
	PWM_pstTimer1Cfg = &Local_stTimer1Cfg;

	/*Initialize Timer 1*/
	Local_u8ErrorFounder = TIMER1_u8Init(&Local_stTimer1Cfg);

	if(Local_u8ErrorFounder == OK)
	{
		/*Set Timer 1 Overflow value*/
		TIMER1_voidSetInputCaptValue(Local_u16OvfValue);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	/*Return Error State*/
	return Local_u8ErrorState;
}

/**
 * @brief					Function to set the duty cycle for any of two timer 1 channels.
 * @param Copy_u8Timer1Ch	Timer 1 channel A or channel B.
 * @param Copy_u8Duty		Duty cycle.
 * @return					Error State.
 */
uint8 PWM_u8SetDuty(uint8 Copy_u8Timer1Ch, uint8 Copy_u8Duty)
{
	/*Define Variables*/
	uint8 Local_u8ErrorState = OK;
	uint16 Local_u16CompareValue = 0u;

	if(PWM_u8SetFlag == INITIALIZED)
	{
		/*Validate Duty Percentage*/
		if(Copy_u8Duty <= 100u)
		{
			/*Calculate Compare Value*/
			Local_u16CompareValue = (uint16) (((uint32) Copy_u8Duty) * ((uint32) PWM_u16OvfValue)) / 100u;

			/*Switch from two channels*/
			switch(Copy_u8Timer1Ch)
			{
			case PWM_u8Timer1ChA:
				if(PWM_u8InitializedFlagChA == UNINITIALZED)
				{
					TIMER1_u8SetCompOutModeChA(PWM_pstTimer1Cfg, NON_INVERTED_PWM);
					PWM_u8InitializedFlagChA = INITIALIZED;
				}
				TIMER1_voidSetCompValueChA(Local_u16CompareValue);
				break;

			case PWM_u8Timer1ChB:
				if(PWM_u8InitializedFlagChB == UNINITIALZED)
				{
					TIMER1_u8SetCompOutModeChB(PWM_pstTimer1Cfg, NON_INVERTED_PWM);
					PWM_u8InitializedFlagChB = INITIALIZED;
				}
				TIMER1_voidSetCompValueChB(Local_u16CompareValue);
				break;

			default: Local_u8ErrorState = NOK;
			}
		}
		else
		{
			Local_u8ErrorState = NOK;
		}
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	/*Return Error State*/
	return Local_u8ErrorState;
}

/**
 * @brief Function to disable hardware PWM signal from OCA.
 */
void PWM_voidDisableChA(void)
{
	/*Disconnect Channel A*/
	TIMER1_u8SetCompOutModeChA(PWM_pstTimer1Cfg, OC_DISCONNECTED);

	/*Raise the flag*/
	PWM_u8InitializedFlagChA = UNINITIALZED;
}

/**
 * @brief Function to disable hardware PWM signal from OCB.
 */
void PWM_voidDisableChB(void)
{
	/*Disconnect Channel B*/
	TIMER1_u8SetCompOutModeChB(PWM_pstTimer1Cfg, OC_DISCONNECTED);

	/*Raise the flag*/
	PWM_u8InitializedFlagChB = UNINITIALZED;
}

/**
 * @brief 	Function to disable fast PWM mode from timer 1, this function also disable OCA and OCB.
 * @return 	Error State.
 */
uint8 PWM_u8Disable(void)
{
	/*Define Variables*/
	uint8 Local_u8ErrorState = OK;

	if(PWM_u8SetFlag == INITIALIZED)
	{
		/*Disable Timer 1*/
		TIMERS_u8Disable(TIMER1);

		/*Raise the set flag*/
		PWM_u8SetFlag = UNINITIALZED;

		/*Disable channel A*/
		PWM_voidDisableChA();

		/*Disable channel B*/
		PWM_voidDisableChB();
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	/*Return Error State*/
	return Local_u8ErrorState;
}
