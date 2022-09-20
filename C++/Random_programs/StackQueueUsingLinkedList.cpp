// code for implementing stack and queue using linked list

#include<bits/stdc++.h>
using namespace std;

typedef struct node {
    int data;
    struct node* next;
}snode;

snode* push(snode* top, int n) {   // Stack push through single pointer
    snode* p = NULL;
    p = new snode;
    if (p != NULL) {
        p->data = n;
        p->next = top;
        top = p;
    }
    else
        cout << "Memory not Allocated!\n";
    return top;
}

snode* pop(snode* top) {   // Stack pop through single pointer
    snode* p = top;
    cout << "Element Popped is: " << p->data << endl;
    top = top->next;
    free(p);
    return top;
}

void disp(snode* top) {    // Stack display
    cout << "Stack Status: ";
    snode* p = top;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    free(p);
}

void stk() {      // MENU driven stack by single pointer
    cout << "\n\tSTACK USING SINGLE POINTER\n";
    snode* top = NULL;
    int ch, n;
    do {
        cout << "1. Push\n2. Pop\n3. Display\n4. Return to Main menu\nEnter your choice: ";
        cin >> ch;
        if (ch == 1) {
            cout << "Enter value to push: ";
            cin >> n;
            top = push(top, n);
            cout << "Element pushed!\n";
        }
        else if (ch == 2) {
            if (top != NULL)
                top = pop(top);
            else
                cout << "Stack Underflow!\n";
        }
        else if (ch == 3) {
            if (top != NULL)
                disp(top);
            else
                cout << "Stack Underflow!\n";
        }
        else if (ch == 4)
            break;
        else
            cout << "Invalid Choice!\n";
    } while (ch != 4);
}

snode* enqueue(snode* tail, int n) {   // Queue insert by single pointer
    snode* p;
    p = new snode;
    if (p != NULL) {
        p->data = n;
        if (tail == NULL)
            return p;
        tail->next = p;
        tail = p;
    }
    else
        cout << "Memory not Allocated!\n";
    return tail;
}

snode* dequeue(snode* head) {    // Queue delete by single pointer
    snode* p;
    p = head;
    cout << "Element Deleted is: " << head->data << endl;
    head = head->next;
    free(p);
    return head;
}

void display(snode* head, snode* tail) {   // Queue dispaly
    cout << "Queue Status: ";
    snode* p;
    p = head;
    while (p != tail) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << p->data << endl;
    free(p);
}

void que() {    // MENU driven queue by single pointer
    cout << "\n\tQUEUE USING SINGLE POINTER\n";
    snode* head = NULL, * tail = NULL;
    int ch, n;
    do {
        cout << "1. Insert Element\n2. Delete Element\n3. Display\n4. Return to Main menu\nEnter your choice: ";
        cin >> ch;
        if (ch == 1) {
            cout << "Enter value to insert: ";
            cin >> n;
            if (head == NULL) {
                head = enqueue(head, n);
                tail = head;
            }
            else
                tail = enqueue(tail, n);
            cout << "Element Inserted!\n";
        }
        else if (ch == 2) {
            if (head == NULL)
                cout << "Queue Underflow!\n";
            else
                head = dequeue(head);
            if (head == NULL)
                tail = NULL;
        }
        else if (ch == 3) {
            if (head != NULL)
                display(head, tail);
            else
                cout << "Queue Underflow!\n";
        }
        else if (ch == 4)
            break;
        else
            cout << "Invalid choice!\n";
    } while (ch != 4);
}

void push(snode** tp, int n) {   // Stack push through double pointer
    snode* p;
    p = new snode;
    if (p != NULL) {
        p->data = n;
        p->next = *tp;
        *tp = p;
    }
    else
        cout << "Memory not Allocated!\n";
}

void pop(snode** tp) {   // Stack pop through double pointer
    snode* p;
    p = *tp;
    cout << "Element Popped is: " << p->data << endl;
    (*tp) = (*tp)->next;
    free(p);
}

void stkdob() {
    cout << "\n\tSTACK USING DOUBLE POINTER\n";
    snode* top = NULL;
    int ch, n;
    do {
        cout << "1. Push\n2. Pop\n3. Display\n4. Return to Main menu\nEnter your choice: ";
        cin >> ch;
        if (ch == 1) {
            cout << "Enter value to push: ";
            cin >> n;
            push(&top, n);
            cout << "Element pushed!\n";
        }
        else if (ch == 2) {
            if (top != NULL)
                pop(&top);
            else
                cout << "Stack Underflow!\n";
        }
        else if (ch == 3) {
            if (top != NULL)
                disp(top);
            else
                cout << "Stack Underflow!\n";
        }
        else if (ch == 4)
            break;
        else
            cout << "Invalid Choice!\n";
    } while (ch != 4);
}

void enqueue(snode** tl, int n) {   // Queue insert by double pointer
    snode* p;
    p = new snode;
    if (p != NULL) {
        p->data = n;
        if (*tl == NULL) {
            *tl = p;
            return;
        }
        (*tl)->next = p;
        *tl = p;
    }
    else
        cout << "Memory not Allocated!\n";
}

void dequeue(snode** hd) {    // Queue delete by double pointer
    snode* p;
    p = *hd;
    cout << "Element Deleted is: " << (*hd)->data << endl;
    (*hd) = (*hd)->next;
    free(p);
}

void quedob() {
    cout << "\n\tQUEUE USING DOUBLE POINTER\n";
    snode* head = NULL, * tail = NULL;
    int ch, n;
    do {
        cout << "1. Insert Element\n2. Delete Element\n3. Display\n4. Return to Main menu\nEnter your choice: ";
        cin >> ch;
        if (ch == 1) {
            cout << "Enter value to insert: ";
            cin >> n;
            if (head == NULL) {
                enqueue(&head, n);
                tail = head;
            }
            else
                enqueue(&tail, n);
            cout << "Element Inserted!\n";
        }
        else if (ch == 2) {
            if (head == NULL)
                cout << "Queue Underflow!\n";
            else
                dequeue(&head);
            if (head == NULL)
                tail = NULL;
        }
        else if (ch == 3) {
            if (head != NULL)
                display(head, tail);
            else
                cout << "Queue Underflow!\n";
        }
        else if (ch == 4)
            break;
        else
            cout << "Invalid choice!\n";
    } while (ch != 4);
}

int main() {   // Main function
    int ch;
    do {
        cout << "\n\tMAIN MENU\n1. Stack using Singly Linked List\n2. Queue using Singly Linked List\n3. Stack using Doubly Linked List\n4. Queue using Doubly Linked List\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        if (ch == 1)
            stk();
        else if (ch == 2)
            que();
        else if (ch == 3)
            stkdob();
        else if (ch == 4)
            quedob();
        else if (ch == 5)
            break;
        else
            cout << "Invalid Choice!\n";
    } while (ch != 5);
    return 0;
}
