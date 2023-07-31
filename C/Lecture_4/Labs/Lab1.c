/*Include needed libraries*/
#include "stdio.h"

/*Functions' Prototypes*/
int Get_Max(int Num1, int Num2);

/*It's the main*/
int main()
{
	/*Define variables*/
	int Num1;
	int Num2;
	int MaxNumber;
	
	/*Scan two numbers from the user*/
	printf("Please, Enter value 1: ");
	scanf("%d", &Num1);
	
	printf("Please, Enter value 2: ");
	scanf("%d", &Num2);
	
	/*Call a function to return the bigger number*/
	MaxNumber = Get_Max(Num1, Num2);
	
	/*Print the bigger number to the user*/
	printf("Tha maximum value is: %d", MaxNumber);
	
	/*Return to the operating system*/
	return 0;
}

/*Functions' Implementation*/
int Get_Max(int Num1, int Num2)
{
	/*Define Variables*/
	int MaxNumber;
	
	/*Get the maximum number*/
	if(Num1 > Num2)
	{
		MaxNumber = Num1;
	}
	else
	{
		MaxNumber = Num2;
	}
	
	/*Return the maximum number*/
	return MaxNumber;
}