/*Include needed libraries*/
#include "stdio.h"

/*Functions' Prototypes*/
int GetMax(int Numbers[]);
int GetMin(int Numbers[]);

/*It's the main*/
int main()
{
	/*Define variables*/
	int Numbers[4];
	int MaxNumber;
	int MinNumber;
	
	/*Scan 4 numbers from the user*/
	for(int i = 0; i < 4; i++)
	{
		printf("Enter Number %d: ", (i + 1));
		scanf("%d", &Numbers[i]);
	}

	/*Get the maximum and minimum numbers of the 4 inputed numbers*/
	MaxNumber = GetMax(Numbers);
	MinNumber = GetMin(Numbers);
	
	/*Print the results*/
	printf("Maximum Number is %d.\n", MaxNumber);
	printf("Minimum Number is %d.", MinNumber);
	/*Return to the operating system*/
	return 0;
}

/*Functions' implementation*/
int GetMax(int Numbers[])
{
	/*Define variables*/
	int MaxNumber = 0;
	
	/*Search for the maximum number*/
	for(int i = 0; i < 4; i++)
	{
		if(Numbers[i] > MaxNumber)
		{
			MaxNumber = Numbers[i];
		}
	}
	
	/*Return maximum number*/
	return MaxNumber;
}

int GetMin(int Numbers[])
{
	/*Define variables*/
	int MinNumber = Numbers[0];
	int TempNumber;
	
	/*Search for the maximum number*/
	for(int i = 1; i < 4; i++)
	{
		if(Numbers[i] < MinNumber)
		{
			MinNumber = Numbers[i];
		}
	}
	
	/*Return maximum number*/
	return MinNumber;
}