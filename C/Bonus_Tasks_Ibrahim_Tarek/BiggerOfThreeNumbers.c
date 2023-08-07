/*Include needed libraries*/
#include "stdio.h"

/*It's the main*/
int main()
{
	/*Define Variables*/
	int Num1;
	int Num2;
	int Num3;
	int BiggerNum;
	
	/*Scan three number from the user*/
	printf("Enter the first number: ");
	scanf("%d", &Num1);
	printf("Enter the second number: ");
	scanf("%d", &Num2);
	printf("Enter the third number: ");
	scanf("%d", &Num3);

	switch(Num1 > Num2)
	{
		case 1:
			switch(Num1 > Num3)
			{
				case 1: BiggerNum = Num1;	break;
				case 0: BiggerNum = Num3;	break;
			}
			break;
		
		case 0:
			switch(Num2 > Num3)
			{
				case 1: BiggerNum = Num2;	break;
				case 0: BiggerNum = Num3;	break;
			}
			break;
	}
	
	/*Print the bigger number*/
	printf("The bigger number is %d", BiggerNum);
	
	/*Return to the operating system*/
	return 0;
}