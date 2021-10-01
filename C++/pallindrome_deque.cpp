#include<iostream>
using namespace std;

#define MAX 100

int size, Q[MAX], front=-1, rear=-1, x;

void insert_rear(int x)
{
    if(front==-1)
        front=0;
    rear++;
    Q[rear]=x;
}

int delete_from_front()
{
    if(front==-1)
        cout<<"DeQueue is Empty\n";
    if (front==rear)
    {
        int d=Q[front];
        front=rear=-1;
        return d;
    }

    else if (front==size-1)
    {
        int d=Q[front];
        front=0;
        return d;
    }
    else
    {
        int d=Q[front];
        front=front+1;
        return d;
    }
}

int delete_from_rear() {
    if(front==-1)
        cout<<"DeQueue is Empty\n";
    if (front==rear)
    {
        int d=Q[rear];
        front=rear=-1;
        return d;
    }
    else if (rear==0)
    {
        int d=Q[rear];
        rear=size-1;
        return d;

    }
    else
    {
        int d=Q[rear];
        rear=rear-1;
        return d;
    }
}

int main()
{
     int c,a,b,flag=0,cnt=0;
     char ele[MAX];
     cout<<"Enter the string: ";
     gets(ele);
     for(int j=0; ele[j] != '\0'; j++)
     {
            cnt++;
     }
     size=cnt;
     int count=size/2;
     for (int i=0;i<size;i++)
     {
        insert_rear(ele[i]);
     }
     while(count>0)
     {
         a=delete_from_front();
         b=delete_from_rear();
         if(a!=b)
            flag=1;
         count--;
     }
     if(flag==0)
        cout<<"\nString is a Pallindrome\n";
     else
        cout<<"\nString is not a Pallindrome\n";
     return 0;
}
