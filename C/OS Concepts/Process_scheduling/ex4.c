#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
	int id, arrival_t, burst_t, priority, wait_t, turn_around_t, end_t, start_t;
	struct Node* next;
};

struct Node* Node_construct(int i, int a, int b, int p)	//constructor function for Node
{
	struct Node* n=(struct Node*)malloc(sizeof(struct Node));
	n->id =i;
	n->arrival_t = a;
	n->burst_t = b;
	n->priority = p;
	n->next=NULL;
	return n;
}

struct Node* Node_construct1(int i, int a, int b, int p, int w, int t, int e, int s)	//constructor function for Node
{
	struct Node* n=(struct Node*)malloc(sizeof(struct Node));
	n->id =i;
	n->arrival_t = a;
	n->burst_t = b;
	n->priority = p;
	n->wait_t = w;
	n->turn_around_t = t;
	n->end_t = e;
	n->start_t = s;
	n->next=NULL;
	return n;
}

struct Queue
{
	struct Node* front;	//front of queue
	struct Node* rear;	//rear of queue
	int num_p; //number of process in queue
};

struct Queue* Queue_construct()
{
	struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
	q->front=NULL;
	q->rear=NULL;
	q->num_p = 0;
	return q;
}

int isEmpty(struct Queue* q)	//return T if queue is empty
{
	return q->front==NULL;
}

void enqueue(struct Queue* q, struct Node* n)	//enqueue node to queue
{
	if(q->rear==NULL && q->front==NULL)	//empty queue
	{
		q->front = n;
		q->rear = n;
	 	q->front->next = NULL;
	 	q->rear->next = NULL;
	}
	else	//non-empty queue
	{
		q->rear->next = n;
		q->rear = n;
	}
	q->num_p++;	//incrementing number of process in queue
}

void dequeue(struct Queue* q)
{
	struct Node* temp;
	if (q->front == NULL)
		return;
 	temp = q->front;
	q->front = q->front->next;
 	if (q->front == NULL)	//if only one node in the queue
  		q->rear = NULL;
  	q->num_p--;	//decrementing number of processes in queue
  	free(temp);
}

void getDetails(int n,struct Queue *q)	//get details of the n processes
{
	int id,arrival_t,burst_t,priority;
	for(id=0;id<n;id++)
	{
		printf("\n Process %d:\n",id+1);
		printf("-----------------------\n");
		printf("Arrival time : ");
		scanf("%d",&arrival_t);
		printf("Burst time : ");
		scanf("%d",&burst_t);
		printf("Priority : ");
		scanf("%d",&priority);
		struct Node* n = Node_construct(id, arrival_t, burst_t, priority);	//create node
		enqueue(q, n);	//enque node to queue
 	}
}

struct Node* Node_construct_gant(int i, int st, int end)	//constructor function for Node for gant chart
{
	struct Node* n=(struct Node*)malloc(sizeof(struct Node));
	n->id =i;
	n->start_t = st;
	n->end_t = end;
	return n;
}

void print_gant(struct Queue* q)
{
	struct Node* temp = q->front;
	printf("\n");
	while(temp!=NULL)
	{
		printf("Process%d : (%d-%d)\n",temp->id,temp->start_t,temp->end_t);
		temp = temp->next;
	}
}

void swap(struct Node* min, struct Node* temp1)	//swap contents
{
	struct Node* temp2 = Node_construct(min->id, min->arrival_t, min->burst_t, min->priority);

	min->id=temp1->id;
	min->arrival_t=temp1->arrival_t;
	min->burst_t=temp1->burst_t;
	min->priority=temp1->priority;

	temp1->id=temp2->id;
	temp1->arrival_t=temp2->arrival_t;
	temp1->burst_t=temp2->burst_t;
	temp1->priority=temp2->priority;
}

