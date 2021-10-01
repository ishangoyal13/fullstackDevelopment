// Doubly Linked List - Insertion, Deletion, Display
#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};
void insertHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    if(head!=NULL){
        head->prev = n;
    }
    head = n;
}
void insertTail(node* &head, int val){

    if(head == NULL){
        insertHead(head, val);
        return;
    }
    node* n = new node(val);
    node* temp = head;

    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = n;
    n->prev = temp;
}
void deleteHead(node* &head)
{
    node* todelete = head;
    head = head->next;
    head->prev = NULL;
    delete todelete;
}
void deletion(node* &head, int pos)
{
    if(pos == 1){
        deleteHead(head);
        return;
    }
    node* temp = head;
    int count = 1;
    while(temp!=NULL && count!=pos){
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if(temp->next!=NULL)
        temp->next->prev = temp->prev;
    delete temp;
}
void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    node* head = NULL;
    insertTail(head, 2);
    insertTail(head, 3);
    display(head);
    insertHead(head, 1);
    display(head);
    return 0;
}
