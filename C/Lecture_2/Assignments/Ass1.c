/*Include needed libraries*/
#include "stdio.h"

/*It's the main*/
int main()
{
	/*Define variables*/
	int i;
	int SearchNumber;
	int NumbersArr[10];
	
	/*Scan 10 numbers from the user*/
	for(i = 0; i < 10; i++)
	{
		printf("Enter number %d: ", i);
		scanf("%d", &NumbersArr[i]);
	}
	
	/*Scan the search number*/
	printf("Enter the value to search: ");
	scanf("%d", &SearchNumber);
	
	/*Search for the number*/
	for(i = 0; i < 10; i++)
	{
		if(NumbersArr[i] == SearchNumber)
		{
			printf("Value is exist at element number: %d", i);
			break;
		}
	}
	
	/*Check if the number does not exist*/
	if(i == 10)
	{
		printf("Number does not exist.");
	}
	
	/*Return to the operating system*/
	return 0;
}