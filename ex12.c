
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
long long** shrink(int** arr1, int size);
int countdigits(num);
int main()
{
	long long** arr3 = NULL;
	int** arr1 = NULL;
	int i, size, j;
	printf("please enter a size to the two dementional array");
	scanf("%d", &size);
	if (size % 2 != 0)
	{
		printf("error");
		return NULL;
	}
	arr3 = (long long**)malloc((size / 2) * sizeof(long long*));//defining the returned array
	if (arr3 == NULL)
	{
		printf("error");
		return NULL;
	}
	for (j = 0; j < (size/2); j++)
	{
		*(arr3 + j) = (long long*)malloc((size / 2) * sizeof(long long));//defining the returned inside array
		if (*(arr3 + j) == NULL)
		{
			printf("error");
			return NULL;
		}
	}
	arr1 = (int**)malloc(size * sizeof(int*));//defining new array
	if (arr1 == NULL)
	{
		printf("error");
		return NULL;
	}
	for (i = 0; i < size; i++)//defining the inside new array
	{
		*(arr1+i) = (int*)malloc(size * sizeof(int));
		if (*(arr1 + i) == NULL)
		{
			return NULL;
		}
	}
	printf("please enter number to the array:\n");
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			scanf("%d", &arr1[i][j]);//scanning new numbers into the array
		}
	}
	arr3 = shrink(arr1, size);//calling shrink function
	for (i = 0; (i < size / 2); i++)
	{
		for (j = 0; (j < size / 2); j++)
		{
			printf("%lld ", arr3[i][j]);
			printf("\n");
		}
	}
	for (i = 0; i < size; i++)//freeing the arrays
	{
		free(arr1[i]);
	}
	free(arr1);
	for (i = 0; i < (size/2); i++)
	{
		free(arr3[i]);
	}
	free(arr3);
}
long long** shrink(int** arr1, int size)
{
	
	int i, j,num;
	long long** arr2 = NULL;
	arr2 = (long long**)malloc((size/2) * sizeof(long long*));//defining new half array
	if (arr2 == NULL)
	{
		printf("error");
		return NULL;
	}
	for (j = 0; j < size/2; j++)
	{
		*(arr2 + j) = (long long*)malloc((size / 2) * sizeof(long long));
		if (*(arr2 + j) == NULL)
		{
			printf("error");
			return NULL;
		}
	}
	for (i = 0; i < (size/2); i++)
	{
		for (j = 0; j < (size/2); j++)
		{			
			arr2[i][j] = arr1[2 * i][2 * j];//
			num = countdigits(arr1[2 * i][2 * j + 1]);
			arr2[i][j] = (arr2[i][j]) * num + arr1[2 * i][2 * j + 1];//multiplaying the second number with the return count
			num = countdigits(arr1[2 * i + 1][2 * j]);
			arr2[i][j] = (arr2[i][j]) * num + arr1[2 * i + 1][2 * j];//multiplaying the third number with the return count
			num = countdigits(arr1[2 * i + 1][2 * j + 1]);
			arr2[i][j] = (arr2[i][j]) * num + arr1[2 * i + 1][2 * j + 1];//multiplaying the fourth number with the return count
			num = 0;
		}
	}
	return arr2;
}
int countdigits(num)//counting the numbers that need to be multiplaied
{
	int count = 1;
	while (num !=0)
	{
		count = count * 10;
		num = num / 10;		
	}
	return count;
}
