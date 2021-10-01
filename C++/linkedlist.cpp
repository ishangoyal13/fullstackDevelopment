
#include <iostream>
using namespace std;
struct node{
    int data;
    node *ptr;
};
struct node *head=NULL;
void insert(int a){
    struct node *temp=new node;
    temp->data=a;
    temp->ptr=head;
    head=temp;
}
void display(){
    struct node *p;
    p=head;
    while(p!=NULL){
        cout<<p->data<<endl;
        p=p->ptr;//over here pts is acting as a link
    }
}
int main()
{
    insert(5);
    insert(88);
    insert(52);
    insert(6);
    insert(0);
    cout<<"The Linked List is\n";
    display();

}
