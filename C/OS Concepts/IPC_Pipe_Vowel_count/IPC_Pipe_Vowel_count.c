#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<ctype.h>
#include<string.h>

int main()
{
	char str_r[20], str_w[20];
	int pipe1[2], pipe2[2],pid;
	pipe(pipe1);	//parent send input string to child
	pipe(pipe2);	//child sends vowel count to parent
	pid = fork();
	if(pid!=0)	//parent
	{
		int count;
		printf("Enter string\n");
		scanf("%s",str_w);
		//close pipe1's read and pipe2's write which are unnecessary
		close(pipe1[0]);
		close(pipe2[1]);
		//input string got as input from parent is passed to child through pipe 1
		write(pipe1[1], str_w, sizeof(str_w));
		//get vowel count passed from child through pipe2
		read(pipe2[0], &count, sizeof(count));
		printf("\nNumber of vowels in the string %s is %d\n", str_w, count);
	}
	else if(pid==0)	//child
	{
		int i, count=0;
		//close pipe1's writ and pipe2's read which are unnecessary
		close(pipe1[1]);
		close(pipe2[0]);
		//input string sent from parent is received in child through pipe 1
		read(pipe1[0], str_r, sizeof(str_r));
		for(i=0;i<strlen(str_r);i++)
		{
			str_r[i] = toupper(str_r[i]);
			if(str_r[i]=='A' || str_r[i]=='E' || str_r[i]=='I' || str_r[i]=='O' || str_r[i]=='U')
				count++;
		}
		//pass vowel count from child to parent through pipe2
		write(pipe2[1], &count, sizeof(count));
	}
	else
	{
		printf("Child Creation Unsuccessfull");
	}
	return 0;
}