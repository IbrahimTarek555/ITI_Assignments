/*Include needed libraries*/
#include "stdio.h"

/*It's the main*/
int main()
{
	/*Define variables*/
	int Num1;
	int Num2;
	int Result;
	
	/*Keep in the program until the user close the window*/
	while(1)
	{
		/*Ask the user to enter 2 numbers*/
		printf("Please, Enter the first number: ");
		scanf("%d", &Num1);

		printf("Please, Enter the second number: ");
		scanf("%d", &Num2);
		
		/*Calculate the 2 numbers summation then print it*/
		Result = Num1 + Num2;
		printf("The result is %d.\n\n", Result);		
	}
	
	/*Return to the operating system*/
	return 0;
}