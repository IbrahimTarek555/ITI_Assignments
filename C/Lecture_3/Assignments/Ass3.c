/*Include needed libraries*/
#include "stdio.h"

/*It's the main*/
int main(void)
{
	/*Define variables*/
	int Height;
	int i, j, k;
	
	/*Scan the hieght from the user*/
	printf("Please, Enter a height: ");
	scanf("%d", &Height);
	
	/*Print the pyramid*/
	for(i = Height; i > 0; i--)
	{
		for(j = i - 1; j > 0; j--)
		{
			printf(" ");
		}
		
		for(k = 0; k < ((Height - i + 1) * 2) - 1; k++)
		{
			printf("*");
		}
		
		if(i != 1)
		{
			printf("\n");			
		}
	}

	/*Return to the operating system*/
	return 0;
}