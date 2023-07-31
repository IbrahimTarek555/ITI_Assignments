/*Needed libraries*/
#include <stdio.h>

/*It is the main*/
int main()
{
	/*Define variables*/
	int i, j;
	int MaxNum;
	int MaxFreq = 0;
	
	/*Define a variable to track the searched values, if you find a new value that exists for the first time inside the array, increment this counter by 1*/
	int Temp = 0;

	/*Define array to carry the numbers that we will search through*/
	int Arr[10] = {1, 2, 3, 5, 4, 2, 2, 4, 2, 2};
	
	/*
	 * Define two dimension array: 1- One dimension to carry the unique number.
	 *							   2- and another one dimension to carry its repeatation inside the array we search.
	 */
	int FindMaxArr[10][2] = {{0}, {0}};
	
	/*Traverse over all elements*/
	for(i = 0; i < 10; i++)
	{
		/*Search for the current element inside the FindMaxArr*/
		for(j = 0; j < Temp; j++)
		{
			/*If you find that the number finded before, increment its existance counter*/
			if(Arr[i] == FindMaxArr[j][0])
			{
				FindMaxArr[j][1]++;
				
				/*Block that return the maximum frequented number and its existance counter*/
				if(FindMaxArr[j][1] > MaxFreq)
				{
					MaxNum = FindMaxArr[j][0];
					MaxFreq = FindMaxArr[j][1];
				}
			}
		}
		
		/*If the previous loop terminated without finding the current element insided FindMaxArr, add this element into FindMaxArr and increment its counter to be 1*/
		/*That means that it is the first existance of the current element*/
		if(j == Temp)
		{
			FindMaxArr[Temp][0] = Arr[i];
			FindMaxArr[Temp][1]++;
			
			/*Increment The finded numbers to search for in the next loop*/
			Temp++;
		}
	}
	
	printf("Maximum frequented number is %d with repeat of %d times.", MaxNum, MaxFreq);
		
	/*Return to the operating system*/
	return 0;
}