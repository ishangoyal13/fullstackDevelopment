/*Check if Linked List is Palindrome 
Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Example 1:

Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.
Example 2:

Input:
N = 4
value[] = {1,2,3,4}
Output: 0
Explanation: The given linked list
is 1 2 3 4 , which is not a palindrome
and Hence, the output is 0.*/
#include<iostream>
#include<stack>
using namespace std;
 
class Node {
public:
    int data;
    Node* next;
};
 
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int countSum(Node* slow){
    int res=1;
    Node* temp = slow;
    while(temp->next!=slow){
        res++;
        temp = temp->next;
    }
    return res;
}
 
bool isPalindrome(Node *head)
    {
        Node* curr= head;
        int count=0, pos;
        stack<int> v;
        while(curr!=NULL){
            count++;
            v.push(curr->data);
            curr = curr->next;
        }
        curr = head;
        while(head!=NULL){
            // cout<<"head: "<<head->data<<" top: "<<v.top()<<"\n";
            if(head->data != v.top())
                return 0;
            head = head->next;
            v.pop();
        }
        
        return 1;
    }
void printList(struct Node* node)
{
    // Print the list after loop removal
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}
 
int main()
{
    Node* head = NULL;
 
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    // printList(head);
    if(isPalindrome(head)){
        cout<<"It is a pallindrome";
    }else{
        cout<<"It is not a pallindrome";
    }
    
}