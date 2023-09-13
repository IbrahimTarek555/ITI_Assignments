/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: SCHED_interface.h		**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/

/**
 * @file SCHED_interface.h
 * @author Ibrahim Tarek
 * @brief This file interfaces the SCHED service functions.
 * @version 1.00
 */

#ifndef SCHED_INTERFACE_H_
#define SCHED_INTERFACE_H_

/*Copy_u8Repeat Options*/
#define SCHED_u8ONCE	0u
#define SCHED_u8Repeat	1u

/**
 * @brief 					Function to schedule a function to be executed after a period of time.
 * @param Copy_u32Time		Time required to delay the function execution.
 * @param Copy_u8Repeat		Flag to know function needed to be repeated or not.
 * @param Copy_pvFunction	Pointer to the function.
 * @return					Error State.
 */
uint8 SCHED_u8ScheduleMs(uint32 Copy_u32Time, uint8 Copy_u8Repeat, void (*Copy_pvFunction)(void));

/**
 * @brief 	Function to disable the scheduling function.
 * @return	Error State.
 */
uint8 SCHED_u8Disable(void);

#endif
