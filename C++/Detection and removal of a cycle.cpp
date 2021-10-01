#include <iostream>
using namespace std;

class node
{
  public:
     int data;
     node* next;
     
       node(int val){
         data = val;
         next=NULL;
     }
};

void InsertHead(node* &head, int val)
{
    node* n = new node(val);
    n->next = head;
    head = n;
}

void InsertEnd(node* &head, int val)
{
    
    node* n = new node(val);
    
    if(head==NULL)
    {
        head=n;
        return ;
    }
    
    node* temp = head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next = n;
}

void makeCycle(node* &head, int pos)
{
    node* temp =head;
    node* startNode;
    
    int count=1;
    while(temp->next!=NULL){
        if(count == pos){
            startNode = temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startNode;
}

bool detectCycle(node* &head){
    node* slow = head;
    node* fast = head;
    
    while(fast!=NULL && fast->next!=NULL ){
        slow = slow->next;
        fast = fast->next->next;
        
        if(fast==slow)
        {
            return true;
        }
    }
}

void removeCycle(node* &head)
{
    node* slow = head;
    node* fast = head;
    
    do{
        slow=slow->next;
        fast=fast->next->next;
  
      }while(slow!=fast);
    
    fast=head;
    while(slow->next!= fast->next){
        slow = slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    node* head =NULL;
    InsertEnd(head,1);
    InsertEnd(head,2);
    InsertEnd(head,3); 
    InsertEnd(head,4);
    InsertEnd(head,5);
    InsertEnd(head,6); 
    
    makeCycle(head,3);
   
    cout<<detectCycle(head)<<endl;
    
    removeCycle(head);
    
    cout<<detectCycle(head)<<endl;
    
    display(head);
    
    return 0;
}




