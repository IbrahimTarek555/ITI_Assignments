/*Needed libraries*/
#include <stdio.h>

/*Define two struct types*/
typedef struct
{
	unsigned short int x;
	unsigned long  int y;
	unsigned short int z;
	unsigned long  int k;
}
Struct1;

typedef struct
{
	unsigned long  int y;
	unsigned long  int k;
	unsigned short int x;
	unsigned short int z;
}
Struct2;

/*It is the main*/
int main()
{
	/*Print size of struct before ordering*/
	printf("Size of struct before ordering is: %d\n", sizeof(Struct1));
	
	/*Print size of struct after ordering*/
	printf("Size of struct after ordering is: %d", sizeof(Struct2));
		
	/*Return to the operating system*/
	return 0;
}