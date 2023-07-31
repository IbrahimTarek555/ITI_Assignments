/*Include needed libraries*/
#include "stdio.h"

/*It's the main*/
int main()
{
	/*Define variables*/
	int OperationID;
	int Result;
	int Num1;
	int Num2;
	int Flag = 1;
	
	/*Scan the operation from the user*/
	printf("1 -> Add.\n");
	printf("2 -> Subtract.\n");
	printf("3 -> Multiply.\n");
	printf("4 -> Divide.\n");
	printf("5 -> And.\n");
	printf("6 -> Or.\n");
	printf("7 -> Not.\n");
	printf("8 -> Xor.\n");
	printf("9 -> Reminder.\n");
	printf("10 -> Increment.\n");
	printf("11 -> Decrement.\n");
	
	printf("\nYour Choice: ");
	scanf("%d", &OperationID);

	/*Scan the operation ID*/
	switch(OperationID)
	{
	case 7:
	case 10:
	case 11:
		printf("\nEnter the number: ");
		scanf("%d", &Num1);
		break;
	case 1 ... 6: 
	case 8 ... 9: 
		printf("\nEnter the first number: ");
		scanf("%d", &Num1);
		printf("Enter the second number: ");
		scanf("%d", &Num2);	
		break;
	default:
		printf("\nEnter valid operation ID!\n");
		Flag = 0;
		break;
	}
	
	/*Validate operation ID*/
	if(Flag != 0)
	{
		/*Execute the operation*/
		switch(OperationID)
		{
		case 1: Result = Num1 + Num2;	break;
		case 2: Result = Num1 - Num2;	break;
		case 3: Result = Num1 * Num2;	break;
		case 4: Result = Num1 / Num2;	break;
		case 5: Result = Num1 & Num2;	break;
		case 6: Result = Num1 | Num2;	break;
		case 7: Result = ~Num1;			break;
		case 8: Result = Num1 ^ Num2;	break;
		case 9: Result = Num1 % Num2;	break;
		case 10: Result = ++Num1;		break;
		case 11: Result = --Num1;		break;
		}
		
		/*Print the result*/
		printf("\nResult is: %d\n", Result);		
	}
	
	/*Return to the operating system*/
	return 0;
}