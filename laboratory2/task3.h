#include<stdio.h>
#include<time.h>
//#include"isnumber.h"
void program3 ()
{
	
	srand(time(0));
	
	char rows_str[100], cols_str[100];
	int rows_int, cols_int, i, j;
	do
	{
		
		printf("\n\nEnter the number of rows in a 2d array : ");
		gets(rows_str);

	}	while((!isintnumber(rows_str))||(isintnumber(rows_str) && !ispositivenumber(rows_str)));
	
	do
	{
		
		printf("\n\nEnter the number of columns in a 2d array : ");
		gets(cols_str);

	}	while((!isintnumber(cols_str))||(isintnumber(cols_str) && !ispositivenumber(cols_str)));
	
	rows_int=atoi(rows_str);
	cols_int=atoi(cols_str);
	
	float array[rows_int][cols_int];
	
	char choice_str[100];
	
	do
	{
		printf("\n\nPress 1 - to fill array manually, 2 - to fill with random numbers : ");
		gets(choice_str);
		
	}	while((!isintnumber(choice_str))||(isintnumber(choice_str) && !ispositivenumber(choice_str))||(ispositivenumber(choice_str)&&((atoi(choice_str)<1)||(atoi(choice_str)>2))));
	
	int choice_int;
	choice_int=atoi(choice_str);
	
	char number_chr[100];
	
	for (i=0; i<rows_int; i++)
		for (j=0; j<cols_int; j++)
			array[i][j]=0;
	
	int f, k;
	bool result=true;		
	
	switch(choice_int)
	{
		case 1:
		{
			for (i=0; i<rows_int; i++)
			{
				for (j=0; j<cols_int; j++)
				{
					do
					{
						printf("\n\nEnter the value of element of array, placed in %d row and %d column : ", i+1, j+1);
						gets(number_chr);

					} while(!isnumber(number_chr));
					array[i][j]=atof(number_chr);
				}
			}
			printf("\n\nArray with manually entered numbers :\n");
			for (i=0; i<rows_int; i++)
			{
				printf("\n");
				for (j=0; j<cols_int; j++)
					printf(" %.2f ", array[i][j]);
				printf("\n");
			}
			break;
		}
		
		case 2:
		{
			printf("\n\nArray with random numbers :\n");
			for (i=0; i<rows_int; i++)
			{
				printf("\n");
				for (j=0; j<cols_int; j++)
				{
					do
					{
						array[i][j]= rand () % (rows_int*cols_int);
						result=true;
						
						for (k=0; k<i; k++)			
						{
							for (f=0; f<cols_int; f++)
							{
								if(array[i][j]==array[k][f])
								{
									result=false;
									break;
								}
							}
							
							if(result==false)
								break;
						}
						
						for(f=0;f<j;f++)
						{
							if(array[i][j]==array[i][f])
								{
									result&=false;
									break;
								}
						}
						
					}	while(!result);
					printf(" %.2f ", array[i][j]);
				}
				printf("\n");
			}
			break;
		}		
	}
	
	float *pointer, *pointer_min, *pointer_max, min_value=array[0][0], max_value=array[0][0];
	pointer=&array[0][0];
	float positions[2][2];
	
	for(i=0;i<rows_int*cols_int;pointer++, i++)
	{
		if(*pointer<=min_value)
		{
			min_value=*pointer;
			pointer_min=pointer;
		}
		if(*pointer>=max_value)
		{
			max_value=*pointer;
			pointer_max=pointer;
		}

	}
	printf("\n\nMax value is %.2f .", max_value);
	printf("\n\nMin value is %.2f .", min_value);
		
	float sum=0;
	
    if(!(pointer_min+1==pointer_max || pointer_max+1==pointer_min))
    {
		if(pointer_min<pointer_max)
		{
			for(pointer=pointer_min, sum=0; (pointer+1)<pointer_max;sum+=*++pointer /*printf("\nSum = %f", sum), printf("\nPointer = %p", pointer)/*, pointer++*/);
		}
				
		if(pointer_min>pointer_max)
		{
			for(pointer=pointer_max, sum=0; (pointer+1)<pointer_min; sum+=*++pointer/*, printf("\nSum = %f", sum), printf("\nPointer = %p", pointer)/*, pointer++*/);
		}
    } 
	if(sum==0)	
		printf("\n\nMin and max values are placed next to each other in the array.");
	else 
		printf("\n\nSum of numbers between min ( %.2f ) and max ( %.2f ) values is : %.2f", min_value, max_value, sum);
}
