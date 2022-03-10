
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct {
	int DayNumber;
	int WorkHours;
} WorkDay;
typedef struct {
	long ID;
	int HourlySal; 
	int workdays; 
	WorkDay* wd; 
	double salary; 
} Worker;
void InputWorkDay(WorkDay* pWD);
void PrintWorkDay(WorkDay wd);
void InputWorker(Worker* pW);
void PrintWorker(Worker w);
Worker* InitFactory(int* pSize);
void PrintFactory(Worker* pWorker, int size);
void  CalculateSalary(Worker* pWorker, int size);
int main()
{
	Worker* pFactory = NULL;
	int size,i;
	printf("please enter mumber of workers");
	scanf("%d", &size);
	pFactory = InitFactory(&size);
	CalculateSalary(pFactory, size);//calling to the calculate function
	PrintFactory(pFactory, size);
	for (i = 0; i < size;i++)
	{
		free(pFactory[i].wd);
	}
	return 0;

}
void InputWorkDay(WorkDay* pWD)//the function scans the day number and the amount of hours 
{

	int i;
	printf("please enter a day: ");
	scanf("%d", &pWD->DayNumber);
	printf("please enter hours: ");
	scanf("%d", &pWD->WorkHours);	
}
void PrintWorkDay(WorkDay wd)
{
	printf("day:%d\n", wd.DayNumber); //printing the days and the hours
	printf("hours:%d\n", wd.WorkHours);
}
void InputWorker(Worker* pW) //scanning the worker k
{
	int count=0,i;
	printf("please enter your ID: ");
	scanf("%d", &pW->ID);//pointing to the id in the struct
	printf("please enter your hour salary: ");
	scanf("%d", &pW->HourlySal);
	printf("please enter number of days: ");
	scanf("%d", &pW->workdays);
	pW->wd = (WorkDay*)malloc(pW->workdays * sizeof(WorkDay));
	{
		if (pW->wd == NULL)
		{
			return NULL;
		}
	}
	printf("please enter hours and days :");
	for (i = 0; i < pW->workdays; i++)
	{
		InputWorkDay(&pW->wd[i]);
	}
	
	
}
void PrintWorker(Worker w)//printing workers index such as id work days
{
	int hours,i;
	printf("worker id %d\n", w.ID);
	printf("worker hoursalary %d\n", w.HourlySal);
	printf("total workdays in the month %d\n", w.workdays);
	printf("worker total salary %lf\n", w.salary);
	for (i = 0; i < w.workdays; i++)
	{
		PrintWorkDay(w.wd[i]);
	}
	
	
}
Worker* InitFactory(int* pSize) //doing an array for the worker
{
	int i;
	Worker* pFactory = NULL;
	pFactory = (Worker*)malloc(*pSize * sizeof(Worker));
	if (pFactory == NULL)
	{
		printf("error");
		return NULL;
	}
	for (i = 0; i < *pSize; i++)
	{
		InputWorker(&pFactory[i]);
	}
	return pFactory;
}
void PrintFactory(Worker* pWorker, int size)//printing the worker stuff
{
	int i;
	for (i = 0; i < size; i++)
	{
		PrintWorker(pWorker[i]);
	}
}
void  CalculateSalary(Worker* pWorker, int size)//calculating the workers salary
{
	int totalhours = 0, i;
	for (i = 0; i < pWorker->workdays; i++)
	{
		totalhours = totalhours + (pWorker->wd[i].WorkHours);
	}
	pWorker->salary = totalhours * (pWorker->HourlySal);
}