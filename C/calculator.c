#include <stdio.h>
 
int main()
{
	char Operator;
	float number1, number2;
	
	printf("Please Enter Calculation: ");
  	scanf("%f %c %f",&number1, &Operator, &number2);
  	
  	if(Operator == '+')
  	{
  		printf("%.2f", number1 + number2);
  	}
  	else if(Operator == '-')
  	{
  		printf("%.2f", number1 - number2);
  	}
  	else if(Operator == '*')
  	{
  		printf(" %.2f", number1 * number2);
  	}
  	else if(Operator == '/')
  	{
  		printf(" %.2f",  number1 / number2);
  	}
  	else
  	{
  		printf("\n Enetered an Invalid Operator ");
	}
	
  	return 0;
}