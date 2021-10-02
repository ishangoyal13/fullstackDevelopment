#include<stdio.h>
#include<sys/msg.h>

int main()
{
	struct mesg_buffer 
	{
	    long mesg_type;	//message type
	    int arr[10];	//message content
	};
	int msg_id;
	struct mesg_buffer message;
	message.mesg_type = 1;
	key_t my_key = ftok("./ex3_4_1.c", message.mesg_type);
	msg_id = msgget(my_key, 0666|IPC_CREAT);
	printf("Enter 10 numbers\n");
	for(int i=0;i<10;i++)
		scanf("%d",&message.arr[i]);
	msgsnd(msg_id, &message, sizeof(message), 0);
}