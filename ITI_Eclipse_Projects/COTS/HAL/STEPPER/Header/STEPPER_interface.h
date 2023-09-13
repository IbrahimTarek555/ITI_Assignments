/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: STEPPER_interface.h	**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/

/**
 * @file STEPPER_interface.h
 * @author Ibrahim Tarek
 * @brief This file interfaces the stepper module functions.
 * @version 1.00
 */

#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_

/*Copy_u8Direction Options*/
#define STEPPER_u8ROTATE_CW		1
#define STEPPER_u8ROTATE_CCW	2

/*Copy_u8Speed Options*/
#define STEPPER_u8SPEED_SLOW	10u
#define STEPPER_u8SPEED_MEDIUM	6u
#define STEPPER_u8SPEED_FAST	2u

/**
 * @brief 			Struct to configure the stepper information.
 * @param Port 		Port to which the stepper pins are connected.
 * @param BluePin 	Pin to which the blue wire is connected.
 * @param PinkPin 	Pin to which the pink wire is connected.
 * @param YellowPin Pin to which the yellow wire is connected.
 * @param OrangePin Pin to which the orange wire is connected.
 */
typedef struct
{
	uint8 Port;
	uint8 BluePin;
	uint8 PinkPin;
	uint8 YellowPin;
	uint8 OrangePin;
}STEPPER_t;

/**
 * @brief					Function to rotate the stepper with a fixed speed (medium) and specific angle.
 * @param Copy_pstMotorInfo	Pointer to struct which carries the stepper information.
 * @param Copy_u16Angle		Angle to rotate with.
 * @param Copy_u8Direction	Direction to rotate with.
 * @return					Error State.
 */
uint8 STEPPER_u8RotateWithMidiumSpeed(const STEPPER_t *Copy_pstMotorInfo, uint16 Copy_u16Angle, uint8 Copy_u8Direction);

/**
 * @brief					Function to rotate the stepper with variable angle and speed.
 * @param Copy_pstMotorInfo	Pointer to struct which carries the stepper information.
 * @param Copy_u16Angle		Angle to rotate with.
 * @param Copy_u8Direction	Direction to rotate with.
 * @param Copy_u8Speed		Speed to rotate with.
 * @return					Error State.
 */
uint8 STEPPER_u8RotateWithAngle(const STEPPER_t *Copy_pstMotorInfo, uint16 Copy_u16Angle, uint8 Copy_u8Direction, uint8 Copy_u8Speed);

/**
 * @brief						Function to rotate the stepper with variable speed and number of complete rolls.
 * @param Copy_pstMotorInfo		Pointer to struct which carries the stepper information.
 * @param Copy_u8RollsNumber	Number of rolls.
 * @param Copy_u8Direction		Direction to rotate with.
 * @param Copy_u8Speed			Speed to rotate with.
 * @return						Error State.
 */
uint8 STEPPER_u8RotateWithRolls(const STEPPER_t *Copy_pstMotorInfo, uint8 Copy_u8RollsNumber, uint8 Copy_u8Direction, uint8 Copy_u8Speed);


#endif
