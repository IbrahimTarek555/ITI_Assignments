/*Include needed libraries*/
#include "stdio.h"

/*It's the main*/
int main()
{
	/*Define variables*/
	int ID;
	
	/*Scan the ID from the user*/
	printf("Please, Enter your ID: ");
	scanf("%d", &ID);
	
	/*Validate the ID and print the result*/
	switch(ID)
	{
		case 1234:
			printf("Welcome Ahmed.");
			break;
		case 5678:
			printf("Welcome Yousef.");
			break;
		case 1145:
			printf("Welcome Mina.");
			break;
		default:
			printf("Wrong ID.");
			break;
	}
	
	/*Return to the operating system*/
	return 0;
}