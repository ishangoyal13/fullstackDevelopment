#include<stdio.h>
#include<conio.h>
int Q[40];
int front = -1;
int rear = -1;
struct node {
	int vertex;
	struct node *next;
};
struct Graph {
	int numvertices;
	struct node **adjLists;
	int *visited;
};
struct node *createNode (int v){
	struct node *newNode = malloc (sizeof (struct node));
	newNode->vertex = v;
	newNode->next = NULL;
	return newNode;
}
struct Graph *createAGraph (int vertices) {
	struct Graph *graph = malloc (sizeof (struct node));
	graph->numvertices = vertices;
	graph->adjLists = malloc(vertices * sizeof (struct node));
	graph->visited = malloc(vertices * sizeof (int));
	int i;
	for (i=0;i<vertices;i++){
		graph->adjLists[i] = NULL;
		graph->visited[i] = 0;
	}
	return graph;
}
void addEdge (struct Graph *graph, int s, int d) {
	struct node *newNode = createNode(d);
		if( graph->adjLists[s] == NULL) {
		newNode->next = graph->adjLists[s];
		graph->adjLists[s] = newNode;
	}
	else {
		struct node *temp = graph->adjLists[s];
		while(temp->next != NULL){
			temp=temp->next;
		}
		temp->next=newNode;
	}
	
	newNode = createNode(s);
		if( graph->adjLists[d] == NULL) {
		newNode->next = graph->adjLists[d];
		graph->adjLists[d] = newNode;
	}
	else {
		struct node *temp = graph->adjLists[d];
		while(temp->next != NULL){
			temp=temp->next;
		}
		temp->next=newNode;
	}
}
void bfs(struct Graph *graph, int start){
	struct node *temp;
	int current;
	graph->visited[start] = 1;
	
	enqueue(start);
	
	while(! isEmpty())
	{
		current = dequeue();
		printf("\n Visted : %d \n \n",current);
		
		temp = graph->adjLists[current];
		while(temp){
			int adj = temp->vertex;
			if(graph->visited[adj] == 0)
			{
				graph->visited[adj] = 1;
				enqueue(adj);
			}
			temp = temp->next;
		}
		printQueue();
	}
	
}
void enqueue(int v)
{
	if(isEmpty())
	{
		front = 0;
		Q[++rear] = v;
	}
	else{
		Q[++rear] = v;
	}
}
int dequeue(){
	int temp;
	if(isEmpty()){
		printf("Queue is Empty\n");
		return 0;
	}
	else if(rear == front){
		temp = Q[front];
		front = -1;
		rear = -1;
		return temp;
	}
	else{
		temp = Q[front];
		front++;
		return temp;
	}
}
int isEmpty(){
	if(rear == -1 & front == -1){
		return 1;
	}
	return 0;
}
void printQueue () {
	int i;
	printf("Queue Contains : \t \t");
	if (isEmpty()) {
		printf("Queue Empty");
	} else {
		for(i=front;i<=rear;i++)
		{
			printf("%d \t",Q[i]);
		}
	}	
}
int main () {
	int n,i,s,d;
	struct Graph *graph;
	printf("Enter no. of edges\n");
	scanf("%d",&n);
	graph = createAGraph(n);
	for(i=0;i<n;i++){
		printf("enter source and destination :\t");
		scanf("%d %d",&s,&d);
		addEdge(graph,s,d);
	}
	bfs(graph,0);
	
	return 0;
}
