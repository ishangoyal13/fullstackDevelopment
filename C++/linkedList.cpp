#include <iostream>
using namespace std;


struct Node{
	int data;
	Node *next;
	Node(int x){
		data=x;
		next=NULL;
	}
}
;
void printList(Node *head){
	Node *curr=head;
	while(curr!=NULL){
		cout<<curr->data<<" ";
		curr=curr->next;
	}
	cout<<endl;
}
void rprint(Node *head){
	if(head==NULL)
		return ;
	cout<<head->data<<" ";
	rprint(head->next);
}

int search(Node *head,int key){
	int pos=1;
	Node *curr=head;
	while(curr!=NULL)
	{
		if(curr->data==key)
			return pos;
		else
		{
			pos++;
			curr=curr->next;
		}
	}
	return -1;
}

int rsearch(Node *head,int key){
	if(head==NULL)
		return -1;
	if(head->data==key)
		return 	1;
	else{
		int res=rsearch(head->next,key);
		if(res== -1)
			return -1;
		else
			return (res+1);
	}
}


Node *insertAtBeg(Node *head ,int val){
	Node *temp=new Node(val);
	temp->next=head;
	return temp;
}


Node *insertAtEnd(Node *head,int val){
	Node *temp=new Node(val);
	if(head==NULL)
		return temp;
	Node *curr=head;
	while(curr!=NULL){
		curr=curr->next;

	}
	curr->next=temp;
	return head;
}

Node *deleteFirstNode(Node *head){
	if(head==NULL)
		return NULL;
	else{
		return head->next;
	}
}
int main(){
Node *head=new Node(10);
Node *temp1=new Node(20);
Node *temp2=new Node(30);
head->next=temp1;
temp1->next=temp2;
printList(head);
rprint(head);
cout<<endl;
cout<<"Element present at position "<<search(head,10)<<endl;

cout<<"Element present at position using recursion "<<rsearch(head,20)<<endl;;

head=insertAtBeg(head,5);
printList(head);

head=insertAtEnd(head,50);
printList(head);

head=deleteFirstNode(head);

printList(head);
return 0;

}