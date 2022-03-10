
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int num, num1, num2, num3, num4;
	printf("please enter a number between 0-9999:");
	scanf("%d", &num);
	if (num >= 0 && num <= 9999)
	{
		if (num >= 0 && num <= 9)
		{
			printf("The maximum digit is %d", num);//the system automaticly chooses the number that is selected is the highest
		}
		else if (num >= 10 && num <= 99)
		{
			num1 = num / 10;
			num2 = num % 10;
			if (num1 > num2)//The system chooses which number is the highest and which is the lowest
				printf("the maximum digit is %d and the minimum digit is %d", num1, num2);
			else if (num1 < num2)
				printf("the maximum digit is %d and the minimum digit is %d", num2, num1);
			else if (num1 == num2)
				printf("the numbers are equal");
		}
		else if (num >= 100 && num <= 999)
		{
			num1 = num / 100;
			num2 = num / 10 % 10;
			num3 = num % 10;
			if (num2 > num1 && num3 > num2)//The system chooses which number is the highest and which is the lowest
				printf("The maximum digit is %d and the minimum digit is %d", num3, num1);
			else if (num1 > num2 && num3 > num2)
				printf("The maximum digit is %d and the minimum digit is %d", num3, num2);
			else if (num2 > num1 && num1 > num3)
				printf("The maximum digit is %d and the minimum digit is %d", num2, num3);
			else if (num2 > num3 && num3 > num1)
				printf("The maximum digit is %d and the minimum digit is %d", num2, num1);
			else if (num1 > num3 && num3 > num2)
				printf("The maximum digit is %d and the minimum digit is %d", num1, num2);
			else if (num1 > num2 && num2 > num3)
				printf("The maximum digit is %d and the minimum digit is %d", num1, num3);
			else
				printf("%d=%d=%d", num1, num2, num3);
		}
		else if (num >= 1000 && num <= 9999)
		{
			num1 = num / 1000;
			num2 = num / 100 % 10;
			num3 = num / 10 % 10;
			num4 = num % 10;
			{
				if (num1 > num2 && num1 > num3 && num1 > num4)//The system chooses which number is the highest and which is the lowest
					printf("The maximum digit is %d", num1);
				else if (num2 > num1 && num2 > num3 && num2 > num4)
					printf("The maximum digit is %d", num2);
				else if (num3 > num1 && num3 > num2 && num3 > num4)
					printf("The maximum digit is %d", num3);
				else if (num4 > num1 && num4 > num2 && num4 > num1)
					printf("The maximum digit is %d", num4);
			}
			{
				if (num1 < num2 && num1 < num3 && num1 < num4)
					printf("The minimum digit is %d", num1);
				else if (num2 < num1 && num2 < num3 && num2 < num4)
					printf("The minimum digit is %d", num2);
				else if (num3 < num1 && num1 < num3 && num3 < num4)
					printf("The minimum digit is %d", num3);
				else if (num4 < num1 && num4 < num2 && num4 < num1)
					printf("The minimum digit is %d", num4);
				else
					printf("%d=%d=%d=%d",num1,num2,num3,num4);
			}
		}
	}
	else
		printf("error");//the system prints an error if the number is higher then 9999
	return 0;
}
