#include<stdio.h>
#include<math.h>
//#include"isnumber.h"
void program1 ()
{
	char bigger_radius[100], smaller_radius[100];
	float bigger_radius_fl=0, smaller_radius_fl=0;
	float volume=0;
	
	do
	{
		printf("\n\nEnter the value of smaller radius : ");
		gets(smaller_radius);
//		scanf("%s", &smaller_radius);
//		getchar();
		if((!(isnumber(smaller_radius)) || (isnumber(smaller_radius) && !ispositivenumber(smaller_radius))))
			printf("\n\nYou've entered a wrong value of radius\n\n");
		

	} while(!(isnumber(smaller_radius)) || (isnumber(smaller_radius) && !ispositivenumber(smaller_radius)));
	
	smaller_radius_fl=atof(smaller_radius);
	
	do
	{
		printf("\n\nEnter the value of bigger radius : ");
		gets(bigger_radius);
//		scanf("%s", &bigger_radius);		
//		getchar();
		if(!(isnumber(bigger_radius)) || (isnumber(bigger_radius) && !ispositivenumber(bigger_radius)))
			printf("\n\nYou've entered a wrong value of radius\n\n");
	} while(!(isnumber(bigger_radius)) || (isnumber(bigger_radius) && !ispositivenumber(bigger_radius)));
	
	bigger_radius_fl=atof(bigger_radius);
	volume=2*pow(M_PI, 2)*bigger_radius_fl*smaller_radius_fl;
	
	printf("\n\nThe volume of thor figure is : %f\n\n", volume);
}
