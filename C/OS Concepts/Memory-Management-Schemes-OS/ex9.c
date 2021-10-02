#include<stdio.h>
#include<stdlib.h>

void getDetails(int n, int m, int* process, int* partitions)
{
	int i;
	printf("\nMemory Required for Processes\n");
	printf("-------------------------------\n");
	for(i=0;i<n;i++)
	{
		printf("Enter the required memory space for process %d : ",i+1);
		scanf("%d",&process[i]);
	}
	printf("\nMemory of Free Partitions\n");
	printf("---------------------------\n");
	for(i=0;i<m;i++)
	{
		printf("Enter the memory space of free partition %d : ",i+1);
		scanf("%d",&partitions[i]);
	}
}

void reverseArray(int* partitions, int m)	//reverse input array
{
    int temp, start=0;
    while (start < m)
    {
        temp = partitions[start];  
        partitions[start] = partitions[m];
        partitions[m] = temp;
        start++;
        m--;
    }  
}    

void selectionSort(int* partitions, int m, int type)
{
	//ascending - type =0 ; descending - type =1
    int i, j, min_idx;
    for (i = 0; i < m - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < m; j++)
            if (partitions[j] < partitions[min_idx])
                min_idx = j;
        //swap
        if(i != min_idx)
        {
	        partitions[min_idx] += partitions[i];
	        partitions[i] = partitions[min_idx] - partitions[i];
	        partitions[min_idx] -= partitions[i];
	    }
    }
    if(type==1)
    	reverseArray(partitions, m);	//descending order
}

int first_fit(int n, int m, int* process, int* partitions)
{
	int i, j, ext_frag=0, tot_frag=0, flag=0;

	int* partitions_cpy = (int*)malloc(sizeof(int)*m);	//copy partitions
	for(i=0;i<m;i++)
		partitions_cpy[i] = partitions[i];

	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(process[i] <= partitions[j])
			{
				partitions[j] -= process[i];
				process[i]=0;
			}
	//calc total fragmentation
	for(i=0;i<m;i++)
		tot_frag+=partitions[i];

	for(i=0;i<n;i++)
	{
		if(process[i] != 0)
		{
			printf("Can't allocate for process with memory requirement %d units\n", process[i]);
			flag=1;	
		}
	}
	if(flag==1)//can't allocate all processes
		return 99999;

	for(i=0;i<m;i++)
		if(partitions[i] == partitions_cpy[i])
			ext_frag += partitions[i];		

	printf("Internal Fragmentation : %d\n", (tot_frag-ext_frag));
	printf("External Fragmentation : %d\n", ext_frag);
	printf("Total Fragmentation : %d\n\n", tot_frag);

	free(partitions_cpy);
	return 1;
}

int best_fit(int n, int m, int* process, int* partitions)
{
	selectionSort(partitions, m, 0);	//sorting memory fragments in ascending order
	return first_fit(n, m, process, partitions);
}

int worst_fit(int n, int m, int* process, int* partitions)
{
	selectionSort(partitions, m, 1);	//sorting memory fragments in descending order
	return first_fit(n, m, process, partitions);
}

void copy_vals(int n, int m, int* process, int* process_cpy, int* partitions, int* partitions_cpy)
{
	int i,j;
	for(i=0;i<n;i++)
		process_cpy[i] = process[i];
	for(i=0;i<m;i++)
		partitions_cpy[i] = partitions[i];
}

void optimal(int n, int m, int* process, int* partitions)
{
	int ffit_frag, bfit_frag, wfit_frag;
	int* process_cpy = (int*)malloc(sizeof(int)*n);
	int* partitions_cpy = (int*)malloc(sizeof(int)*m);

	copy_vals(n, m, process, process_cpy, partitions, partitions_cpy);
	printf("\nFirst Fit :\n");
	printf("-----------\n");
	ffit_frag = first_fit(n, m, process_cpy, partitions_cpy);
	copy_vals(n, m, process, process_cpy, partitions, partitions_cpy);
	printf("\nBest Fit :\n");
  	printf("------------\n");
	bfit_frag = best_fit(n, m, process_cpy, partitions_cpy);
	printf("\nWorst Fit :\n");
  	printf("-------------\n");
	wfit_frag = worst_fit(n, m, process, partitions);

	if(ffit_frag!=-1)
		if(ffit_frag<=bfit_frag && ffit_frag<=wfit_frag)
			printf("\nFirst Fit is the Optimal Alogirthm\n");
	else if(bfit_frag!=-1)
		if(bfit_frag<=ffit_frag && bfit_frag<=wfit_frag)
			printf("\nBest Fit is the Optimal Alogirthm\n");
	else if(wfit_frag!=-1)
		if(wfit_frag<=bfit_frag && wfit_frag<=ffit_frag)
			printf("\nWorst Fit is the Optimal Alogirthm\n");

	free(process_cpy);
	free(partitions_cpy);
}

int main()
{
	int n, ch, m, out,i;
	int* process;
	int* partitions;
	
	printf("\nEnter the number of processes : ");
	scanf("%d",&n);
	printf("Enter the number of free partitions : ");
	scanf("%d",&m);
	//dynamic memory allocation
	process = (int*)malloc(sizeof(int)*n);
	partitions = (int*)malloc(sizeof(int)*m);

	getDetails(n, m, process, partitions);

	printf("\n\t1.First Fit\n");
	printf("\n\t2.Best Fit\n");
	printf("\n\t3.Worst Fit\n");
	printf("\n\t4.Optimal Fitting Algorithm\n");
	printf("\n\t5.Exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		{
			printf("\nFirst Fit :\n");
		  	printf("-----------\n");
		  	out = first_fit(n, m, process, partitions);
		  	if(out == 99999)
		  		printf("\nAll Process can't be allocated\n");
		  	break;
		}
		case 2:
		{
			printf("\nBest Fit :\n");
		  	printf("----------\n");
		  	out = best_fit(n, m, process, partitions);
		  	if(out == 99999)
		  		printf("\nAll Process can't be allocated\n");
		  	break;
		}
		case 3:
		{
			printf("\nWorst Fit :\n");
			printf("-----------\n");
			out = worst_fit(n, m, process, partitions);
		  	if(out == 99999)
		  		printf("\nAll Process can't be allocated\n");
		  	break;
		}
		case 4:
		{
			printf("\nOptimal Algorithm :\n");
			printf("-------------------\n");
			optimal(n, m, process, partitions);
			break;
		}
		case 5:
			free(process);
			free(partitions);
			exit(0);
		default:
			printf("Invalid Choice\n");
	}
	free(process);
	free(partitions);
	return 0;
}