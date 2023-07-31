/*Needed libraries*/
#include <stdio.h>

/*It is the main*/
int main()
{
	/*Define Variables*/
	int NumbersArr[10];
	
	/*Scan Numbers from the user*/
	for(int i = 0; i < 10; i++)
	{
		printf("Please, Enter Number %d: ", (i + 1));
		scanf("%d", &NumbersArr[i]);
	}
		
	/*Print the array elements in reversed order*/
	for(int i = 9; i >= 0; i--)
	{
		printf("Element %d is: %d\n", (i + 1), NumbersArr[i]);
	}

	/*Return to the operating system*/
	return 0;
}