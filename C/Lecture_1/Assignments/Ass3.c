/*Include needed libraries*/
#include "stdio.h"

/*It's the main*/
int main()
{
	/*Decalre variables*/
	int Number1;
	int Number2;
	int SumResult;
	int SubResult;
	int AndResult;
	int OrResult;
	int XorResult;
	
	/*Scan the 2 numbers from the user*/
	printf("Please, Enter number a: ");
	scanf("%d", &Number1);
	
	printf("Please, Enter number b: ");
	scanf("%d", &Number2);
	
	/*Calculate the operations' results*/
	SumResult = Number1 + Number2;
	SubResult = Number1 - Number2;
	AndResult = Number1 & Number2;
	OrResult = Number1 | Number2;
	XorResult = Number1 ^ Number2;
	
	/*Print the operations' results*/
	printf("%d + %d = %d\n", Number1, Number2, SumResult);
	printf("%d - %d = %d\n", Number1, Number2, SubResult);
	printf("%d & %d = %d\n", Number1, Number2, AndResult);
	printf("%d | %d = %d\n", Number1, Number2, OrResult);
	printf("%d ^ %d = %d\n", Number1, Number2, XorResult);
	
	/*Return to the operating system*/
	return 0;
}