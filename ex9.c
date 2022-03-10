
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
void rotateleft(char str[80]);
void rotateright(char str2[80]);
int intersection(char str[80], char str2[80]);
int main()
{
	int len, len2;
	char str[80], str2[80], temp4[80];//defining strings
	puts("please enter two strings:\n");
	gets(str);//scaning the string
	gets(str2);
	printf("\n");
	rotateright(str);//rotating the string right
	rotateright(str);
	printf("The string after 2 rotations right : %s", str);
	printf("\n");
	rotateleft(str2);//rotating the string left
	rotateleft(str2);
	rotateleft(str2);
	printf("The string after 3 rotations left : %s", str2);
	printf("\n");
	intersection(str, str2);//sending the strings to comapre

}
void rotateleft(char str[80])
{
	char temp[80], temp2[80], temp4[80];
	int i, j;
	for (i = 0; str[i] != ' '; i++)//i-1 on
	{
		temp[i] = str[i];//entering the the temp string charecters
	}
	temp[i] = '\0';
	for (i = i + 1, j = 0; str[i] != '\0'; i++, j++)
	{
		temp2[j] = str[i];//two three four five six\0
	}
	temp2[j] = '\0';
	strcpy(temp4, temp2);
	strcat(temp4, " ");
	strcat(temp4, temp);
	strcpy(str, temp4);//copying the temp string to the str string

}
void rotateright(char str2[80])
{
	char temp2[80], temp3[80], temp4[80];
	int i = strlen(str2);//defining the lenth of the string
	int j = 0, k = 0, x = 0;

	for (i; str2[i] != ' '; i--)
	{
		k = i;
	}
	for (k; str2[k] != '\0'; k++, j++)
	{
		temp2[j] = str2[k];
	}
	temp2[j] = '\0';
	for (x = 0; str2[x] != '\0', x < i; x++)
	{
		temp3[x] = str2[x];
	}
	temp3[x] = '\0';
	strcpy(temp4, temp2);
	strcat(temp4, " ");
	strcat(temp4, temp3);
	strcpy(str2, temp4);//copying the temp string to the str string
}
int intersection(char str[80], char str2[80])
{
	int i = 0, j = 0, count = 0, temp[80], temp2[80];
	for (i = 0, j = 0; str[i] != '\0' && str2[j] != '\0'; i++, j++)
	{
		if (str[i] == str2[j])
		{
			count++;
		}
		if (str[i] - str2[j] == 32 || str[i] - str2[j] == -32)//to say that the the chars like letters are even you need to decrease between capital and small letter and to get 32 in ascii code or -32 
		{
			count++;
		}
	}

	printf("the intersection of the 2 strings is %d", count-1);
}






	






	