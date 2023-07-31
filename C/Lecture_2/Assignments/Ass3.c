/*Include needed libraries*/
#include "stdio.h"

/*It's the main*/
int main()
{
	/*Define variables*/
	int Num1;
	int Num2;
	int Num3;
	int BiggerNum;
	
	/*Scan three numbers from the user*/
	printf("Please, Enter the first number: ");
	scanf("%d", &Num1);
	printf("Please, Enter the second number: ");
	scanf("%d", &Num2);
	printf("Please, Enter the third number: ");
	scanf("%d", &Num3);
	
	/*Search for the bigger with ternary operator*/
	BiggerNum = (Num1 > Num2)? ((Num1 > Num3)? Num1 : Num3) : ((Num2 > Num3)? Num2 : Num3);
	
	/*print the bigger number*/
	printf("Bigger number is: %d", BiggerNum);
	
	/*Return to the operating system*/
	return 0;
}