/*Needed libraries*/
#include <stdio.h>

/*Define a sturct for employee*/
struct Employee
{
	float Salary;
	float Bonus;
	float Deduction;
};

/*It is the main*/
int main()
{
	/*Define Variables*/
	struct Employee Ahmed, Waleed, Amr;
	int Result;
	
	/*Scan inputs from the user*/
	printf("Please, Enter Ahmed Salary: ");
	scanf("%f", &Ahmed.Salary);
	printf("Please, Enter Ahmed Bonus: ");
	scanf("%f", &Ahmed.Bonus);
	printf("Please, Enter Ahmed Deduction: ");
	scanf("%f", &Ahmed.Deduction);

	printf("Please, Enter Waleed Salary: ");
	scanf("%f", &Waleed.Salary);
	printf("Please, Enter Waleed Bonus: ");
	scanf("%f", &Waleed.Bonus);
	printf("Please, Enter Waleed Deduction: ");
	scanf("%f", &Waleed.Deduction);

	printf("Please, Enter Amr Salary: ");
	scanf("%f", &Amr.Salary);
	printf("Please, Enter Amr Bonus: ");
	scanf("%f", &Amr.Bonus);
	printf("Please, Enter Amr Deduction: ");
	scanf("%f", &Amr.Deduction);

	/*Calculate total vlue needed from finance team*/
	Result = Ahmed.Salary + Waleed.Salary + Amr.Salary + Ahmed.Bonus + Waleed.Bonus + Amr.Bonus - Ahmed.Deduction - Waleed.Deduction - Amr.Deduction;
	
	/*Print needed money to the user*/
	printf("Total value needed is %d", Result);
	
	/*Return to the operating system*/
	return 0;
}