/*Include needed libraries*/
#include "stdio.h"

/*It's the main*/
int main()
{
	/*Define variables*/
	int x = 0;
	int Sum = 0;
	float Avg;
	
	/*Scan the 10 numbers from the user and calculate their sum*/
	for(int i = 0; i < 10; i++)
	{
		printf("Enter Number %d: ", i);
		scanf("%d", &x);
		
		Sum = Sum + x;
	}
	
	/*Calculate the average number*/
	Avg = Sum / 10.0;
	
	/*Print Results to the user*/
	printf("Summation is: %d\n", Sum);
	printf("Average number is: %f", Avg);
	
	/*Return to the operating system*/
	return 0;
}