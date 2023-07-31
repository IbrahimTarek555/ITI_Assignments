/*Needed libraries*/
#include <stdio.h>

/*Functions' Prototypes*/
int Sum(int *Num1Ptr, int *Num2Ptr);

/*It is the main*/
int main()
{
	/*Define Variables*/
	int Num1;
	int Num2;
	int Result;
	
	/*Scan two numbers from the user*/
	printf("Please, Enter value 1: ");
	scanf("%d", &Num1);
	
	printf("Please, Enter value 2: ");
	scanf("%d", &Num2);
	
	/*Call a function to return the summation*/
	Result = Sum(&Num1, &Num2);
	
	/*Print the summation to the user*/
	printf("The result is: %d", Result);
	
	/*Return to the operating system*/
	return 0;
}

/*Functions' Implementation*/
int Sum(int *Num1Ptr, int *Num2Ptr)
{
	/*Return Summation of the 2 numbers*/
	return (*Num1Ptr + *Num2Ptr);
}