/*Include needed libraries*/
#include "stdio.h"

/*It's the main*/
int main()
{
	/*Define Variables*/
	int Num;
	int i;
	
	/*Scan a number from the user*/
	printf("Enter the number to display its multiplication table: ");
	scanf("%d", &Num);
	
	/*Print the muliplication table*/
	for(i = 1; i <= Num; i++)
	{
		printf("%d x %d = %d\n", Num, i, (Num * i));
	}
	
	/*Return to the operating system*/
	return 0;
}