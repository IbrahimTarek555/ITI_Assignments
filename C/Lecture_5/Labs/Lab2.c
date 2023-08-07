/*Needed libraries*/
#include <stdio.h>

/*It is the main*/
int main()
{
	/*Define Variables*/
	int NumbersArr[10];
	int Sum = 0;
	int max = 0;
	float Avg;
	
	/*Scan Numbers from the user*/
	for(int i = 0; i < 10; i++)
	{
		printf("Please, Enter Number %d: ", (i + 1));
		scanf("%d", &NumbersArr[i]);
		
		/*Update the summation every iteration*/
		Sum = Sum + NumbersArr[i];
		
		/*Search for the maximum number*/
		if(NumbersArr[i] > max)
		{
			max = NumbersArr[i];
		}
	}
	
	/*Calculate the average of the numbers*/
	Avg = Sum / 10.0;
	
	/*Print Results to the user*/
	printf("Sum of array elements = %d\n", Sum);
	printf("Average of array elements = %f\n", Avg);
	printf("Maximum number = %d", max);
	/*Return to the operating system*/
	return 0;
}