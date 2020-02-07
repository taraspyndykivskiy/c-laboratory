#include<stdio.h>
#include<ctype.h>
#include"isnumber.h"
#include"task1.h"
#include"task2.h"

int enter_task_number()
{
	char task_number[100];
	do
	{
		printf("\n\nPress the number of task you want to test ( 1 - 2 ) : ");
		gets(task_number);

	}	while(!(isintnumber(task_number) && ispositivenumber(task_number)));
	
	return atoi(task_number);
}
void init()
{
	printf("Taras Pyndykivskiy");
	printf("\nLaboratory work #2");	
	printf("\n14th variant");
}
void init_task(int task_number)
{
	switch(task_number)
	{
		case 1:
		{
			printf("\n\nTask 1 : Print out the elements that occur only 3 times in array .");
			break;
		}
		case 2:
		{
			printf("\n\nTask 2 : Sort array using selection sort.");
			break;
		}		
	}
}

int main(int argc, char *argv[])
{
	int task_number;
	char cont;
	
	init();
	
	do
	{
		do
		{
			task_number=enter_task_number();	
		} while(task_number<1 ||task_number>2);
		
		switch(task_number)
		{
			case 1:
			{
				init_task(1);
				program1();
				break;
			}
			
			case 2:
			{
				init_task(2);
				program2();
				break;
			}							
		}
		printf("\n\nIf you want to continue testing program, press c button ... ");
		scanf("%c", &cont);
		getchar();
		
		
	}   while(cont=='c' || cont=='C');
		
	return 0;
}
