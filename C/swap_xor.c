//swap two numbers without using 3rd variable
//xor bitwise operator is used

#include<stdio.h>
int main()
{
 int a, b;
 printf("Enter first number:");
 scanf("%d", &a);
 printf("Enter second number:");
 scanf("%d", &b);
 printf("\nBefore swapping:\nFirst number:%d",a);
 printf("\nSecond number:%d",b);
 a=a^b;
 b=a^b;
 a=a^b;
 printf("\n\nAfter swapping:\nFirst number:%d",a);
 printf("\nSecond number:%d",b);
 return 0;
 }
