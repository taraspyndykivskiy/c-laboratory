#include<stdio.h>
#include<ctype.h>
#include"task1.h"
#include"isnumber.h"

int enter_task_number()
{
	char task_number[100];
	do
	{
		printf("\n\nPress the number of task you want to test ( 1 ) : ");
		gets(task_number);

	}	while(!(isintnumber(task_number) && ispositivenumber(task_number)));
	
	return atoi(task_number);
}
void init()
{
	printf("Taras Pyndykivskiy");
	printf("\nLaboratory work #3");	
	printf("\n14th variant");
	printf("\n\nTask 1 : Text is given. Determine if it is a palindrome.\nThe difference between lowercase and uppercase letters is ignored.");
}
void init_task(int task_number)
{
	switch(task_number)
	{
		case 1:
		{
			printf("\n\nTask 1 : Text is given. Determine if it is a palindrome.\nThe difference between lowercase and uppercase letters is ignored.");
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
		} while(task_number!=1);
		
		switch(task_number)
		{
			case 1:
			{
				init_task(1);
				program1();
				break;
			}
		}
		printf("\n\nIf you want to continue testing program, press c button ... ");
		scanf("%c", &cont);
		getchar();
		
		
	}   while(cont=='c' || cont=='C');
		
	return 0;
}
