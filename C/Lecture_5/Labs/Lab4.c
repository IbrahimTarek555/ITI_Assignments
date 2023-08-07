/*Needed libraries*/
#include <stdio.h>

/*Functions' prototype*/
int LinearSearch(int NumbersArr[], int ArrSize, int SearchNumber);

/*It is the main*/
int main()
{
	/*Define Variables*/
	int NumbersArr[10];
	int SearchNumber;
	int ExistenceNumber;
	
	/*Scan Numbers from the user*/
	for(int i = 0; i < 10; i++)
	{
		printf("Please, Enter Number %d: ", (i + 1));
		scanf("%d", &NumbersArr[i]);
	}
	
	/*Ask the user to enter a number to search*/
	printf("Enter a number to search: ");
	scanf("%d", &SearchNumber);
	
	/*Search for the number*/
	ExistenceNumber = LinearSearch(NumbersArr, 10, SearchNumber);
	
	/*Print the how much times the search number exists*/
	if(ExistenceNumber > 0)
	{		
		printf("Value exists %d times.", ExistenceNumber);
	}
	else
	{
		/*Number does not exist*/
		printf("Value does not exist!");
	}
	
	/*Return to the operating system*/
	return 0;
}

int LinearSearch(int NumbersArr[], int ArrSize, int SearchNumber)
{
	/*Define Variables*/
	int ExistenceNumber = 0;

	for(int i = 0; i < ArrSize; i++)
	{
		if(NumbersArr[i] == SearchNumber)
		{
			ExistenceNumber++;
		}
	}
	
	/*Return number of existence*/
	return ExistenceNumber;
}