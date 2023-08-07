/*Include needed libraries*/
#include "stdio.h"

/*It's the main*/
int main()
{
	/*Decalre variables*/
	int Number1;
	int Number2;
	int AndResult;
	int OrResult;
	int XorResult;
	int ShiftRightResult;
	int ShiftLeftResult;
	
	/*Scan the 2 numbers from the user*/
	printf("Please, Enter number 1: ");
	scanf("%d", &Number1);
	
	printf("Please, Enter number 2: ");
	scanf("%d", &Number2);
	
	/*Calculate the operations' results*/
	AndResult = Number1 & Number2;
	OrResult = Number1 | Number2;
	XorResult = Number1 ^ Number2;
	ShiftRightResult = Number1 >> 1;
	ShiftLeftResult = Number2 << 2;
	
	/*Print the operations' results*/
	printf("%d & %d = %d\n", Number1, Number2, AndResult);
	printf("%d | %d = %d\n", Number1, Number2, OrResult);
	printf("%d ^ %d = %d\n", Number1, Number2, XorResult);
	printf("%d >> 1 = %d\n", Number1, ShiftRightResult);
	printf("%d << 2 = %d", Number2, ShiftLeftResult);
	
	/*Return to the operating system*/
	return 0;
}