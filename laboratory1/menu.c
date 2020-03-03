#include<stdio.h>
#include<ctype.h>
#include"isnumber.h"
#include"task1.h"
#include"task2.h"
#include"task3.h"

int enter_task_number()
{
	char task_number[100];
	do
	{
		printf("\n\nPress the number of task you want to test ( 1 - 4 ) : ");
		gets(task_number);
		if(!(isintnumber(task_number) && ispositivenumber(task_number)))
			printf("You've entered a wrong task number.");
	}	while(!(isintnumber(task_number) && ispositivenumber(task_number)));
	
	return atoi(task_number);
}
void init()
{
	printf("Sonya Pobiedimska");
	printf("\nLaboratory work #1");	
	printf("\n15th variant");
//	printf("\n\nTask 1 : Find the volume of the thor using formula : V=2*pi^2*R*r^2");
//	printf("\n\nTask 2 : Find the radius of circle, built inside the triangle.");
//	printf("\n\nTask 3: Programming bit and shift operations (packing using parameters) . ");
//	printf("\n\nTask 4: Programming bit and shift operations (unpacking) . \n");
}
void init_task(int task_number)
{
	switch(task_number)
	{
		case 1:
		{
			printf("\n\nTask 1 : Find the volume of the thor using formula : \nV=2*pi^2*R*r^2");
			break;
		}
		case 2:
		{
			printf("\n\nTask 2 : Find the radius of circle, built inside the triangle.");
			break;
		}		
		case 3:
		{
			printf("\n\nTask 3: Programming bit and shift operations (packing using parameters) . ");
			break;
		}	
		case 4:
		{
			printf("\n\nTask 4: Programming bit and shift operations (unpacking) . ");
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
			if(task_number<1 ||task_number>4)
				printf("You've entered a wrong task number.");
		} while(task_number<1 ||task_number>4);
		
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
			
			case 3:
				{
					init_task(3);
					program3_packing();
					break;
				}
			
			case 4:
				{
					init_task(4);
					program3_unpacking();
					break;
				}
				
		}
		printf("\n\nIf you want to continue testing program, press c button ... ");
		scanf("%c", &cont);
		getchar();
		
		
	}   while(cont=='c' || cont=='C');
		
	return 0;
}
