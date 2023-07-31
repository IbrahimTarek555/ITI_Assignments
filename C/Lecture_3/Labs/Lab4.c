/*Include needed libraries*/
#include "stdio.h"

/*It's the main*/
int main()
{
	/*Define Variables*/
	int Result;
	
	/*Ask the user to solve the problem*/
	printf("Enter the answer of 3 x 4 = ");
	
	/*infinite loop which asks the user to enter right value, it terminate only the user enter the right value*/
	while(1)
	{
		/*Scan the result from the user*/
		scanf("%d", &Result);
		
		/*Validate the answer*/
		if(Result == 12)
		{
			/*Thank the user then terminate*/
			printf("Thanks.");
			
			break;
		}
		else
		{
			/*Reask the user to enter the right answer*/
			printf("Not correct, Please try again: ");
		}
	}
	
	/*Return to the operating system*/
	return 0;
}