
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int SumEvenDigits(long num);
long CreateNumber(long number);
int CheckArithmeticSeries(long Number, int Diff);
int checkarray(int arr[], int size, int* negative);
int growingarray(int arr[], int size);
int Symmetric(char* begin, char* end);
void Reducing(char* str, int size);
int main()
{
	long num,sum,number,num1, returnvalue;
	int newnum,diff;
	printf("function1\n");
	printf("please enter a long number:\n");
	scanf("%ld", &num);
	sum = SumEvenDigits(num);
	printf("The sum is %ld\n", sum);
	printf("function2\n");
	printf("please enter a long number:\n");
	scanf("%ld", &number);
	newnum = CreateNumber(number);
	printf("the num is %d\n", newnum);
	printf("function3\n");
	printf("please enter long num:\n");
	scanf("%ld", &num1);
	printf("please enter a diff:\n");
	scanf("%d",&diff);
	returnvalue = CheckArithmeticSeries(num1, diff);
	if (returnvalue == 1)
	{
		printf("The number is aretmetic\n");
	}
	else
	{
		printf("the number is not aretmetic\n");
	}
	printf("function4\n");
	int* arr = NULL;
	int size, i, *negative = 0,odd,oddnumbers;
	printf("please enter a size for the array:\n");
	scanf("%d",&size);
	arr = (int*)malloc(size * sizeof(int));
	if (arr == NULL)
	{
		printf("error");
		return NULL;
	}
	printf("please enter numbers to the array");
	for (i = 0; i < size; i++)
	{
		scanf("%d",&arr[i]);
	}
	oddnumbers = checkarray(arr, size, &negative);
	printf("%d odd numbers\n",oddnumbers);
	printf("there are %d negetive numbers\n",negative);
	printf("function5\n");
	int size1;
	int* arr1 = NULL;
	printf("please enter a size for the array:\n");
	scanf("%d", &size1);
	arr1 = (int*)malloc(size1 * sizeof(int));
	if (arr1 == NULL)
	{
		printf("error");
		return NULL;
	}
	printf("please enter numbers to the array:\n");
	for (i = 0; i < size1; i++)
	{
		scanf("%d", &arr1[i]);
	}
	if (growingarray(arr, size) == 1)
	{
		printf("the array is growing\n");
	}
	else
	{
		printf("the array is not growing\n");
	}
	printf("function6\n");
	char str[80];
	printf("please enter a string\n");
	scanf("%s", &str);
	char begin, end;
	begin = str[0];
	end = str[strlen(str) - 1];
	if (Symmetric(&begin, &end))
	{
		printf("the string is symetric\n");
	}
	else
	{
		printf("the string is not symteric\n");
	}
	printf("function7\n");
	char str2[80];
	int size2;
	printf("please enter characters to the string:\n");
	scanf("%s", &str2);
	size2 = strlen(str2);
	Reducing(&str2, size2);
	free(arr);
	free(arr1);
}
int SumEvenDigits(long num)//checking the sum of the even numbers
{
	int num2=0,num3=0;//
	if (num == 0)
	{
		return 0;
	}
	num2 = num % 10;//9
	if (num2 % 2 == 0)
	{
		return(num2 + SumEvenDigits(num / 10));//calling again to the function with the half number
	}
	SumEvenDigits(num / 10);//calling to the function with the half number
}
long CreateNumber(long number)//creating a number with the odd numbers
{
	int num2;
	int num;
	if (number == 0)
	{
		return number;
	}
	num = number%10;
	if (num % 2 != 0)
	{
		return num + CreateNumber(number/10)*10;//calling to the function with the number/10 and the sum is multiplayied
	}
	else
	{
		num = 0;
		return CreateNumber(number / 10);
	}
}
int CheckArithmeticSeries(long Number, int Diff)//checking if the number is arthemetic
{
	if (Number == 0)
	{
		return 1;//returning 1 if the number is artechmetic
	}
	int num2,num = Number % 10;
	num2 = (Number/10) % 10;
	if (num - num2 == Diff)
	{
		CheckArithmeticSeries(Number / 10, Diff);//returning the number with num/10
	}
	else
	{
		return 0;
	}
}
int checkarray(int arr[] , int size,int *negative)//checking if the array has negetive and odd numbers
{ 
	int num=0;
	if (size <= 0)
	{
		return 0;
	}
	int odd = 0;
	num = arr[size - 1];
	if (num % 2 == 1||num%2==-1)
	{
		odd++;
	}
	if (num < 0)
	{
		(*negative)++;
	}
	return odd + checkarray(arr, size - 1, negative);
}
int growingarray(int arr[], int size)
{
	if (size == 0||size==1)
	{
		return 1;
	}
	if (arr[size - 1] > arr[size - 2])//chechinkg if the the array is growing 
	{
		return growingarray(arr, size - 1);
	}
	else if (arr[size - 1] < arr[size - 2])
	{
		return 0;//if the array is not growing returning 0;
	}
}
int Symmetric(char* begin, char* end)
{
	if (*begin == '\0')
	{
		return 1;
	}
	if (*begin != *end)
	{
		return 0;
	}
	if (*begin == *end)
	{
		*begin++;//making the first index in the string to go till the end
		*end--;
		return(*begin, *end);//returnning the the first and the last index of the string
	}
}
void Reducing(char* str,int size)
{
	if (size <0)
	{
		return 0;
	}
	if (str[size] >= '0' && str[size] <= '9')
	{
		printf("%c", str[size]);//printing the string numbers
		return  Reducing(str, size - 1);
	}
	else
	{
		return  Reducing(str, size - 1);
	}
}
