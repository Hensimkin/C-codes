
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define const 50;
void str_statistics(char str[], int* small, int* capital, int* digits, int size);
void main()
{
	int small , capital, digits,size;
	char str[50];
	puts("please enter to the strings");
	gets(str);//scaning the array
	size = strlen(str);
	str_statistics(str, &small, &capital, &digits,size);//calling the str statics to count how many letters and digits there are
	printf("there are %d small letters",small);//printing small letters
	printf("\n");
	printf("there are %d capital letters", capital);//printing capital letters
	printf("\n");
	printf("there are %d digits", digits);//printing digits
}
void str_statistics(char str[],int *small,int *capital, int *digits, int size)
{
	int i;
	* small = 0, * capital = 0, * digits = 0;//defining that the pointers are equal to zero;
	for (i = 0; i < size; i++)
	{
		if (*(str+i) >= 'a' && *(str+i) <= 'z')
		{
			(*small)++;//counting the small letters
		}
		if (*(str + i) >= 'A' && *(str + i) <= 'Z')
		{
			(*capital)++;//counting the capital letters
		}
		if (*(str + i) >= '0' && *(str + i) <= '9')
		{
			(*digits)++;//counting the digits
		}
	}
}

