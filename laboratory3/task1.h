#include<stdio.h>
#include<stdbool.h>
#include<string.h>
void program1 ()
{
	char sentence[1000]="";
	int i=0;
	
	printf("\n\nEnter the sentence you want to check on being a palindrom statement : ");
	gets(sentence);
	
	int length, j=0;

	length=strlen(sentence);
	
	for(i=0;i<length;i++)
	{
		if(isalpha(sentence[i]) || isdigit(sentence[i]))
		{
			j++;
			
		}
	}
	char sentence2[j];
	for(i=0, j=0;i<length;i++)
	{
		if(isalpha(sentence[i]) || isdigit(sentence[i]))
		{
			sentence2[j]=sentence[i];
			j++;
		}
	}
	

	if(!(isalpha(sentence2[strlen(sentence2)-1]) || isdigit(sentence2[strlen(sentence2)-1])))
		sentence2[strlen(sentence2)-1]='\0';

	printf("\n\nYour sentence \"%s\" is ", sentence);
	
	length=strlen(sentence2);
	
	for(i=0;i<length;i++)
		sentence2[i]=tolower(sentence2[i]);

	bool result;
	result=true;
	
	for(i=0; i<=(length/2);i++)
		if(!(sentence2[i]==sentence2[length-1-i]))
		{
			result=false;
			break;
		}
	printf(result ? "a palindrom." : "not a palindrom.");
}
