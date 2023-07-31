/*Needed libraries*/
#include <stdio.h>

/*Functions' prototype*/
void BubbleSort(int NumbersArr[], int ArrSize);

/*It is the main*/
int main()
{
	/*Define Variables*/
	int NumbersArr[10];
	int SearchNumber;
	int SearchNumberIndex;
	
	/*Scan Numbers from the user*/
	printf("Before Sorting:\n");
	for(int i = 0; i < 10; i++)
	{
		printf("Please, Enter Number %d: ", (i + 1));
		scanf("%d", &NumbersArr[i]);
	}
		
	/*Sort the array*/
	BubbleSort(NumbersArr, 10);
	
	printf("\nAfter Sorting: \n");
	/*Print the array elements after sorting*/
	for(int i = 0; i < 10; i++)
	{
		printf("Element %d is: %d\n", (i + 1), NumbersArr[i]);
	}

	/*Return to the operating system*/
	return 0;
}

/*Functions' Implementation*/
void BubbleSort(int NumbersArr[], int ArrSize)
{
	/*Define Variables*/
	int i, j;
	int Swaps;
	
	/*
	9
	9 8 7 6 5 4 3 2 1 

	8
	9 8 7 6 5 4 3 2 

	7
	9 8 7 6 5 4 3 

	6
	9 8 7 6 5 4 

	5
	9 8 7 6 5 

	4
	9 8 7 6 

	3
	9 8 7 
	
	2
	9 8 
	
	1
	9 
	
	0*/
	
	/*Traverse over the array elements*/
	for(i = (ArrSize - 1); i >= 0; i--)
	{
		Swaps  = 0;
		
		/*Traverse from the last element to the element which already sorted*/
		for(j = (ArrSize - 1); j > (ArrSize - 1 - i); j--)
		{
			/*Swap the elements which need to be swapped*/
			if(NumbersArr[j] < NumbersArr[j - 1])
			{
				Swaps++;
				NumbersArr[j] = NumbersArr[j] + NumbersArr[j - 1];
				NumbersArr[j - 1] = NumbersArr[j] - NumbersArr[j - 1];
				NumbersArr[j] = NumbersArr[j] - NumbersArr[j - 1];
			}
		}
		
		/*If a loop has no swaps, that means that the array is ordered*/
		if(Swaps == 0)
		{
			break;
		}
	}
}