//Find the multiplication of a given number

#include <stdio.h>
int main()
{
    int n, i, range;
    printf("Enter a number = ");
    scanf("%d", &n);
    printf("Enter the range = ");
    scanf("%d", &range);
    for (i = 1; i <= range; i++)
    {
        printf("%d * %d = %d\n", n, i, n * i);
    }
}
