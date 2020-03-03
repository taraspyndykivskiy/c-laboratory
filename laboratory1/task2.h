#include<stdio.h>
#include<math.h>
float enter_data(int side_number)
{
	char side_length[100];
	do
	{
		switch(side_number)
		{
			case 1:
				printf("\n\nEnter the length of the first side of triangle : ");
				break;
			case 2:
				printf("\n\nEnter the length of the second side of triangle : ");
				break;
			case 3:
				printf("\n\nEnter the length of the third side of triangle : ");
				break;
			default:
				printf("Error");
				break;
		}
		gets(side_length);
//		scanf("%s", &side_length);
//		getchar();
		if(!(isnumber(side_length))  || (isnumber(side_length) && (!ispositivenumber(side_length)))|| (atof(side_length)==0))
		{
			if((!ispositivenumber(side_length) && isnumber(side_length)) || (atof(side_length)==0))
				printf("\n\nThe length of side of triangle can't be less or equal to zero!!!");
			if(!(isnumber(side_length)))
				printf("\n\nYou've entered a wrong value of side length");
			continue;
		}
			
	} while(!isnumber(side_length)  || (isnumber(side_length) && (!ispositivenumberr(side_length))) || (atof(side_length)==0)) ;
	
	return atof(side_length);
}

void program2()
{
	float first_side=0, second_side=0, third_side=0;
	
	first_side=enter_data(1);
	second_side=enter_data(2);
	third_side=enter_data(3);
		
	while((first_side+second_side<=third_side)||(second_side+third_side<=first_side)||(first_side+third_side<=second_side))	
	{
		printf("\n\nThe triangle with such sides can't exist !!!\n\n");
		first_side=enter_data(1);
		second_side=enter_data(2);
		third_side=enter_data(3);
	}
	
	
	float area=0, half_perimeter=0, radius=0;
	
	half_perimeter=(first_side+second_side+third_side)/2;
	
	area=sqrt(half_perimeter*(half_perimeter-first_side)*(half_perimeter-second_side)*(half_perimeter-third_side));
	
	radius=area/half_perimeter;
	
	printf("\n\nThe radius of circle, built inside the triangle with sides %.2f, %.2f, %.2f is : %.2f\n\n", first_side, second_side, third_side, radius);
}
