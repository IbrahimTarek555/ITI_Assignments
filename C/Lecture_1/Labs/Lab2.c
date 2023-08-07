/*Include needed libraries*/
#include "stdio.h"

/*It's the main*/
int main()
{
	/*Decalre a variable*/
	int Number;
	
	/*Scan a value from the user*/
	printf("Please, Enter the value: ");
	scanf("%d", &Number);
	
	/*Print the value scanned*/
	printf("The value you entered is: %d", Number);
	
	/*Return to the operating system*/
	return 0;
}