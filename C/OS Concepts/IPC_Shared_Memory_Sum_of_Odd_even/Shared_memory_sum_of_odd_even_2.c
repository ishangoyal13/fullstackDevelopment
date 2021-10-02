#include<stdio.h>
#include<sys/msg.h>

int main()
{
	struct mesg_buffer 
	{
	    long mesg_type;
	    int arr[10];
	};
	int msg_id, key, even=0, odd=0;
	struct mesg_buffer message;
	message.mesg_type=1;
	key_t my_key = ftok("./ex3_4_1.c", message.mesg_type);
	msg_id = msgget(my_key, 0666|IPC_CREAT);
	msgrcv(msg_id, &message, sizeof(message), 1, 0);
	for(int i=0;i<10;i++)
	{
		if(message.arr[i]%2==0)
			even+=message.arr[i];
		else
			odd+=message.arr[i];
	}
	printf("Sum of Odd Numbers : %d\n",odd);
	printf("Sum of Even Numbers : %d\n",even);
	msgctl(msg_id, IPC_RMID, NULL);
}