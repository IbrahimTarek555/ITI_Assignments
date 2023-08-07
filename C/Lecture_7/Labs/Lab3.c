/*Needed libraries*/
#include <stdio.h>

/*Declare new data types*/
typedef unsigned char u8;
typedef signed	 char s8;
typedef unsigned short int u16;
typedef signed	 short int s16;
typedef unsigned long  int u32;
typedef signed	 long  int s32;
typedef unsigned long long int u64;
typedef signed	 long long int s64;
typedef float f32;
typedef double f64;
typedef long double f96;

/*It is the main*/
int main()
{
	/*Print sizes of defined data types*/
	printf("The size of u8 is: %d bytes.\n", sizeof(u8));
	printf("The size of s8 is: %d bytes.\n", sizeof(s8));
	printf("The size of u16 is: %d bytes.\n", sizeof(u16));
	printf("The size of s16 is: %d bytes.\n", sizeof(s16));
	printf("The size of u32 is: %d bytes.\n", sizeof(u32));
	printf("The size of s32 is: %d bytes.\n", sizeof(s32));
	printf("The size of u64 is: %d bytes.\n", sizeof(u64));
	printf("The size of s64 is: %d bytes.\n", sizeof(s64));
	printf("The size of f32 is: %d bytes.\n", sizeof(f32));
	printf("The size of f64 is: %d bytes.\n", sizeof(f64));
	printf("The size of f96 is: %d bytes.\n", sizeof(f96));

	/*Return to the operating system*/
	return 0;
}