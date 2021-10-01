#include<iostream>
#include<string>
using namespace std;

struct stack{
    int size;
    int top;
    char *arr;
};

void display(struct stack * sp){
    for(int i=0;i<=sp->top;i++){
        cout<<sp->arr[i]<<" ";
    }
}

int isFull(struct stack * sp){
    if(sp->top == sp->size-1){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(struct stack * sp){
    if(sp->top == -1){
        return 1;
    }else{
        return 0;
    }
}

void push(struct stack * sp, char val){
    if(isFull(sp)){
        cout<<"Stack Overflow cant push "<< val <<endl;
    }else{
        sp->top++;
        sp->arr[sp->top] = val;
    }
}


char pop(struct stack * sp){
    if(isEmpty(sp)){
        cout<<"Stack Underflow cant pop!!"<<endl;
        return 0;
    }else{
        char val = sp->arr[sp->top];
        sp->top--;
        return val;
    }
}


char stackTop(struct stack * sp){
    if(isEmpty(sp)){
        cout<<"Stack if empty!!"<<endl;
        return 0;
    }else{
        return sp->arr[sp->top];
    }
}

int isOperator(char ch){
    if(ch=='^' || ch=='*' || ch=='/' || ch=='%' || ch=='+' || ch=='-'){
        return 1;
    }else{
        return 0;
    }
}

int presidence(char ch){
    if(ch=='^'){
        return 3;
    }else if(ch=='*' || ch=='/' || ch=='%'){
        return 2;
    }else if(ch=='+' || ch=='-'){
        return 1;
    }else{
        return 0;
    }
}

string infixToPostfix(string infix){

    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    push(sp,'(');

    string inf = infix+")";

    string postfix = "";

    for(int i=0;i<inf.length();i++){
        if(inf[i]==' '){
            continue;
        }else if(inf[i]=='('){
            push(sp,inf[i]);
        }else if(inf[i]==')'){
             while(stackTop(sp)!='('){
                postfix+=pop(sp);
            }
            pop(sp);
        }else if(!(isOperator(inf[i]))){
            postfix+=inf[i];
        }else{
            if(presidence(inf[i])>presidence(stackTop(sp))){
                push(sp,inf[i]);
            }else{
                while(presidence(stackTop(sp))>presidence(inf[i]) || presidence(stackTop(sp))==presidence(inf[i])){
                    postfix+=pop(sp);
                }
                push(sp,inf[i]);
            }
        }

        cout<<"stack :"<<endl;
        display(sp);
        cout<<endl;
        cout<<"postfix :"<<endl;
        cout<<postfix;
        cout<<endl;
        cout<<endl;
    }

    return postfix;

}


int main(){   
   
    cout<<"Enter your infix expression: "<<endl;
    string infix;
    cin>>infix;

    cout<<infixToPostfix(infix)<<endl;

    return 0;
}