void bubbleSort_arrival(struct Node *start)	//sort by arrival time
{
    int swapped, i;
    struct Node *ptr1;
    struct Node *lptr = NULL;
  
    if (start == NULL)
        return;
    do
    {
        swapped = 0;
        ptr1 = start;
        while (ptr1->next != lptr)
        {
            if (ptr1->arrival_t > ptr1->next->arrival_t)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

void bubbleSort_burst(struct Node *start)	//sort by burst time
{
    int swapped, i;
    struct Node *ptr1;
    struct Node *lptr = NULL;
  
    if (start == NULL)
        return;
    do
    {
        swapped = 0;
        ptr1 = start;
        while (ptr1->next != lptr)
        {
            if (ptr1->burst_t > ptr1->next->burst_t)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

void bubbleSort_priority(struct Node *start)	//sort by burst time
{
    int swapped, i;
    struct Node *ptr1;
    struct Node *lptr = NULL;
  
    if (start == NULL)
        return;
    do
    {
        swapped = 0;
        ptr1 = start;
        while (ptr1->next != lptr)
        {
            if (ptr1->priority < ptr1->next->priority)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}


int min(int a, int b)	//minimum of two numbers
{
	if(a<b)
		return a;
	else
		return b;
}

int hash(int val)	//hash function mod 10 of p_id
{
	return (val%10);
}

float fcfs(struct Queue* q)	//fcfs
{
	int prev_end=-1;
	float avg_turnAround=0.0, avg_wait=0.0;
	struct Node* gant_node;
	struct Queue* g = Queue_construct();
	struct Node *temp;
	bubbleSort_arrival(q->front);	//sort by arrival time
    temp=q->front;
    while(temp!=NULL)
    {
    	if(prev_end < temp->arrival_t)
    		prev_end = temp->arrival_t;

    	temp->start_t = prev_end;									//time at which process started executing
		temp->end_t = temp->start_t + temp->burst_t;				//time at which process finished execution
		temp->turn_around_t = temp->end_t - temp->arrival_t;
		temp->wait_t = temp->turn_around_t - temp->burst_t;
		prev_end = temp->end_t;

    	gant_node = Node_construct_gant(temp->id, temp->start_t, temp->end_t);
		enqueue(g, gant_node);

		avg_turnAround += (float)temp->turn_around_t;
		avg_wait += (float)temp->wait_t;

    	temp=temp->next;
    }
    print_gant(g);
	printf("\nAverage Turn-Around Time : %f\n", avg_turnAround/q->num_p);
	printf("Average Wait Time : %f\n", avg_wait/q->num_p);
	return (avg_wait/q->num_p);
}

float sjf(int n, struct Queue* q)
{
	int current_t=-1;
	float avg_turnAround=0.0, avg_wait=0.0;
	struct Node *temp;
	struct Node* gant_node;
	struct Queue* temp_q = Queue_construct();
	struct Queue* g = Queue_construct();

	bubbleSort_arrival(q->front);	//sort by arrival time

	while(q->num_p != 0)
	{
		if(current_t < q->front->arrival_t)
	    		current_t = q->front->arrival_t;
	    	
	    temp = q->front;
		while(temp!=NULL && temp->arrival_t <= current_t)
		{
			struct Node* temp2 = Node_construct(temp->id, temp->arrival_t, temp->burst_t, temp->priority);
			enqueue(temp_q, temp2);  //enqueue process with arrival <= current to temporary queue 
			dequeue(q);
			temp = q->front;
		}

		bubbleSort_burst(temp_q->front);	//sort process in temporary queue by burst time

		temp = temp_q->front;

		temp->start_t = current_t;									//time at which process started executing
		temp->end_t = temp->start_t + temp->burst_t;				//time at which process finished execution
		temp->turn_around_t = temp->end_t - temp->arrival_t;
		temp->wait_t = temp->turn_around_t - temp->burst_t;

		current_t = temp->end_t;

		gant_node = Node_construct_gant(temp->id, temp->start_t, temp->end_t);
		enqueue(g, gant_node);

		avg_turnAround += (float)temp->turn_around_t;
		avg_wait += (float)temp->wait_t;

		dequeue(temp_q);
	}

	temp = temp_q->front;
	while(temp!=NULL)
	{
		temp->start_t = current_t;									//time at which process started executing
		temp->end_t = temp->start_t + temp->burst_t;				//time at which process finished execution
		temp->turn_around_t = temp->end_t - temp->arrival_t;
		temp->wait_t = temp->turn_around_t - temp->burst_t;

		current_t = temp->end_t;

		gant_node = Node_construct_gant(temp->id, temp->start_t, temp->end_t);
		enqueue(g, gant_node);

		avg_turnAround += temp->turn_around_t;
		avg_wait += temp->wait_t;

		temp = temp->next;
	}
	print_gant(g);
	printf("\nAverage Turn-Around Time : %f\n", avg_turnAround/n);
	printf("Average Wait Time : %f\n", avg_wait/n);
	return (avg_wait/n);
}

float prior(int n, struct Queue* q)
{
	int current_t=-1;
	float avg_turnAround=0.0, avg_wait=0.0;
	struct Node *temp;
	struct Node* gant_node;
	struct Queue* temp_q = Queue_construct();
	struct Queue* g = Queue_construct();

	bubbleSort_arrival(q->front);	//sort by arrival time

	while(q->num_p != 0)
	{
		if(current_t < q->front->arrival_t)
	    		current_t = q->front->arrival_t;
	    	
	    temp = q->front;
		while(temp!=NULL && temp->arrival_t <= current_t)
		{
			struct Node* temp2 = Node_construct(temp->id, temp->arrival_t, temp->burst_t, temp->priority);
			enqueue(temp_q, temp2);  //enqueue process with arrival <= current to temporary queue 
			dequeue(q);
			temp = q->front;
		}

		bubbleSort_priority(temp_q->front);	//sort process in temporary queue by priority

		temp = temp_q->front;

		temp->start_t = current_t;									//time at which process started executing
		temp->end_t = temp->start_t + temp->burst_t;				//time at which process finished execution
		temp->turn_around_t = temp->end_t - temp->arrival_t;
		temp->wait_t = temp->turn_around_t - temp->burst_t;

		current_t = temp->end_t;

		gant_node = Node_construct_gant(temp->id, temp->start_t, temp->end_t);
		enqueue(g, gant_node);

		avg_turnAround += temp->turn_around_t;
		avg_wait += temp->wait_t;

		dequeue(temp_q);
	}

	temp = temp_q->front;
	while(temp!=NULL)
	{
		temp->start_t = current_t;									//time at which process started executing
		temp->end_t = temp->start_t + temp->burst_t;				//time at which process finished execution
		temp->turn_around_t = temp->end_t - temp->arrival_t;
		temp->wait_t = temp->turn_around_t - temp->burst_t;

		current_t = temp->end_t;

		gant_node = Node_construct_gant(temp->id, temp->start_t, temp->end_t);
		enqueue(g, gant_node);

		avg_turnAround += temp->turn_around_t;
		avg_wait += temp->wait_t;

		temp = temp->next;
	}
	print_gant(g);
	printf("\nAverage Turn-Around Time : %f\n", avg_turnAround/n);
	printf("Average Wait Time : %f\n", avg_wait/n);
	return (avg_wait/n);
}

float roundRobin(int n, struct Queue* q, int tq)
{
	int i, cnt=0, flag=0, current_t=-1, t, turn_around_hash[10], wait_hash[10], burst_hash[10];
	float avg_turnAround=0.0, avg_wait=0.0;
	struct Node *temp;
	struct Node* rem;
	struct Node* gant_node;
	struct Queue* temp_q = Queue_construct();
	struct Queue* g = Queue_construct();

	bubbleSort_arrival(q->front);	//sort by arrival time

	temp = q->front;	//store burst_t in hash table
	while(temp!=NULL)
	{
		burst_hash[hash(temp->id+1)] = temp->burst_t;
		temp = temp->next;
	}

	while(!(isEmpty(q) && isEmpty(temp_q)))
	{
		while(!isEmpty(q))
			if(current_t < q->front->arrival_t)
				current_t++;
			else
				break;

		while(!isEmpty(temp_q))
			if(current_t < temp_q->front->arrival_t)
				current_t++;
			else
				break;

	    temp = q->front;
		while(temp!=NULL && temp->arrival_t <= current_t)
		{
			struct Node* temp2 = Node_construct(temp->id+1, temp->arrival_t, temp->burst_t, temp->priority);
			enqueue(temp_q, temp2);  //enqueue process with arrival <= current to temporary queue 
			dequeue(q);
			temp = q->front;
		}

		if(flag==1)
		{
			enqueue(temp_q, rem);
			flag=0;
		}

		temp = temp_q->front;

		temp->start_t = current_t;									//time at which process started executing
		t = min(temp->burst_t, tq);	//minimum of time quantum and burst time
		temp->end_t = temp->start_t + t;				//time at which process finished execution

		temp->turn_around_t = temp->end_t - temp->arrival_t;
		turn_around_hash[hash(temp->id)] = temp->turn_around_t;

		temp->burst_t -= t;
		if(temp->burst_t != 0)
		{
			rem = Node_construct(temp->id, temp->arrival_t, temp->burst_t, temp->priority);
			flag = 1;
		}
		else
			cnt++;

		current_t = temp->end_t;

		gant_node = Node_construct_gant(temp->id, temp->start_t, temp->end_t);
		enqueue(g, gant_node);

		dequeue(temp_q);

		if(cnt==n)
			break;
	}
	temp = g->front;
	while(temp->next!=NULL)
	{
		printf("Process%d : (%d-%d)\n",temp->id,temp->start_t,temp->end_t);
		temp = temp->next;
	}

	for(i=1;i<=n;i++)
	{
		wait_hash[i] = turn_around_hash[i] - burst_hash[i];
		avg_turnAround += turn_around_hash[i];
		avg_wait += wait_hash[i];
	}
	printf("\nAverage Turn-Around Time : %f\n", avg_turnAround/n);
	printf("Average Wait Time : %f\n", avg_wait/n);
	return (avg_wait/n);
}

void optimal(int n, struct Queue* q, int tq)
{
	int i;
	float arr[4], min;

	struct Node* t=q->front;
	struct Queue* fcfs_q = Queue_construct();
	struct Queue* sjf_q = Queue_construct();
	struct Queue* prior_q = Queue_construct();
	struct Queue* roundRobin_q = Queue_construct();

	while(t!=NULL)
	{
		enqueue(fcfs_q,Node_construct1(t->id,t->arrival_t,t->burst_t,t->priority,t->wait_t,t->turn_around_t,t->end_t,t->start_t));
		enqueue(sjf_q,Node_construct1(t->id,t->arrival_t,t->burst_t,t->priority,t->wait_t,t->turn_around_t,t->end_t,t->start_t));
		enqueue(prior_q,Node_construct1(t->id,t->arrival_t,t->burst_t,t->priority,t->wait_t,t->turn_around_t,t->end_t,t->start_t));
		enqueue(roundRobin_q,Node_construct1(t->id,t->arrival_t,t->burst_t,t->priority,t->wait_t,t->turn_around_t,t->end_t,t->start_t));
		t=t->next;
	}

	printf("\nFCFS:");
	arr[0] = fcfs(fcfs_q);

	printf("\nSJF:");
	arr[1] = sjf(n, sjf_q);
	
	printf("\nPriority:");
	arr[2] = prior(n, prior_q);
	
	printf("\nRound Robin:");
	arr[3] = roundRobin(n, roundRobin_q, tq);
	min = arr[0];
	
	for(i=0; i<3; i++)
	{
		if(arr[i]>arr[i+1])
			min=arr[i+1];
	}

	if(min==arr[0])
		printf("\nFCFS is the Optimal Job Scheduling Algorithm with Average Waiting Time");
	else if(min==arr[1])
		printf("\nSJF is the Optimal Job Scheduling Algorithm with Average Waiting Time");
	else if(min==arr[2])
		printf("\nPriority is the Optimal Job Scheduling Algorithm with Average Waiting Time");
	else if(min==arr[3])
		printf("\nRound Robin is the Optimal Job Scheduling Algorithm with Average Waiting Time");
	printf(" : %f\n", min);
}

int main()
{
	int n,ch,tq;
	float avg_wait_t;
	struct Queue* q = Queue_construct();
	do
	{
		printf("Enter total number of processes\n");
		scanf("%d",&n);
		getDetails(n,q);
		printf("\n\nScheduling Types :\n");
		printf("-----------------------\n");
		printf("\n\t1.First Come First Serve\n");
		printf("\n\t2 Shortest Job First\n");
		printf("\n\t3.Priority Schedule (Higher Number - Higher Priority)\n");
		printf("\n\t4.Round Robin\n");
		printf("\n\t5.Optimal Algorithm\n");
		printf("\n\t6.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
			  	avg_wait_t=fcfs(q);	//first come first serve
			  	break;
			}
			case 2:
			{
			  	avg_wait_t=sjf(n, q);	//shortest job first
				break;
			}
			case 3:
			{
				avg_wait_t=prior(n, q);		//priority
				break;
			}
			case 4: 
			{
				printf("\nEnter quantum time\n");
			  	scanf("%d",&tq);
				avg_wait_t=roundRobin(n,q,tq);
				break;
			}
			case 5:
			{
				int tq;
				printf("\nEnter quantum time\n");
			  	scanf("%d",&tq);
				optimal(n, q, tq);
				break;
			}
			case 6:
				exit(0);
			default:
				printf("Invalid Choice\n");
		}
		//remove
		break;
	}while(ch!=6);
	return 0;
}