#include<string.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
// function return true if entered string is a number, false otherwise

bool isnumber(char data[100])
{
	int dotcounter=0;
	if(data[strlen(data)-1]=='.')
		return false;
	if(data=='\0' || data==NULL || data[0]=='.')	
		return false;
	int i;	
	for(i=0; i<strlen(data);i++)
	{
		if(isdigit(data[i]) || (data[i]=='.' ) || (data[i]=='+' ) || (data[i]=='-' ))
		{
			if(i==0 && ((data[i]=='+') || (data[i]=='-')))
				continue;
			else if(i!=0 && ((data[i]=='+') || (data[i]=='-')))
				return false;
			if(data[i]=='.' && ++dotcounter>1)
				return false;
			else continue;
		}
		else return false;
	}	
	return true;
}
bool isintnumber(char number[100])
{
	int i;
	bool result=true;
	if(isnumber(number))
	{
		for(i=0; i<strlen(number); number++)
		{
			if(number[i]=='.')
			{
				result=false;
				break;
			}
		}

		return result;
	}
	else 
		return false;
}

bool ispositivenumber(char number[100])
{
	if(isnumber(number))
	{
		if(isdigit(number[0]))
			return true;
		else if(number[0]=='+')
			return true;
		else if(number[0]=='-')
			return false;
	}
	else return false;
}
bool ispositivenumberr(char number[100])
{
	if(isnumber(number))
	{
		if(isdigit(number[0]))
			return true;
		else if(number[0]=='+')
			return true;
		else if(number[0]=='-')
			return false;
	}
	else return false;
}
bool ishexadecimalnumber(char number[100])
{
	int i=0;
	for(i=0; i<strlen(number); i++)
	{
		if(!(isdigit(number[i]) || (number[i]>='a' && number[i]<='f') || (number[i]>='A' && number[i]<='F')))
			return false;
	}
	return true;
}
