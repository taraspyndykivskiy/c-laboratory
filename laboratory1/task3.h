#include<stdio.h>
//#include"isnumber.h"

void program3_packing()
{
	char block_number[100], segment_size[100];	
	char read_access[100], write_access[100];	
	unsigned int unitstatecode;
	
	do
	{
		printf("\n\nEnter the number of block ( 0 - 255 ): ");
		scanf("%s", &block_number);
		getchar();
	}	while((!ispositivenumber(block_number) || ( ispositivenumber(block_number) && ( atoi(block_number)<0 ||  atoi(block_number)>255 )))||(!isintnumber(block_number)));
	do
	{
		printf("\n\nEnter the state of read access ( 0 - 1 ): ");
		scanf("%s", &read_access);
		getchar();
		
	}while((!ispositivenumber(read_access) || ( ispositivenumber(read_access) && ( atoi(read_access)<0 ||  atoi(read_access)>1 )))||(!isintnumber(read_access)));
	
	do
	{
		printf("\n\nEnter the state of write access ( 0 - 1 ): ");
		scanf("%s", &write_access);
		getchar();
	}	while((!ispositivenumber(write_access) || ( ispositivenumber(write_access) && ( atoi(write_access)<0 ||  atoi(write_access)>1 )))||(!isintnumber(write_access)));
	do
	{
		printf("\n\nEnter the segment size ( 0 - 63 ): ");
		scanf("%s", &segment_size);
		getchar();
	}	while((!isnumber(segment_size) || ( isnumber(segment_size) && ( atoi(segment_size)<0 ||  atoi(segment_size)>63 )))||(!isintnumber(segment_size)));
	
	int block_number_int, segment_size_int;
	int read_access_int, write_access_int;
	
	block_number_int=atoi(block_number);
	segment_size_int=atoi(segment_size);
	read_access_int=atoi(read_access);
	write_access_int=atoi(write_access);
	
	unitstatecode=((unsigned int) block_number_int & 0xFF)<<8;
	unitstatecode|=((unsigned int) read_access_int & 1)<<7;
	unitstatecode|=((unsigned int) write_access_int & 1)<<6;
	unitstatecode|=segment_size_int & 0x3F;
	
	printf("\n\nDevice's state code : %04x", unitstatecode);
	
}

void program3_unpacking()
{
	char unitstatecode[100];
	do
	{
		printf("\n\nEnter hexadecimal number ( 0 - FFFF ) : ");
		scanf("%s", &unitstatecode);
		getchar();
	} while(!ishexadecimalnumber(unitstatecode) || (ishexadecimalnumber(unitstatecode) && strlen(unitstatecode)>4));
	
	int unitstatecode_int;
	sscanf(unitstatecode, "%x", &unitstatecode_int);
	
	unsigned char block_number, segment_size;	
	unsigned char read_access, write_access;
	
	block_number=(unitstatecode_int >> 8) & 0xFF;
	read_access=(unitstatecode_int >> 7) & 1;
	write_access=(unitstatecode_int >> 6) & 1;
	segment_size=unitstatecode_int & 0x3F;
	
	printf("\n\nThe number of block is : %d", block_number);
	printf("\n\nThe state of read access : %d", read_access);
	printf("\n\nThe state of write access : %d", write_access);
	printf("\n\nThe size of segment is : %d", segment_size);
}

