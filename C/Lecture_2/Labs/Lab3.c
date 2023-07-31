/*Include needed libraries*/
#include "stdio.h"

/*It's the main*/
int main()
{
	/*Define variables*/
	int Number;
	
	/*Scan a number from the user*/
	printf("Please, Enter a number: ");
	scanf("%d", &Number);
	
	/*Check the number and print the result*/
	if(Number == 0)
	{
		printf("You entered zero.");
	}
	else if(Number % 2 == 0)
	{
		printf("%d is even.", Number);
	}
	else
	{
		printf("%d is odd.", Number);
	}
	
	/*Return to the operating system*/
	return 0;
}