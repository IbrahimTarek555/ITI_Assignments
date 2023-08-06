#include "STD_TYPES.h"
#include "DEFINES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "UART_interface.h"
#include "GIE_interface.h"
#include "TIMERS_interface.h"

#include "MOTOR_interface.h"

#include <util/delay.h>

//void Main_voidTimer0ISR(void);
void Main_voidReceiveNotificFunc(void);
void Main_voidMove(uint8 Copy_u8Direction, uint16 Copy_u16Duration);
void Main_voidStop(void);
void Main_voidTimer0ISR(void);

/*Define two DC motors*/
MOTOR_t Main_stMotor1;
MOTOR_t Main_stMotor2;

/*Define global variables*/
static uint8 Main_u8ReceivedData = 0u;
static uint8 Main_u8CarDirection;
static uint8 Main_u8MotorSpeed = 1u;

/*It is the main*/
void main(void)
{
	/*Initialize needed peripherals*/
	PORT_voidInit();
	USART_voidInit();

	/*Enable Global Interrupt*/
	GIE_voidEnable();

	/*Initialize Timer 0*/
	TIMER0_2_CFG_t Local_stTimer0;
	Local_stTimer0.ClkSelect = TIMER0_u8SYS_CLK_BY_8;
	Local_stTimer0.OCMode = OC_DISCONNECTED;
	Local_stTimer0.WGM = CTC;
	TIMER0_u8Init(&Local_stTimer0);
	TIMER0_voidSetCompValue(250);
	TIMERS_u8SetCallBack(TIMER0_COMP, Main_voidTimer0ISR);
	TIMERS_u8IntDisable(TIMER0_COMP);

	/*Initialize motors' pins*/
	Main_stMotor1.Pin1 = DIO_u8PIN0;
	Main_stMotor1.Pin2 = DIO_u8PIN1;
	Main_stMotor1.Port = DIO_u8PORTC;

	Main_stMotor2.Pin1 = DIO_u8PIN2;
	Main_stMotor2.Pin2 = DIO_u8PIN3;
	Main_stMotor2.Port = DIO_u8PORTC;

	/*Super Loop*/
	while(1)
	{
		/*Receive Character message from usart with asynchronous function*/
		USART_u8ReceiveBufferAsynch(&Main_u8ReceivedData, 1, Main_voidReceiveNotificFunc);

		/*Switch the char which received then take its corresponding order*/
		switch(Main_u8ReceivedData)
		{
		case 'F':
			Main_voidMove('F', 50);
			break;

		case 'B':
			Main_voidMove('B', 50);
			break;

		case 'R':
			Main_voidMove('R', 50);
			break;

		case 'L':
			Main_voidMove('L', 50);
			break;

		default:
			/*Do nothing*/
			break;
		}
	}
}



/*USART Receive ISR*/
void Main_voidReceiveNotificFunc(void)
{
	/*Do nothing*/
}

/*Function to move the car in all directions*/
void Main_voidMove(uint8 Copy_u8Direction, uint16 Copy_u16Duration)
{
	/*Send the direction to the timer ISR*/
	Main_u8CarDirection = Copy_u8Direction;

	/*Enable the timer*/
	TIMERS_u8IntEnable(TIMER0_COMP);

	/*Delay for the step time*/
	_delay_ms(Copy_u16Duration);

	/*Stop the vehicle*/
	Main_voidStop();
}

void Main_voidStop(void)
{
	/*Disable the timer*/
	TIMERS_u8IntDisable(TIMER0_COMP);

	/*Stop the motors*/
	MOTOR_u8Stop(&Main_stMotor1);
	MOTOR_u8Stop(&Main_stMotor2);
}

/*Timer 0 ISR*/
void Main_voidTimer0ISR()
{
	/*Define variables*/
	static uint8 Local_u8Counter = 0u;

	/*Increment the counter of entering the ISR*/
	Local_u8Counter++;

	/*Move the car according to the needed speed and direction*/
	if(Local_u8Counter == Main_u8MotorSpeed)
	{
		if(Main_u8CarDirection == 'F')
		{
			MOTOR_u8RotateCCW(&Main_stMotor1);
			MOTOR_u8RotateCCW(&Main_stMotor2);
		}
		else if(Main_u8CarDirection == 'B')
		{
			MOTOR_u8RotateCW(&Main_stMotor1);
			MOTOR_u8RotateCW(&Main_stMotor2);
		}
		else if(Main_u8CarDirection == 'R')
		{
			MOTOR_u8RotateCW(&Main_stMotor2);
			MOTOR_u8RotateCCW(&Main_stMotor1);
		}
		else if(Main_u8CarDirection == 'L')
		{
			MOTOR_u8RotateCCW(&Main_stMotor2);
			MOTOR_u8RotateCW(&Main_stMotor1);
		}
	}

	/*Every period time stop the motors and zero the counter*/
	else if(Local_u8Counter == 20u)
	{
		MOTOR_u8Stop(&Main_stMotor1);
		MOTOR_u8Stop(&Main_stMotor2);
		Local_u8Counter = 0u;
	}
}
