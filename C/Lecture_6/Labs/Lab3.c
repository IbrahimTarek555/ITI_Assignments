/*Needed libraries*/
#include <stdio.h>

/*Functions' Prototypes*/
void Calc(int *Num1Ptr, int *Num2Ptr, int *SumPtr, int *SubPtr);

/*It is the main*/
int main()
{
	/*Define Variables*/
	int Num1;
	int Num2;
	int Sum;
	int Sub;
	
	/*Scan two numbers from the user*/
	printf("Please, Enter value 1: ");
	scanf("%d", &Num1);
	
	printf("Please, Enter value 2: ");
	scanf("%d", &Num2);
	
	/*Call a function to return the summation*/
	Calc(&Num1, &Num2, &Sum, &Sub);
	
	/*Print the results to the user*/
	printf("The result of summation is: %d\n", Sum);
	printf("The result of subtraction is: %d", Sub);

	/*Return to the operating system*/
	return 0;
}

/*Functions' Implementation*/
void Calc(int *Num1Ptr, int *Num2Ptr, int *SumPtr, int *SubPtr)
{
	/*Return Summation of the 2 numbers*/
	*SumPtr = *Num1Ptr + *Num2Ptr;
	
	/*Return Subtraction of the 2 numbers*/
	*SubPtr = *Num1Ptr - *Num2Ptr;
}