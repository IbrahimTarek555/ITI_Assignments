#include <stdio.h>

int main()
{
	int x = 5;
	
	printf("%d", factorial(7));
}

int factorial(int x)
{
	if(x >= 0)
	{			
		if(x == 0)
		{
			return 1;
		}
		else
		{
			return factorial(x - 1) * x;
		}
	}
	else 
	{
		/*Do nothing*/
	}
}