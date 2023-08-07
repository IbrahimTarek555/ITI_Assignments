#include "../Common/STD_TYPES.h"
#include "../Common/DEFINES.h"
#include "../Common/BIT_MATH.h"

#include "../MCAL/DIO/Header/DIO_interface.h"

void main()
{

	DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN7, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTB, DIO_u8PIN7, DIO_u8PIN_HIGH);


	while(1)
	{

	}
}
