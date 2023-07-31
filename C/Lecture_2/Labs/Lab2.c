/*Include needed libraries*/
#include "stdio.h"

/*It's the main*/
int main()
{
	/*Define variables*/
	int WorkHours;
	int Salary;
	
	/*Scan work hours from the user*/
	printf("Please, Enter your work hours: ");
	scanf("%d", &WorkHours);
	
	/*Calculate the salary*/
	Salary = WorkHours * 50;
	
	/*Apply the deduction*/
	if(WorkHours < 40)
	{
		Salary = Salary - (Salary / 10);
	}
	
	/*Print the salary*/
	printf("Your salary is %d", Salary);
	
	/*Return to the operating system*/
	return 0;
}