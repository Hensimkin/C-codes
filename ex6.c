
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int iseven(int num)
{
		if (num%2 == 0)//checking if the is even
	{
		return 1;// returning 1 if it is even
	}
	else
	{
		return 0; //returning 0 if it is odd
	}
}
int ispositive(int num)
{
	if (num > 0)//cheking if the number is positive
	{
		return 1;//if it is positive returning 1
	}
	else
	{
		return 0;//if it is positive returning 0
	}
}
int countdigits(int num)
{
	int i = 0,num1=num;
	while (num != 0)//checking if the number is not equals zero
	{
		num = num / 10;//deviding the number until we get 0
		i++;//counting the digits in the number
	}
	printf("the num %d has %d digits\n", num1, i);
	return i;
}
float printfloatmax()
{
	float num,maxnum;
	int i = 1,position =i;
	printf("please enter a float num");
	scanf("%f", &num);
	maxnum = num;
	while (num != 0)
	{
		i++;
		printf("please enter a float num");
		scanf("%f", &num);
		if(maxnum - (int)maxnum <num-(int)num)//substracting the float num with the int num to see which float number is higher
		{
			maxnum = num;//muxnum getting the highest number with the float
			position = i;//position counting which number was the highest in which position
		}

	}
	printf("the maxnum is %.4f\n", maxnum);
	printf("the position is %d\n", position);
	return main();
}
unsigned long int reversedigit(unsigned long int num)
{
	unsigned long int reverse = 0;
	while (num != 0)//checking if the number is above 0
	{
		reverse = reverse * 10;
		reverse = reverse + num % 10;
		num = num / 10;//doing actions to rotate the number/reverse
	}
		return reverse;
}
unsigned long int getlongnumber(unsigned long int num)
{
	int num1 = 0;
	num1 = reversedigit(num) + 5;//adding 5 to the reversed number
	printf("the num is %ld\n", num1);
	return main();
}
int printspecialnumbers()
{
	int num, num1, num2, num3, num4, i = 0;
	for (num = 1000; num > 999 && num < 10000; num++)//making the limits for the number
	{
		num1 = num % 10;
		num2 = (num / 10) % 10;
		num3 = (num / 100) % 10;
		num4 = num / 1000;
		if (num1 != num2 && num1 != num3 && num1 != num4)//checking if the numbers are now equel
		{
			if (num2 != num3 && num2 != num4)//checking if the numbers are now equel
			{
				if (num3 != num4)//checking if the numbers are now equel
				{
					printf("%d\n", num);
					i++;//counting the numbers thar arent equal
				}
			}
		}
	}
	printf("\n\n");
	return i;
}
int CountSpecialNumbers()
{
	printf("The number is %d\n", printspecialnumbers());// printing the total amout of numbers
	return main();
}
int printmaxcountdivisors(int low,int high)
{
int num, devider = 1, counter,maxcounter=0,maxnum;
{		
	for (num=low; num <= high; num++)
		{	
			counter = 1;// zeroing the counter for every time the system counts
			for (devider=1; devider <= high; devider++)
			{
				if (num % devider == 0)
				{
					if (counter > maxcounter)
					{
						maxcounter = counter;//entering the number of counter to the max counts of devides
						maxnum = num;// entering the maximun number with the maximum devides
					}
					counter++;					
				}
			}
		}
		
	}
    

printf("The max number is %d and it has %d of devides\n", maxnum, maxcounter);
	for (devider = 1; devider <= maxnum; devider++)
	{
		if (maxnum % devider == 0)
		{
			printf("the deviders are %d\n", devider);//printing the deviders
		}
	}
	return 0;
}
int maxcountdivisors()
{
	int high, low;
	printf("please enter 2 limits min max:\n");
	scanf("%d %d", &low, &high);
	while (low < 0 || high < 0 || high < low)//if the numbers arent correct by the terms you enter the loop and scan new numbers
	{
		printf("error\n");
		printf("please enter two positive limits min max:\n");
		scanf("%d %d", &low, &high);
	}
	printmaxcountdivisors(low,high);
	return main();
}
int triangle(int size)
{
	int i,j;
	for (i = 1; i <= size; i++)//counting the lines
	{
		for (j = 1; j <= i; j++)//counting the columns
			printf("*");
		printf("\n");
	}
	printf("\n");
	return main();
}
int square (int size)
{
	int i, j;
	for (i = 1; i <= size; i++)//counting the lines
	{
		for (j = 1; j <= size; j++)//counting the columns=lines
			printf("*");
		printf("\n");
	}
	printf("\n");
	return main();
}
int rectangle(int width, int height)
{
	int i, j;
	for (i = 1; i <= width; i++)
	{
		for (j = 1; j <= height; j++)
		{
			if (i == 1 || i == width || j == 1 || j == height)//checking the term that the system will print # for the outside of the rectangle and $ for the inside
			{
				printf("#");
			}
			else
			{
				printf("$");
			}
		}
	     printf("\n");
	}
	printf("\n");
	return main();
}
int allshapes()
{
	int num;
	printf("please slecet a shape:\n1 is triangle\n2 is square\n3 is rectangle\n4 for exit\n");
	scanf("%d", &num);
	if (num == 1)
	{
		int size;
		printf("please enter a size for triangle\n");
		scanf("%d", &size);
		triangle(size);
	}
	else if (num == 2)
	{
		int size;
		printf("please enter a size for square\n");
		scanf("%d", &size);
		square(size);
	}
	else if (num == 3)
	{
		int width, height;
		printf("please enter a width and height for rectangle\n");
		scanf("%d %d", &width,&height);
		rectangle(width,height);
	}
	else if (num == 4)
	{
		return main();
	}
}
void info()
{
	int num,i=countdigits;
	printf("please enter a number:");
	scanf("%d", &num);
	{
		if (iseven(num) == 1)
		{
			printf("the num is even\n");
		}
		else
		{
			printf("the num is odd\n");
		}
	}
	{
		if (ispositive(num) == 1)
		{
			printf("the num is positive\n");
		}
		else
		{
			printf("the num is negetive\n");
		}
	}
	{
		countdigits(num);//entering into the countdigits function
	}
	return main();
}
int main()
{
	int num;
	printf("Please choose and option:\n1-info:\n2-print a number with max float:\n3-reverse the digit and add 5:\n4-Pick the number that has the max amount of divisors:\n5-Print the special numbers:\n6-Print shapes:\n7-exit\n");
	int num2;
		scanf("%d", &num2);
	if (num2 == 1)
	{		
		info();
	}
	else if (num2 == 2)
	{
		printfloatmax();
	}
	else if(num2==3)
	{
		printf("enter a number:\n");
		scanf("%ld", &num);
		reversedigit(num);
		getlongnumber(num);
	}
	else if (num2 == 4)
	{
		maxcountdivisors();
	}
	else if (num2 == 5)
	{
		CountSpecialNumbers();
	}
	else if (num2 == 6)
	{		
		allshapes();
	}
	else if (num2 == 7)
	{
		printf("have a nice day");
	}
	return 0;
}

