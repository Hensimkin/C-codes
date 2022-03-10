
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	float triangle, rectangle, square, circle, height, base, radius;
	const float pie = 3.14;
	int num;
	printf("please enter a number between 1 and 4\n1=triangle\n2=retangle\n3=square\n4=circle\n");
	scanf("%d", &num);
	if (num == 1)
	{
		printf("please enter the hight and the base");
		scanf("%f %f", &height, &base); //scaning the numbers the user inserted
		triangle = (height * base) / 2; //calculating the triangle area
		printf("the height is %f\nthe base is %f\nthe area is %f", height, base, triangle);
	}
	else if (num == 2)
	{
		printf("please enter the hight and the base");
		scanf("%f %f", &height, &base);//scaning the numbers the user inserted
		rectangle = (height * base);//calculating the rectangle area
		printf("the height is %f\nthe base is %f\nthe area is %f", height, base, rectangle);
	}
	else if (num == 3)
	{
		printf("please enter the lengh of the sqaure edge");
		scanf("%f", &height);//scaning the numbers the user inserted
		square = (height * height);//calculating the square area
		printf("the lengh of the square edge is %f\nthe area is %f", height, square);
	}
	else if (num == 4)
	{
		printf("please radius");
		scanf("%f", &radius);//scaning the numbers the user inserted
		circle = (radius * radius) * pie;//calculating the circle area
		printf("the radius is %f\nthe area is %f", radius, circle);
	}
	else
		printf("error");
	return 0;
}