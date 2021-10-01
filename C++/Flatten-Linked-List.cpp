/*
Flattening a Linked List 
Medium Accuracy: 33.91% Submissions: 67762 Points: 4
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of next pointer.
 
Example 1:
Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every 
node in a single level.
(Note: | represents the bottom pointer.)
 
Example 2:
Input:
5 -> 10 -> 19 -> 28
|          |                
7          22   
|          |                 
8          50 
|                           
30              
Output: 5->7->8->10->19->20->22->30->50
Explanation:
The resultant linked lists has every
node in a single level.
(Note: | represents the bottom pointer.)
*/
#include <iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node *right, *down;
};
 
Node* head ;
 
Node* merge(Node* a, Node* b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    Node* result;
 
    if (a->data < b->data)
    {
        result = a;
        result->down = merge(a->down, b);
    }
    else
    {
        result = b;
        result->down = merge(a, b->down);
    }
    result->right = NULL;
    return result;
}
 
Node* flatten(Node* root)
{
    if (root == NULL || root->right == NULL)
        return root;
    return merge(root, flatten(root->right));
}

Node* push(Node* head_ref, int data)
{
     
    Node* new_node = new Node();
 
    new_node->data = data;
    new_node->right = NULL;
    new_node->down = head_ref;
    head_ref = new_node;
 
    return head_ref;
}
 
void printList()
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->down;
    }
    cout << endl;
}
 
// Driver code
int main()
{
     
    /* Let us create the following linked list
        5 -> 10 -> 19 -> 28
        |    |     |     |
        V    V     V     V
        7    20    22    35
        |          |     |
        V          V     V
        8          50    40
        |                |
        V                V
        30               45
    */
    head = push(head, 30);
    head = push(head, 8);
    head = push(head, 7);
    head = push(head, 5);
 
    head->right = push(head->right, 20);
    head->right = push(head->right, 10);
 
    head->right->right = push(head->right->right, 50);
    head->right->right = push(head->right->right, 22);
    head->right->right = push(head->right->right, 19);
 
    head->right->right->right = push(head->right->right->right, 45);
    head->right->right->right = push(head->right->right->right, 40);
    head->right->right->right = push(head->right->right->right, 35);
    head->right->right->right = push(head->right->right->right, 20);
 
    // Flatten the list
    head = flatten(head);
 
    printList();
    return 0;
}