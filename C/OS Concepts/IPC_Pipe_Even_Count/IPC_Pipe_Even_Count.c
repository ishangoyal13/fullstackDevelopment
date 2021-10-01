#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<ctype.h>
#include<string.h>

int main()
{
	int arr_r[5], arr_w[5];
	int pipe1[2], pipe2[2],pid;
	pipe(pipe1);	//parent send input array to child
	pipe(pipe2);	//child sends even count to parent
	pid = fork();
	if(pid!=0)	//parent
	{
		int count, i;
		printf("Enter 5 numbers\n");
		for(i=0;i<5;i++)
			scanf("%d",&arr_w[i]);
		//close pipe1's read and pipe2's write which are unnecessary
		close(pipe1[0]);
		close(pipe2[1]);
		//input got as input from parent is passed to child through pipe 1
		write(pipe1[1], arr_w, sizeof(arr_w));
		//get even count passed from child through pipe2
		read(pipe2[0], &count, sizeof(count));
		printf("\nNumber of even numbers is %d\n", count);
	}
	else if(pid==0)	//child
	{
		int i, count=0;
		//close pipe1's writ and pipe2's read which are unnecessary
		close(pipe1[1]);
		close(pipe2[0]);
		//input sent from parent is received in child through pipe 1
		read(pipe1[0], arr_r, sizeof(arr_r));
		for(i=0;i<5;i++)
		{
			if(arr_r[i]%2==0)
				count++;
		}
		//pass count from child to parent through pipe2
		write(pipe2[1], &count, sizeof(count));
	}
	else
	{
		printf("Child Creation Unsuccessfull");
	}
	return 0;
}