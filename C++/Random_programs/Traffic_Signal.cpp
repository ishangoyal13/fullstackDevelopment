#include <stdio.h>
#include <stdlib.h>
void enqueue(int cq[],int *rear,int val,int MAX)
{
	if((*front == 0 && *rear == MAX-1) || (*front == *rear+1))
	{
		printf("Queue Overflow \n");
		return;
	}
	if (*front == -1) 
	{
		*front = 0;
		*rear = 0;
	}
	else
	{
		if(*rear == MAX-1)
			*rear = 0;
		else
			*rear = *rear+1;
	}
	cq[*rear] = val ;
}
char dequeue(int cq[],int *front,int MAX){
	if (*front == -1)
	{
		printf("Queue Underflow\n");
		
	}

	if(*front == *rear) 
	{
		*front = -1;
		*rear=-1;
	}
	else
	{	
		if(*front == MAX-1)
			*front = 0;
		else
			*front = *front+1;
	}
	return cq[*front];
	}
	
int main(){
	int q[6],r=-1,f=-1;
	printf("\tR1\tR2\tR3\tR4\tR5\tR6\n\n");
	for(int i=0;i<6;i++){
	enqueue(q,&r,0,6);
	enqueue(q,&r,0,6);
	enqueue(q,&r,0,6);
