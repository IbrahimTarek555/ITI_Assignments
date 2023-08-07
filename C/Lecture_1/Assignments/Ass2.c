/*Include needed libraries*/
#include "stdio.h"

/*It's the main*/
int main(void)
{
	/*Define variables*/
	int Number1;
	int Number2;
	int Number3;

	/*Scan the 3 numbers from the user*/
	printf("Please, Enter number 1: ");
	scanf("%d", &Number1);
	
	printf("Please, Enter number 2: ");
	scanf("%d", &Number2);
	
	printf("Please, Enter number 3: ");
	scanf("%d", &Number3);
	
	/*Print Scanned numbers in reversed order*/
	printf("number 3: %d\n", Number3);
	printf("number 2: %d\n", Number2);
	printf("number 1: %d", Number1);
	
	/*Return to the operating system*/
	return 0;
}