
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int table(int tab[5][5]);
int table2(int tab[5][5]);
int table3(int tab[5][5]);

int main()
{
	int tab[5][5], num1, max, j, i;//defining two dementional array
	printf("Welcome to the two dimensional array please enter a number:\n");
	for (i = 0; i < 5; i++)//inserting numbers to the array
	{
		for (j = 0; j < 5; j++)
		{
			scanf("%d", &tab[i][j]);
		}
	}
	max = table(tab);
	printf("Sum of maximums of lines is %d\n", max);
	max = table2(tab);
	printf("Sum of maximums of cols is %d\n", max);
	max = table3(tab);
	printf("Number of equal pairs of neighbors are %d\n", max);
	
} 
int table(int tab[5][5])//defining which number is the highest in the line
{
	int i, j, maxline , max2=0;
	for (i = 0; i < 5; i++)
	{
		maxline = 0;		
		for (j = 0; j < 5; j++)			
		{				
			if (tab[i][j] >= maxline)
			{				
				maxline = tab[i][j];
			}			
		}
		max2 = max2 + maxline;
	}	
	return max2;
}
int table2(int tab[5][5])//defining which number is the highest in the col
{
	int i, j, maxcol, max2 = 0;
	for (j = 0; j < 5; j++)
	{
		maxcol = 0;
		for (i = 0; i < 5; i++)
		{
			if (tab[i][j] >= maxcol)
			{
				maxcol = tab[i][j];
			}
		}
		max2 = max2 + maxcol;
	}
	return max2;
}
int table3(int tab[5][5])//checking how many pair are there in the 2 dementional array 
{
	int i, j, count=0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			while (j != 5 && i != 5)
			{
				if (tab[i][j] == tab[i][j + 1])//cheking in the line
				{
					count++;
				}
				if (tab[i][j] == tab[i + 1][j])//checking in the col
				{
					count++;
				}
				if (tab[i][j] == tab[i++][j++])//checking in the diagonal line
				{
					count++;
				}
			}
		}
	}
	return count;
}