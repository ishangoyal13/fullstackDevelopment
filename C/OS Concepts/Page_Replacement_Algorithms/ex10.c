#include<stdio.h>
#include<stdlib.h>

int hit_miss(int* frame_list, int pg, int frame_n)	//to check for page hit or miss
{
	int i;
	for(i=0;i<frame_n;i++)
		if(frame_list[i] == pg)
			return 1;	//hit
	return -1;	//miss
}

void FIFO(int ref_n, int *ref_list, int frame_n)	//First-in first-out
{
	int i, j, hit=0, ind=0;
	int* frame_list = (int*)malloc(sizeof(int)*frame_n);
	for(i=0;i<frame_n;i++)	//initially frame list = -1
		frame_list[i] = -1;

	printf("\nPages in Frame\n");
	printf("----------------\n");
	for(i=0;i<ref_n;i++)
	{
		if(hit_miss(frame_list, ref_list[i], frame_n) == 1)	//hit
			hit++;
		else
		{
			frame_list[ind%frame_n] = ref_list[i];
			ind++;
		}
		printf("\n");
		for(j=0;j<frame_n;j++)
			printf("%d ", frame_list[j]);
		printf("\n");
	}
	printf("\nPage Hits : %d\n", hit);
	printf("Page Faults : %d\n", ref_n - hit);
	free(frame_list);
}

void LRU(int ref_n,int *ref_list,int frame_n)
{
	int i, j, hit=0, max_ind=0;

	int* frame_list = (int*)malloc(sizeof(int)*frame_n);
	for(i=0;i<frame_n;i++)	//initially frame list = -1
		frame_list[i] = -1;

	int* replacement_vect = (int*)malloc(sizeof(int)*frame_n);	//replacement vector used for page swap
	for(i=0;i<frame_n;i++)	//initially replacement list = frame_n
		replacement_vect[i] = frame_n;

	printf("\nPages in Frame\n");
	printf("----------------\n");
	for(i=0;i<ref_n;i++)
	{
		max_ind = 0;
		for(j=1;j<frame_n;j++)	//find Leastly used page
			if(replacement_vect[j] > replacement_vect[max_ind])
				max_ind = j;

		if(hit_miss(frame_list, ref_list[i], frame_n) == 1)	//hit
		{
			hit++;
			continue;
		}
		else	//miss
		{
			frame_list[max_ind] = ref_list[i];
			replacement_vect[max_ind]--;
		}

		printf("\n");
		for(j=0;j<frame_n;j++)
			printf("%d ", frame_list[j]);
		printf("\n");
	}
	printf("\nPage Hits : %d\n", hit);
	printf("Page Faults : %d\n", ref_n - hit);

}


void main()
{
	int ref_n, frame_n, pg_fault=0, frame_index=0, ch;
	int *ref_list;
	
	printf("Enter Reference size : ");
	scanf("%d",&ref_n);

	ref_list= (int*)malloc(sizeof(int)*ref_n);
	printf("Enter the Reference List :\n");
 	for(int i=0;i<ref_n;i++)
    	scanf("%d",&ref_list[i]);

    printf("\nEnter Frame Size : ");
	scanf("%d",&frame_n);
    do
	{
		printf("\n1.FIFO Replacement Algorithm\n");
		printf("\n2.LRU Replacement Algorithm\n");
		printf("\n3.Exit\n\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				FIFO(ref_n,ref_list,frame_n);
				break;
			}
			case 2:
			{
				LRU(ref_n,ref_list,frame_n);  
				break;
			}
			default:
				break;
		}break;//reomve
	}while(ch != 3);
}