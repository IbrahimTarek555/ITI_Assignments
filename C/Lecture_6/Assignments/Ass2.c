/*Needed libraries*/
#include <stdio.h>

/*It is the main*/
int main()
{
	/*Define Variables*/
	int x, y, z;
	int *p, *q, *r;
	
	/*Initialize variables*/
	x = 10, y = 20, z = 30;
	p = &x, q = &y, r = &z;
	
	/*Print the needed values with req (a)*/
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("z = %d\n", z);
	printf("p = %d\n", p);
	printf("q = %d\n", q);
	printf("r = %d\n", r);
	printf("*p = %d\n", *p);
	printf("*q = %d\n", *q);
	printf("*r = %d\n", *r);
	
	/*Print the message required in req (b)*/
	printf("\nSwapping pointers:\n");
	
	/*Swap code in req (c)*/
	r = p;
	p = q;
	q = r;
	
	
	/*Print the needed values with req (a)*/
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("z = %d\n", z);
	printf("p = %d\n", p);
	printf("q = %d\n", q);
	printf("r = %d\n", r);
	printf("*p = %d\n", *p);
	printf("*q = %d\n", *q);
	printf("*r = %d\n", *r);

	/*Return to the operating system*/
	return 0;
}