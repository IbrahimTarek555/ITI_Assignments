/*Needed libraries*/
#include <stdio.h>
#include <stdlib.h>

/*Functions' prototype*/
void BubbleSort(int *NumbersArr, int ArrSize);

/*It is the main*/
int main()
{
	/*Define Variables*/
	int Size;
	int *ArrPtr;
	
	/*Scan number of numbers from the user*/
	printf("Please, Enter the number of numbers: ");
	scanf("%d", &Size);
	
	/*Reserve memory for the size of numbers*/
	ArrPtr = (int *) calloc(Size, sizeof(int));
	
	/*Scan Numbers from the user*/
	printf("Before Sorting:\n");
	for(int i = 0; i < Size; i++)
	{
		printf("Please, Enter Number %d: ", (i + 1));
		scanf("%d", (ArrPtr + i));
	}
		
	/*Sort the array*/
	BubbleSort(ArrPtr, Size);
	
	/*Print the array elements after sorting*/
	printf("\nAfter Sorting: \n");
	for(int i = 0; i < Size; i++)
	{
		printf("Element %d is: %d\n", (i + 1), ArrPtr[i]);
	}
	
	/*Free the memory we reserved*/
	for(int i = 0; i < Size; i++)
	{
		free(ArrPtr + i);		
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