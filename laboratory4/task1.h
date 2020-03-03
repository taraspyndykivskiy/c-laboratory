#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
//#include"isnumber.h"
void program1 ()
{
	
//	srand(time(0));
	
	int rows, cols, i, j;
	
	rows=input_int_positive_number("\n\nEnter the number of rows in a 2d array : ");
	
	cols=input_int_positive_number("\n\nEnter the number of cols in a 2d array : ");
		
	
	int choice;
	
	do
	{
		
		choice=input_int_positive_number("\n\nPress 1 - to fill array manually, 2 - to fill with random numbers : ");
		
	} while(choice<0 || choice>2);

//	char number_chr[100];
	
	float array[rows][cols];
	
	for (i=0; i<rows; i++)
		for (j=0; j<cols; j++)
			array[i][j]=0;
	
	int f, k;
//	bool result=true;		
	char prompt[100];
	//char array[10];
	//sprintf(array, "%f", 3.123);
	
	char data[100];
	
	
	switch(choice)
	{
		case 1:
		{
			for (i=0; i<rows; i++)
			{
				for (j=0; j<cols; j++)
				{
					do
					{
						printf("\n\nEnter the value of number in %d row and %d column : ", i+1, j+1);
						gets(data);
//						if(!(is_number(data)))
//							printf("\nYou have entered wrong value");
					} while((is_number(data)!=true));
					
					array[i][j]=atof(data);
				
				}
			}
			printf("\n\nArray with manually entered numbers :\n");
			for (i=0; i<rows; i++)
			{
				printf("\n");
				for (j=0; j<cols; j++)
					printf(" %.2f ", array[i][j]);
				printf("\n");
			}
			break;
		}
		
		case 2:
		{
			printf("\n\nArray with random numbers :\n");
			for (i=0; i<rows; i++)
			{
				printf("\n");
				for (j=0; j<cols; j++)
				{
					array[i][j]= rand () % (rows*cols) - (rand() % (rows*cols)/2);
					printf(" %.2f ", array[i][j]);
				}
				printf("\n");
			}
			break;
		}		
	}
	
	float *pointer;
	pointer=&array[0][0];
	int counter_negative=0, counter_positive=0, counter_zeros=0;
	
	
	
	for(i=0;i<rows*cols; pointer++, i++)
	{
		if(*pointer<0)
			counter_negative++;
		else if(*pointer>0)
			counter_positive++;
		else if((int)*pointer==0)
			counter_zeros++;
	}
	
	printf("\n\nThe matrix contains %d positive numbers.", counter_positive);
	printf("\n\nThe matrix contains %d negative numbers.", counter_negative);
	printf("\n\nThe matrix contains %d zero numbers.", counter_zeros);
	
}

