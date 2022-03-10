
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define kashlah 50
int menu();
char** init_arr(int* psize);
char** add(char** arr, int* psize, char* str);
void twice(char** arr, int psize, int index);
int find(char** arr, int size, char* str);
void print(char** arr, int size);
int main()
{
	int i, j, k, size, index,option;
	char** arr1;
	printf("please enter number of words:\n");
	scanf("%d", &size);
	int* psize = &size;
	arr1 = init_arr(&psize);                        
	printf("please enter string:");
	printf("\n");
	for (i = 0; i < *psize; i++)
	{
		scanf("%s",arr1[i]);//scanning the strings into the 2d array
	}
	menu(arr1,size);// calling to the menu
	for (i = 0; i < *psize; i++);//freeing the array
	{
		free(arr1[i]);
	}
	free(arr1);
	return 0;
	
}
int menu(char **arr1,int size)
{
	int option,index,i,last;
	char str[50],str2[50];
	int* psize = &size;
	printf("please choose an opions:\n1.add\n2.twice\n3.find\n4.print\n5.end\n");
	scanf("%d",&option);
	if (option == 1)
	{
		printf("please enter addtional string:\n");
		scanf("%s",str);
		add(arr1, &size, str);
		menu(arr1,size);
	}
	if (option == 2)
	{
		printf("please enter an index: ");
		scanf("%d",&index);
		twice(arr1, size,index);
		menu(arr1, size);
	}
	if (option == 3)
	{
		printf("please enter a string you want to find:\n");
		scanf("%s", str2);
		printf("the index is %d",find(arr1, size, str2));
		menu(arr1, size);

	}
	if (option == 4)
	{
		print(arr1,size);
		menu(arr1, size);
	}
	if (option == 5)
	{		
		printf("have a nice day");
		exit(1);
	}
	else
	{
		printf("the number is incorrect try again");
		menu(arr1, size);
	}
	return 0;
}
char** init_arr(int *psize)
{
	int i;
	char **arr=NULL;
	arr = (char**)malloc(*psize * sizeof(char*));//defining an array 
	if (arr == NULL)
	{
		printf("error");
		return NULL;
	}
	for (i = 0; i < 50; i++)
	{
		*(arr + i) = (char*)malloc(50 * sizeof(char));//defining the inside array with for loop
		if (arr == NULL)
		{
			printf("error");
			return NULL;
		}
	}
	return arr;
}
char** add(char** arr1, int* psize, char* str)
{
	int i, j,count;
	for (i = 0; i < *psize; i++)
	{
		count = 0;
		for (j = 0; j < 50; j++)
		{
			if (arr1[i][j] == str[j])
			{
				count++;
			}
		}
		if (count == strlen(str))//checking if the count equals the string
		{
			menu(arr1, psize);
		}
	}
	(*psize)++;
	arr1 = (char**)realloc(arr1,(*psize)*sizeof(char*));// doing a realloc to the arr to give it a new size
	if (arr1 == NULL)
	{
		return NULL;
	}
	arr1[*psize-1] = str; //entering the the new string to the array
	printf("allocation made\n");
	return arr1;
}
void twice(char** arr, int size, int index)
{
	char* temp ;
	int i,j,newsize;
	if (index < size)
	{
		for (i = 0; i < size; i++)
		{
			if (index == i)
			{
				newsize = strlen(arr[i]);
				temp = (char*)malloc(newsize * sizeof(char));//doing a malloc to the temp array 
				strcpy(temp, arr[index]);//coping the arr[index] to the temp array
				strcat(arr[index], temp);//doubling the string in the array
				printf("twice completed\n");
			}
		}
		
	}
	else
	{
		printf("please try again\n");
		menu(arr, size);
	}
	return arr;
}
int find(char** arr, int size, char* str)
{
	int i, j,count=0,newstr=strlen(str),newstr2;
	for (i = 0; i < size; i++)
	{
		count = 0;
		for (j = 0; j < newstr; j++)
		{
			if (arr[i][j] == str[j])//checking if the arr equals the str 
			{
				count++;//6
			}			
		}
		newstr2 = strlen(arr[i]);
		if (count == newstr2)//checking if the arr equals the str  
		{
			return i;// if its equal returning the index
		}
	}
	return -1;
}
void print(char** arr1, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%s ", arr1[i]);//printing the array after doing 
	}
}