#include<stdio.h>
#include<stdlib.h>

int a[10];
int top=-1;
void push()
{
int item;
int capacity=10;
printf("Enter the value to be pushed in stack\n");
scanf("%d",&item);
if(top==capacity-1)
{
    printf("Stack overflow or the stack is full\n");
    return;
}
else
   {
    top++;
    a[top]=item;
   }
 }
 //..........................................................................................
 void pop()
 {
 int k=0;
 if(top==-1)
{
    printf("Stack underflow or stack is empty\n");
    return;
}
 else
 {
     k=a[top];
     top--;
     printf("%d is popped out from the stack\n",k);
   }
 }
 //...............................................................................................
 void display()
 {
     printf("Displaying all the elements of the stack\n");
     for(int i=top;i>=0;i--)
     { printf("%d \n",a[i]);}
 }
 //...............................................................................................
 int menu()
{
int choice;
printf("1.Push\n");
printf("2.Pop\n");
printf("3.Display the stack\n");
printf("4.Exit!!\n");
printf("Enter the choice\n");
scanf("%d",&choice);
return(choice);
}
//................................................................................................
void main()
    {
        printf("The size of the arrray is 10\n");
         printf("\n*****************************************************\n");
        while(1)
     {
        switch(menu())
        {
           case 1:push();
                  printf("\n*****************************************************\n");
                   break;
           case 2:pop();
                  printf("\n*****************************************************\n");
                  break;
           case 3:display();
                  printf("\n*****************************************************\n");
                  break;
           case 4: printf("\n.........................EXIT...................................\n");
                   exit(0);
          default:printf("\nPlease enter the correct choice\n");
                  printf("\n*****************************************************\n");
            }
         }
       }
