/*Needed libraries*/
#include <stdio.h>

/*Functions' Prototypes*/
int ScalarMulti(int Vector1Arr[],int Vector2Arr[], int VectorSize);

/*It is the main*/
int main()
{
	/*Define Variables*/
	int Vector1Arr[10];
	int Vector2Arr[10];
	int Result;
	
	/*Fill the first array values*/
	printf("Vector 1: \n");
	for(int i = 0; i < 10; i++)
	{
		printf("Enter Number %d: ", (i + 1));
		scanf("%d", &Vector1Arr[i]);
	}
	
	/*Fill the second array values*/
	printf("\nVector 2: \n");
	for(int i = 0; i < 10; i++)
	{
		printf("Enter Number %d: ", (i + 1));
		scanf("%d", &Vector2Arr[i]);
	}
	
	/*Call a function to calculate the scalar multiplication of two vectors*/
	Result = ScalarMulti(Vector1Arr, Vector2Arr, 10);
	
	/*Print the result to the user*/
	printf("\nScalar multiplication result is: %d.", Result);

	/*Return to the operating system*/
	return 0;
}

/*Functions' Implementation*/
int ScalarMulti(int Vector1Arr[],int Vector2Arr[], int VectorSize)
{
	/*Define variables*/
	int Result = 0;
	
	/*Calculate summation of the array*/
	for(int i = 0; i < VectorSize; i++)
	{
		Result = Result + (Vector1Arr[i] * Vector2Arr[i]);
	}
	
	/*Return the summation*/
	return Result;
}