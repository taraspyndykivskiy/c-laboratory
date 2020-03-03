#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
//#include"isnumber.h"
long int sum_ciphers(long int number)
{
	long int sum=0, bufer=number;
	while(number>0)
	{
		sum+=number%10;
		number=(int)(number/10);
	}
	return sum;
}
long int digital_root(long int number)
{
	if(number>=0 && number<=9)
		return number;
	else
		digital_root(sum_ciphers(number));
}
void program2()
{
	long int number=0;
	number=input_int_positive_number("\n\nEnter a positive integer (natural) number : ");
	printf("\n\nThe digital root of number %d is %d", number, digital_root(number));
}
