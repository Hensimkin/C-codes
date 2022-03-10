
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int test, project, work1, work2, work3, work4, work5;
	int lastgrade, worktotal, sumoftest, sumofproject, sumofworkstotal;
	printf("please enter the test grade");
	scanf("%d", &test);
	if (test < 56)
	{
		printf("your final grade is %d and you failed", test);
	}
	else
	{
		printf("please enter the project grade");
		scanf("%d", &project);
		printf("please enter the work1 grade");
		scanf("%d", &work1);
		printf("please enter the work2 grade");
		scanf("%d", &work2);
		printf("please enter the work3 grade");
		scanf("%d", &work3);
		printf("please enter the work4 grade");
		scanf("%d", &work4);
		printf("please enter the work5 grade");
		scanf("%d", &work5);
		worktotal = (work1 + work2 + work3 + work4 + work5) / 5;//doing the avarage of the 5 works
		sumoftest = 0.7 * test;
		sumofproject = 0.1 * project;
		sumofworkstotal = 0.2 * worktotal;
		lastgrade = sumoftest + sumofproject + sumofworkstotal;//calculating the sum of all test exam and works
		printf("your final grade is %d and you passed", lastgrade);
	}

	return 0;
}