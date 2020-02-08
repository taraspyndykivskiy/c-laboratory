#include<stdio.h>
#include<time.h>
//#include"isnumber.h"

void program2()
{
	srand(time(0));
	
	char length[100];
	int length_int, i, j;
	
	do
	{
		
		printf("\n\nEnter the length of array of numbers : ");
		gets(length);

	}	while((!isintnumber(length))||(isintnumber(length) && !ispositivenumber(length)));
	
	length_int=atoi(length);
	float array[length_int];
	
	char choice_str[100];
	
	do
	{
		printf("\n\nPress 1 - to fill array manually, 2 - to fill with random numbers : ");
		gets(choice_str);
		
	}	while((!isintnumber(choice_str))||(isintnumber(choice_str) && !ispositivenumber(choice_str))||(ispositivenumber(choice_str)&&((atoi(choice_str)<1)||(atoi(choice_str)>2))));
	
	int choice_int, c;
	
	choice_int=atoi(choice_str);
	char number_chr[100];
	switch(choice_int)
	{
		case 2:
		{
			printf("\n\nArray with random numbers :\n\n");
			for (i=0; i<length_int; i++)
			{

				array[i]= rand () % length_int;
				printf("%.0f\t", array[i]);
			}
			break;
		}		
		case 1:
		{
			for (i=0; i<length_int; i++)
			{
				do
				{
					printf("\n\nEnter the value of %d element of array : ", i+1);
					scanf("%s", &number_chr);
				} while(!isnumber(number_chr));
				array[i]=atof(number_chr);
			}
			printf("\n\nArray with manually entered numbers :\n\n");
			for (i=0; i<length_int; i++)
				printf("%.0f\t", array[i]);
			break;
		}
	}
	
	for(i=1;i<length_int;i++)
	{
		for(j=i;j>0;j--)
		{
			if(array[j]<array[j-1])
			{
				c=array[j-1];
				array[j-1]=array[j];
				array[j]=c;
			}
		}
	}
	
	printf("\n\nSorted array: \n\n");
		for (i=0; i<length_int; i++)
			printf("%.0f\t", array[i]);

}
