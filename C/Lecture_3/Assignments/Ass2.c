/*Include needed libraries*/
#include "stdio.h"

/*It's the main*/
int main()
{
	/*Define variables*/
	char UsersNamesID[3][10] = {"Ahmed", "Amr", "Wael"};
	int UsersArr[3][2] = {{1234, 7788}, {5678, 5566}, {9870, 1122}};
	int TempID;
	int TempPassword;
	int LoginFlag = 0;
	int Attempts = 3;
	int i;
	
	/*Scan the ID from the user*/
	printf("Please, Enter your ID: ");
	scanf("%d", &TempID);
	
	/*Search for the ID*/
	for(i = 0; i < 3; i++)
	{
		if(TempID == UsersArr[i][0])
		{
			LoginFlag = 1;
			break;
		}
	}

	/*If the ID exists, ask for the password*/
	if(LoginFlag == 1)
	{
		/*Ask the user for the password*/
		printf("Please, Enter the password: ");
		
		/*Loop to handle the login with three attempts*/
		while(Attempts != 0)
		{
			/*Scan the password*/
			scanf("%d", &TempPassword);
			
			/*If password is correct, welcome the user*/
			if(TempPassword == UsersArr[i][1])
			{
				printf("Welcome, %s!", UsersNamesID[i]);
				break;
			}
			/*Else, continue scannig the password*/
			else
			{
				if(Attempts > 1)
				{
					printf("Try again: ");					
				}
				else
				{
					printf("Incorrect password for 3 times, No more tries.");
				}
			}
			
			/*Decrement the attempts*/
			Attempts--;
		}		
	}
	/*Else, terminate the program with a message*/
	else
	{
		printf("ID does not exist!");
	}
	
	/*Return to the operating system*/
	return 0;
}