#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/wait.h>

int main()
{
	int p1, p2,n=8,i, inp[8], key, shmid;
	key = ftok("ex3_2.c", 1);
	shmid = shmget(key, 8*sizeof(int),0666|IPC_CREAT);	//create shared memory
	int* shared_mem =(int*)shmat(shmid, 0, 0);

	p1=fork();
	if(p1==0)	//child 1
	{
		int* shared_mem =(int*)shmat(shmid, 0, 0);
		printf("Enter 4 elements\n");
		for(int i=0;i<4;i++) 		//input from child 1
			scanf("%d",&shared_mem[i]);
		shmdt(0);
	}
	else if(p1>0) // parent
	{
		wait(NULL);
		p2 =fork();
		if(p2==0)
		{
			int* shared_mem =(int*)shmat(shmid, 0, 0);
			printf("Enter 4 elements\n");
			for(int i=4;i<8;i++) 		//input from child 1
				scanf("%d",&shared_mem[i]);
			shmdt(0);
		}
		else
		{
			wait(NULL);
			int* shared_mem =(int*)shmat(shmid, 0, 0);
			for(int i=0;i<4;i++) 		//input from child 1
				shared_mem[i] += shared_mem[i+4];
			printf("Sum of the matrices\n");
			for(int i=0;i<4;i++)
				printf("%d\n", shared_mem[i]);
		}
	}

}