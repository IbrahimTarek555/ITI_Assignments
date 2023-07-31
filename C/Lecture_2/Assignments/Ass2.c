/*Include needed libraries*/
#include "stdio.h"

/*It's the main*/
int main()
{
	/*Define variable*/
	int ID = 1234;
	int Password = 5678;
	int IDCheck;
	int PasswordCheck;
	
	/*Scan ID and password from the user*/
	printf("Please, Enter ID: ");
	scanf("%d", &IDCheck);
	printf("Please, Enter Password: ");
	scanf("%d", &PasswordCheck);
	
	/*Vaidate ID and password*/
	if(IDCheck != ID)
	{
		printf("Incorrect ID!");
	}
	else if(PasswordCheck != Password)
	{
		printf("Incorrect Password!");
	}
	else
	{
		printf("Welcome!");
	}
	
	/*Return to the operating system*/
	return 0;
}