/*Needed libraries*/
#include <stdio.h>

/*Functions' Prototypes*/
int Sum(int *NumbersArr, int ArrSize);

/*It is the main*/
int main()
{
	/*Define Variables*/
	int NumbersArr[20];
	int Result;
	
	/*Fill the array values*/
	for(int i = 0; i < 20; i++)
	{
		printf("Enter Number %d: ", (i + 1));
		scanf("%d", &NumbersArr[i]);
	}
	
	/*Call a function to calculate summation of the array*/
	Result = Sum(NumbersArr, 20);
	
	/*Print the summation of the array*/
	printf("Summation of the array is: %d.", Result);

	/*Return to the operating system*/
	return 0;
}

/*Functions' Implementation*/
int Sum(int *NumbersArr, int ArrSize)
{
	/*Define variables*/
	int Sum = 0;
	
	/*Calculate summation of the array*/
	for(int i = 0; i < ArrSize; i++)
	{
		Sum = Sum + NumbersArr[i];
	}
	
	/*Return the summation*/
	return Sum;
}