#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/wait.h>

struct prod_cons
{
	int mutex;	//mutual exclusion variable
	int full;	//number of full buffers
	int empty;	//number of empty buffers
	int n;	//total number of buffers
};

void wait_val(int *t)	//wait 
{
	while(*t <= 0);	//busy wait
	*t--;
}

void signal_val(int *t)	//signal
{
	*t++;
}

void display_data(struct prod_cons *t)	//display full and empty values
{
	printf("---------------------------------------\n");
	printf("Total Number of Buffers : %d\n", t->n);
	printf("Number of Full Buffers : %d\n", t->full);
	printf("Number of Empty Buffers : %d\n", t->empty);
	printf("---------------------------------------\n");
}

void consume(struct prod_cons *p)	//decrements full and increments empty
{
	if(p->empty == p->n)
	{
		printf("\nBuffers Are Emplty\n");
		return;
	}
	while(p->empty != p->n)
	{
		p->full--;
		wait_val(&(p->mutex));
		//remove an item
		signal_val(&(p->mutex));
		p->empty++;
		//consume
	}
	display_data(p);
}

void main()
{
	int ch, key, shmid;
	key = ftok("ex5_writer.c", 1);
	shmid = shmget(key, sizeof(struct prod_cons), 0666|IPC_CREAT);	//create shared memory
	struct prod_cons* p =(struct prod_cons*)shmat(shmid, 0, 0);
	do
	{
		printf("\n\t1.Consume\n");
		printf("\n\t2 Display Data\n");
		printf("\n\t3.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				consume(p);
				break;
			}
			case 2:
			{
				display_data(p);
				break;
			}
			case 3:
			{
				break;
			}
			default:
				printf("Invalid Choice\n");
		}
	}while(ch!=3);
	shmdt(0);
	shmctl(shmid, IPC_RMID, NULL);	
}