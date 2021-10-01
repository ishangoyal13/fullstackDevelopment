#include <stdio.h>
#include<stdlib.h>
void input_data(int n, int m, int *available, int* cpy_available, int **max, int **allocation, int** cpy_allocation, int  **need, int** cpy_need)
{
	int i, j;

	printf("\nAvailability of Resources\n");
	printf("---------------------------\n");
	//available
	for(i=0;i<m;i++)
	{
		printf("Number of available instances for resource %d : ", i+1);
		scanf("%d",&available[i]);
		cpy_available[i] = available[i];
	}

	//allocation
	printf("\n---------------------------\n");
	printf("Allocation of Resources\n");
	printf("---------------------------\n\n");
	for(i=0;i<n;i++)
	{
		printf("-------------------\n");
		printf("Process %d :\n", i+1);
		printf("-------------------\n");
		for(j=0;j<m;j++)
		{
			printf("Number of instances of resource %d currently allocated : ", j+1);
			scanf("%d",&allocation[i][j]);
			cpy_allocation[i][j] = allocation[i][j];
		}
	}

	//max
	printf("\n---------------------------\n");
	printf("Maximum Allocation\n");
	printf("---------------------------\n\n");
	for(i=0;i<n;i++)
	{
		printf("-------------------\n");
		printf("Process %d :\n", i+1);
		printf("-------------------\n");
		for(j=0;j<m;j++)
		{
			printf("Number of instances of resource %d the process may request at maximum : ", j+1);
			scanf("%d",&max[i][j]);
			need[i][j] = max[i][j] - allocation[i][j];
			cpy_need[i][j] = need[i][j];
		}
	}
}

int banker_alg(int *avail, int** need, int **allocation, int n, int m)
{
	int skipped=0, cnt=0, completed =0, i, j;
	int* finish = (int*)malloc(sizeof(int)*n);	//to denote completed processes
	int* done = (int*)malloc(sizeof(int)*n);	//to denote completed processes
	for(i=0;i<n;i++)
		done[i]=-1;

	while(skipped != n-completed)	//skipped should not be equal to the all remaining process - means unsafe
	{
		for(i=0;i<n;i++)
		{
			if(done[i] != -1) //already completed
				continue;

			for(j=0;j<m;j++)
				if(need[i][j] <= avail[j])
					cnt++;

			if(cnt==m)	//process can be allocated
			{
				for(j=0;j<m;j++)
					avail[j] += allocation[i][j];
				finish[completed++] = i;
				done[i]=1;
				skipped=0;
			}
			else
				skipped++;

			cnt=0;
		}
	}

	if(n != completed)	//unsafe
		return -1;
	else	//safe so print order of allocation
	{
		printf("\n\nOrder of Resource Allocation for the processes : ");
		for(i=0;i<n;i++)
			printf("%d ", finish[i]);
		printf("\n");
		return 1;
	}
}

void resource_req(int n, int m, int* cpy_available, int** cpy_need, int** cpy_allocation, int* req, int pr)
{
	int i,j, cnt=0;

	for(j=0;j<m;j++)
	{
		if(req[j] <= cpy_need[pr-1][j] && req[j] <= cpy_available[j])
			cnt++;
		else
		{
			printf("Invalid Request\n");
			return;
		}
	}

	for(j=0;j<m;j++)
	{
		cpy_available[j] -= req[j];
		cpy_allocation[pr-1][j] += req[j];
		cpy_need[pr-1][j] -= req[j];
	}

	if(banker_alg(cpy_available, cpy_need, cpy_allocation, n, m) == -1)
		printf("\n\n!!! Unsafe System !!!\n");
}

void main()
{
	int n;	//number of processes
	int m;	//number of resorce types
	int* available;	//available vector - number of instances of each resources
	int** max; // Max[i,j] process Pi may request at most k instances of resorce type Rj
	int** allocation;	//Allocation[i,j]-process Pi is currently allocated K instances of Rj
	int** need;	//Need[i,j] - process Pi may need k more instances of Rj need = max - allocation
	int* cpy_available;
	int** cpy_need;
	int** cpy_allocation;
	int* req;

	int i, j, pr;

	printf("Enter the number of processes : ");
	scanf("%d",&n);
	printf("Enter the number of resources types : ");
	scanf("%d",&m);
	//dynamic memory allocation 
	available = (int*)malloc(sizeof(int)*m);
	cpy_available = (int*)malloc(sizeof(int)*m);
	max = (int**)malloc(sizeof(int*)*n);
	allocation = (int**)malloc(sizeof(int*)*n);
	cpy_allocation = (int**)malloc(sizeof(int*)*n);
	need = (int**)malloc(sizeof(int*)*n);
	cpy_need = (int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++)
	{
		max[i] = (int*)malloc(sizeof(int)*m);
		allocation[i] = (int*)malloc(sizeof(int)*m);
		cpy_allocation[i] = (int*)malloc(sizeof(int)*m);
		need[i] = (int*)malloc(sizeof(int)*m);
		cpy_need[i] = (int*)malloc(sizeof(int)*m);
	}

	input_data(n, m, available, cpy_available, max, allocation, cpy_allocation, need, cpy_need);
	if(banker_alg(available, need, allocation, n, m)==-1)
	{
		printf("\n\n!!! Unsafe System !!!\n");
		return;
	}
	else
	{
		req = (int*)malloc(sizeof(int)*m);
		printf("Enter the process number which requests for resource : ");
		scanf("%d",&pr);
		printf("Enter the resource request by the process :");
		for(i=0;i<m;i++)
			scanf("%d",&req[i]);
		resource_req(n, m, cpy_available, cpy_need, cpy_allocation, req, pr);
	}
}