#include<string.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
// function return true if entered string is a number, false otherwise

int is_number(char data[]);
//bool is_int_number(char *number);
//bool is_positive_number(char *number);
//bool is_hexadecimal_number(char *number);
//int input_int_positive_number(char *prompt);
//float input_float_positive_number(char *prompt);
//int input_int_number(char *prompt);
//float input_float_number(char *prompt);

int is_number(char data[])
{
	int dotcounter=0;
	if(data[strlen(data)-1]=='.')
		return 0;	
	if(data=='\0' || data==NULL || data[0]=='.')	
		return 0;
	int i;	
	for(i=0; i<strlen(data);i++)
	{
		if(isdigit(data[i]) || (data[i]=='.' ) || (data[i]=='+' ) || (data[i]=='-' ))
		{
			if(i==0 && ((data[i]=='+') || (data[i]=='-')))
				continue;
			else if(i!=0 && ((data[i]=='+') || (data[i]=='-')) || (data[i]=='.' && ++dotcounter>1))
				return 0;
//			else continue;
		}
		else return 0;
	}	
	return 1;
}
int is_int_number(char number[])
{
	int i;
	int result=1;
	if(is_number(number))
	{
		for(i=0; i<strlen(number); number++)
		{
			if(number[i]=='.')
			{
				result=0;
				break;
			}
		}

		return result;
	}
	else 
		return 0;
}

int is_positive_number(char number[])
{
	if(is_number(number))
	{
		if(atoi(number)==0)
			return 0;
		if(isdigit(number[0]))
			return 1;
		else if(number[0]=='+')
			return 1;
		else if(number[0]=='-')
			return 0;
	}
	else return 0;
}

int is_hexadecimal_number(char number[])
{
	int i=0;
	for(i=0; i<strlen(number); i++)
	{
		if(!(isdigit(number[i]) || (number[i]>='a' && number[i]<='f') || (number[i]>='A' && number[i]<='F')))
			return 0;
	}
	return 1;
}

int input_int_positive_number(char prompt[])
{
	char number[100];
	do
	{
		printf(prompt);
		gets(number);
		if(!(is_int_number(number) && is_positive_number(number)))
			printf("\nYou've entered a wrong value");
		
	}	while(!(is_int_number(number)==1 && is_positive_number(number)==1));
	
	return atoi(number);
}

float input_float_positive_number(char prompt[])
{
	char number[100];
	do
	{
		printf(prompt);
		gets(number);
		if(!(is_positive_number(number)==1))
			printf("\nYou've entered a wrong value.");
		
	}	while(!(is_positive_number(number)==1));
	
	return atof(number);
}

int input_int_number(char prompt[])
{
	char number[100];
	do
	{
		printf(prompt);
		gets(number);
		if(!(is_int_number(number)==1))
			printf("\nYou've entered a wrong value");
		
	}	while(!(is_int_number(number)==1));
	
	return atoi(number);
}

float input_float_number(char prompt[])
{
	char number[1000];
	do
	{
		printf(prompt);
		gets(number);
		if(!(is_number(number)==1))
			printf("\nYou've entered a wrong value");
		
	}	while(!(is_number(number)==1));
	
	return atof(number);
}
