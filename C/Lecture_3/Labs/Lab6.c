/*Include needed libraries*/
#include "stdio.h"

/*It's the main*/
int main()
{
	/*Define a variable*/
	int Number; 
	int TempNumber;
	int Factorial = 1;
	
	/*Scan the number from the user*/
	printf("Please, Enter the number: ");
	scanf("%d", &Number);
	TempNumber = Number;
	
	/*Calculate the factorial*/
	do
	{
		Factorial = Factorial * TempNumber;
		TempNumber--;
	}
	while(TempNumber != 0);
	
	/*Print the factorial*/
	printf("Factorial of %d is %d", Number, Factorial);
	
	/*Return to the operating system*/
	return 0;
}