/*Needed libraries*/
#include <stdio.h>

/*It is the main*/
int main()
{
	/*Define Variables*/
	int Num = 10;
	int *NumPtr = &Num;
	
	/*Print the number before changing*/
	printf("X before change is: %d\n", Num);
	
	/*Change Num with dereferencing it*/
	*NumPtr = 20;
	
	/*Print the number after changing*/
	printf("X after change is: %d", Num);

	/*Return to the operating system*/
	return 0;
}