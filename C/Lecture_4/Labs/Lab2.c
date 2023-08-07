/*Include needed libraries*/
#include "stdio.h"

/*Functions' Prototypes*/
void SwapGlobal(void);

/*Define global variables*/
int x = 10; 
int y = 20;

/*It's the main*/
int main()
{
	/*Print 2 Numbers before swapping*/
	printf("x before swap = %d\n", x);
	printf("y before swap = %d\n\n", y);
	
	/*Swap the two variables*/
	SwapGlobal();
	
	/*Print 2 Numbers after swapping*/
	printf("x after swap = %d\n", x);
	printf("y after swap = %d", y);

	/*Return to the operating system*/
	return 0;
}

/*Functions' Implementation*/
void SwapGlobal(void)
{
	/*Swap two variables*/
	x = x + y;
	y = x - y;
	x = x - y;
}
