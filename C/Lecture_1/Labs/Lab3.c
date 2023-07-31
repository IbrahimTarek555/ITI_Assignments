/*Include needed libraries*/
#include "stdio.h"

/*It's the main*/
int main()
{
	/*Decalre variables*/
	int Number1;
	int Number2;
	int Sum;
	int Multi;
	
	/*Scan the 2 numbers from the user*/
	printf("Please, Enter number 1: ");
	scanf("%d", &Number1);
	
	printf("Please, Enter number 2: ");
	scanf("%d", &Number2);
	
	/*Calculate the numbers summation and multiplication*/
	Sum = Number1 + Number2;
	Multi = Number1 * Number2;
	
	/*Print Summation and Multiplication*/
	printf("%d + %d = %d\n", Number1, Number2, Sum);
	printf("%d * %d = %d", Number1, Number2, Multi);
	
	/*Return to the operating system*/
	return 0;
}