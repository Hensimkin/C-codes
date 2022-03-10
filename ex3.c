
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	float num;
	int num1, num2;
	char num3;
	printf("Please enter a number:");
	scanf("%f", &num);
	num1 = num; //making your float number into int number
	num2 = num1; //making the int number into hexadecimal number
	num3 = num1; // showing the the number as a character
	printf("The number you chose is %f\nThe integer is %d\nThe hexadecimal is 0x%x\nThe string is %c ", num, num1, num2, num3);
	return 0;
}

