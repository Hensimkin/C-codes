
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int contain(int big[], int size_b, int small[], int size_s);
void digits(int arr[10], int size, int statistics[10]);
int main()
{
	int statistics[10];//defining emptey array
	int size = 10;
	int arr[10];//defining a array of 10
	int big[10];//defining a array of 10
	int small[5];//defining a array of 5
	int size_b, size_s, num3;
	int i, j;

	for (i = 0; i < 10; i++)
	{
		printf("please enter numbers to the big array:\n");
		scanf("%d", &big[i]);//inserting numbers to the array
	}
	for (j = 0; j < 5; j++)
	{
		printf("please enter numbers to the small array:\n");
		scanf("%d", &small[j]);//inserting numbers to the array
	}
	contain(big, 10, small, 5);
	printf("%d\n", contain(big, 10, small, 5));
	digits(big, 10, statistics);
	{
		for (i = 0; i <= size - 1; i++)
		{
			printf("%d ", statistics[i]);			
		}
	}
	digits(small, 5, statistics);
	{
		printf("\n");
		for (i = 0; i <= size - 1; i++)
		{
			printf("%d ", statistics[i]);//438 439 440 441 442
		}
	}		
}
int contain(int big[], int size_b, int small[], int size_s)
{
	int i, j, count_i, count_j,indexofstart=0;
	for (i = 0, j = 0; i < size_b && j < size_s;)
	{
		while (i < size_b && j < size_s)
		{			
			if (big[i] == small[j])//checking if the small array is in the big array in raw
			{
				i++;
				j++;
				indexofstart++;
			}
			else
			{
				i++;
				j = 0;
			}
		}
	}
	if (j == 5)
	{
		return i=j;//returing the index of the array starts
	}
	else
	{
		return -1;
	}
}
void digits(int arr[10], int size, int statistics[10])
{
	int i, j, count = 0, num, num2;
	for (i = 0; i <= size-1; i++)//[2]=0
	{
		count = 0;//
		for (j = 0; j <=size-1 ; j++)//438 439 440 441 442 443 444 445 446 447//
		{
			num = arr[j];//440
			while (num > 0)
			{
				num2=num % 10;//438 num=0
				if (num2 == i)
				{
					count++;//1
				}
				num = num / 10;
			}

		}//
		statistics[i] = count;//inserting the amount of numbers to the index that he belongs
	}
	
}

