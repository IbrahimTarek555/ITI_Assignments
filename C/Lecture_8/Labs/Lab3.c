/*Needed libraries*/
#include <stdio.h>

/*Define a sturct for employee*/
typedef struct Student
{
	int ID;
	int MathGrade;
	int LanguageGrade;
	int PhysicsGrade;
	int ChemistryGrade;
}
Student;

/*It is the main*/
int main()
{
	/*Define Variables*/
	Student StudentsArr[10];
	int SearchID;
	int i;
	
	/*Initialize students grades*/
	for(i = 0; i < 10; i++)
	{
			StudentsArr[i].ID = i;
			StudentsArr[i].MathGrade = i + 5;
			StudentsArr[i].LanguageGrade = i + 10;
			StudentsArr[i].PhysicsGrade = i + 20;
			StudentsArr[i].ChemistryGrade = i + 30;
	}

	
	/*Scan student ID from the user*/
	printf("Please, Enter student ID: ");
	scanf("%d", &SearchID);
	
	/*Search for the index inside the array*/
	for(i = 0; i < 10; i++)
	{
		if(SearchID == StudentsArr[i].ID)
		{
			break;
		}
	}
	
	/*Print grades*/
	if(i == 10)
	{
		printf("Student ID is not correct!");
	}
	else
	{
		printf("Math Grade: %d\n", StudentsArr[i].MathGrade);
		printf("Language Grade: %d\n", StudentsArr[i].LanguageGrade);
		printf("Physics Grade: %d\n", StudentsArr[i].PhysicsGrade);
		printf("Chemistry Grade: %d\n", StudentsArr[i].ChemistryGrade);
	}
	
	/*Return to the operating system*/
	return 0;
}