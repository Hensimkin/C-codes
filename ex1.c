
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	float startprice = 10.20, km = 1.30, suitcase = 2.00, distance, priceforbaggage, pricefordistance, total; // defining variables
	int  baggage;
	printf("please enter number of suitcases you are carrying:");
	scanf("%d", &baggage);
	priceforbaggage = baggage * suitcase; //multipying the number of baggeges with the price
	printf("please enter the amout of km youre going to travel:");
	scanf("%f", &distance);
	pricefordistance = distance * km; //multipying the number of kilometers with the price
	total = pricefordistance + priceforbaggage + startprice;
	printf("the total price is %.2f", total);
	return 0;



}