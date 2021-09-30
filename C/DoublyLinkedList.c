#include<stdio.h>
#include<stdlib.h>
struct Node//creating the configuration of  a node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head=NULL;
//****************************************************************************
void create()//function for creating a node
{
struct Node *ptr,*current;
char ch;
ptr=NULL;
current=NULL;
do
{
 ptr=(struct Node*)malloc(sizeof(struct Node));
 if(ptr==NULL)
 {
    printf("Memory Insufficient");
    return;
 }
 printf("Enter the data for the node\n");
  scanf("%d",&ptr->data);
  ptr->next=NULL;
  ptr->prev=NULL;
  if(head==NULL)//if node is not there
  {
   head=ptr;
   current=ptr;
  }
  else//if at least one node is there
  {
   current->next=ptr;
   ptr->prev=current;
   current=ptr;
  }
  printf("Want to create more node Y or N\n");
  fflush(stdin);
  scanf("%c",&ch);
 }
 while(ch=='Y'||ch=='y');
 printf("-----------------------------------------------------------------\n");
 printf("The Linked List is created!!\n");
}
//*******************************************************************************
void insertFirstNode()//inserting node at the beginning of  doubly linked list...
{
struct Node *new;
new=(struct Node*)malloc(sizeof(struct Node));
printf("Enter the value for the node to be inserted\n");
scanf("%d",&new->data);
new->prev=NULL;
new->next=NULL;
if(head==NULL)
head=new;
else
{
 head->prev=new;
  new->next=head;
 head=new;
}
}
//*******************************************************************************
void deleteFirstNode()//deleting the first node of the doubly linked list
{
struct Node *k;
if(head==NULL)
printf("\nList is Empty!!\n");
else
{
 k=head;
head=head->next;
head->prev=NULL;
free(k);
}
}
//*********************************************************************************
void display()
{
 struct Node *temp;
 temp=head;
 while(temp!=NULL)
 {
  printf("%d ",temp->data);
  temp=temp->next;
 }
 printf("\n");
}
//***********************************************************************************
int menu()
{
int choice;
printf("1.Inserting the node at the beginning of the doubly linked list\n");
printf("2.Deleting the 1st node of the doubly linked list\n");
printf("3.Displaying the doubly linked list\n");
printf("4.Exit!!\n");
printf("Enter the choice\n");
scanf("%d",&choice);
return(choice);
}
//***********************************************************************************
void main()
    {
        printf("Create the linked list\n");
        create();
         printf("\n*****************************************************\n");
        while(1)
     {
        switch(menu())
        {
           case 1:insertFirstNode();
                  printf("\n*****************************************************\n");
                   break;
           case 2:deleteFirstNode();
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


