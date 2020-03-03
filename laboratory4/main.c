#include<stdio.h>
#include<ctype.h>
#include"task1.h"
#include"task2.h"
#include<stdbool.h>
#include"isnumber.h"
#include<stdlib.h>
void init()
{
	printf("Taras Pyndykivskiy");
	printf("\nLaboratory work #4");	
	printf("\n14th variant");
	printf("\n\nTask 1 : Count the number of positive, negative, and zero numbers in the matrix.");
	printf("\n\nTask 2 : Find a digital root of the number using recursive function.");
}

void init_task(int task_number)
{
	switch(task_number)
	{
		case 1:
		{
			printf("\n\nTask 1 : Count the number of positive, negative, and zero numbers in the matrix.");
			break;
		}
		case 2:
		{
			printf("\n\nTask 2 : Find a digital root of the number using recursive function.");
			break;
		}
	}
}

int main(void)
{
	int task_number;
	char cont;
	
	init();
	
	do
	{
		do
		{
			task_number=input_int_positive_number("\n\nPress the number of task you want to test ( 1 - 2 ) : ");	
		} while(task_number<1 || task_number>2);
		
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
