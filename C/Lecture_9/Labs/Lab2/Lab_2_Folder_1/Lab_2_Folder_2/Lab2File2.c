/*Needed libraries*/
#include <stdio.h>
#include "../Lab2File1.h"
#include "./Lab_2_Folder_3/Lab2File3.h"

/*It is the main*/
int main()
{
	/*Print variabels which exist inside the header files*/
	printf("Variable inside the first header file is: %d.\n", File1_Var);
	printf("Variable inside the second header file is: %d.\n", File3_Var);
		
	/*Return to the operating system*/
	return 0;
}