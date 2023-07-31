/*Include needed libraries*/
#include "stdio.h"

/*It's the main*/
int main()
{
	/*Define a variable*/
	char x;
	
	/*Print the true value*/
	x = 1 || 0;
	printf("True value in GCC = %d\n", x);
	
	/*Print the true value*/
	x = 1 && 0;
	printf("False value in GCC = %d", x);
	
	/*Return to the operating system*/
	return 0;
}