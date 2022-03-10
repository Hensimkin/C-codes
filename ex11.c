
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int* divide(int arr1[], int size, int arr2[], int size2);
int main()
{
	int *arr1,size,*arr2,size2,*arr3,i,j,k;
	printf("please enter a size for the arr1:\n");
	scanf("%d", &size);
	arr1 = (int*)malloc(size * sizeof(int));//defining new array with the size
	if (arr1 == NULL)
	{
		printf("not enough memory");
		return 0;
	}
	printf("please enter numbers to the arr1:\n");
	for (j = 0; j < size; j++)
	{
		scanf("%d", &arr1[j]);//scaning numbers to the array
	}
	printf("please enter a size for the arr2:\n");
	scanf("%d", &size2);
	arr2 = (int*)malloc(size2 * sizeof(int));//defining the new returned array
	if (arr2 == NULL)
	{
		printf("not enough memory");
		return 0;
	}
	printf("please enter numbers to the arr2:\n");
	for (k = 0; k < size2; k++)
	{
		scanf("%d", &arr2[k]);//scaning the numbers to the 
	}
	arr3=divide(arr1, size, arr2, size2);
	for (i = 0; i < size2; i++)
	{
		printf("%d ", arr3[i]);
	}
	free(arr1);//free the arr1
	free(arr2);//free the arr2
	free(arr3);//free the arr3
}
int* divide(int arr1[], int size, int arr2[], int size2)
{
	int *arr3=NULL,i,j,count;
	arr3 = (int*)malloc(size2 * sizeof(int));
	if (arr3 == NULL)
	{
		printf("not enough memory");//if there are not enough memory the message will show up
		return 0;
	}
	for (i = 0; i < size2; i++)
	{
		arr3[i] = 0;
		count = 0;
		for (j = 0; j < size; j++)
		{
			if (*(arr1 + j) % *(arr2 + i) == 0)
			{
				count++;
			}
		}
		arr3[i] = count;//putting the count to the new array
	}
	return arr3;
}