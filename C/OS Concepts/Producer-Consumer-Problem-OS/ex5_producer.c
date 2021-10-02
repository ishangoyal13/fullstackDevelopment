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

void produce(struct prod_cons *p)	//increments full and decrements empty
{
	if(p->full == p->n)
	{
		printf("\nBuffers Are Full\n");
		return;
	}
	while(p->full != p->n)	//produce n items
	{
		p->empty--;	//run till empty
		wait_val(&(p->mutex));
		//add item to buffer
		signal_val(&(p->mutex));
		p->full++;
	}
	display_data(p);
}

void main()
{
	int ch, key, shmid;
	key = ftok("ex5_writer.c", 1);
	shmid = shmget(key, sizeof(struct prod_cons), 0666|IPC_CREAT);	//create shared memory
	struct prod_cons* p =(struct prod_cons*)shmat(shmid, 0, 0);
	p->n = 10;
	p->mutex = 1;
	p->full = 0;
	p->empty = p->n;
	do
	{
		printf("\n\t1.Produce\n");
		printf("\n\t2 Display Data\n");
		printf("\n\t3.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				produce(p);
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