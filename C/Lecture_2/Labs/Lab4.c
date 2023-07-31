/*Include needed libraries*/
#include "stdio.h"

/*It's the main*/
int main()
{
	/*Define variables*/
	int Result;
	
	/*Scan a Result from the user*/
	printf("Please, Enter the result: ");
	scanf("%d", &Result);
	
	/*Check for the rating and print it*/
	if((Result < 0) || (Result > 100))
	{
		printf("Invalid Result.");
	}
	else if(Result < 50)
	{
		printf("Your rating is failed.");
	}
	else if(Result < 65)
	{
		printf("Your rating is pass.");
	}
	else if(Result < 75)
	{
		printf("Your rating is good.");
	}
	else if(Result < 85)
	{
		printf("Your rating is very good");
	}
	else
	{
		printf("Your rating is excellent");
	}
	
	/*Return to the operating system*/
	return 0;
}