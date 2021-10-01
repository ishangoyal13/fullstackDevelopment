#include <iostream>
using namespace std;

class node{
public:
    int data;
    node*next;
//Constructor 
    node(int d){
        this-> data = d ;
        this-> next = NULL;
    }
};


void insertAtHead(node* &head, int d){
    if(head==NULL){
        head = new node(d);
        return;
    }
    node* n = new node(d);
    n->next = head;
    head = n;
}

// -------------------- INPUT/OUTPUT -----------------

// Take input from user
node* take_input(){
    int d;
    node* head = NULL;

    while(cin >> d){
        insertAtHead(head,d);
    }
    return head;
}



//Print linked list
void print(node* head){
    while(head!= NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// -------------------- OPERATOR OVERLOADING -----------------


ostream& operator<<(ostream &os,node* head){
    print(head);
    return os; // cout << head will represent linked list
} 

istream& operator>>(istream& is,node* &head){
    head = take_input();
    return is;
}

// Runner Technique to find mid point of linkedlist
// 2 horses race
// 1st horse -> 2x speed
// 2nd horse -> x speed
node* mid(node* head){
    if(head==NULL or head->next == NULL){
        return head;
    }
    node* fast = head->next;
    node* slow = head;
    while(fast != NULL and fast->next != NULL ){
        fast = fast->next->next;
        slow = slow ->next;
    }
    return slow;
}



int main() {
    node* head ;
    cin >> head ;
    cout << head;


    node* midpt = mid(head);

    cout << midpt->data << endl;

}
