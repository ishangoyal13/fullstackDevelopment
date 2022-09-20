#include <iostream>
#include <string.h>
#include <cctype>
#include <stdio.h>
using namespace std;

class post_eval
{
    char infix[100];
    char stk[100];
    int top = 0;
    char str[100];
    int k = 0;

public:
    void create()
    {
        int l = 0;
        cout<<"Infix Expression->";
        cin >> infix;
        l = strlen(infix);
        infix[l] = ')';
        infix[l + 1] = '\0';
        stk[0] = '(';
    }

    void process()
    {
        int i;
        i = 0;
        while (infix[i] != '\0')
        {
            if (infix[i] == '(')
            {
               push_stack(infix[i]);
            }
            else if (isdigit(infix[i]))
            {
                add_postfix(infix[i]);
            }

            else if (isalpha(infix[i]))
            {
                add_postfix(infix[i]);
            }
            else if (infix[i] == ')')
            {
                while (stk[top] != '(')
                {
                    add_postfix(stk[top]);
                    pop();
                }
                pop();
            }

            else if (infix[i] == '*' || infix[i] == '/' || infix[i] == '+' || infix[i] == '-' || infix[i] == '^')
            {
                if (stk[top] == '('){
                    push_stack(infix[i]);
                }
                else if (prece(stk[top]) >= prece(infix[i])){
                    while (prece(stk[top]) >= prece(infix[i])){

                        add_postfix(stk[top]);
                        pop();
                    }
                    push_stack(infix[i]);
                }
                else if (prece(stk[top]) < prece(infix[i])){
                    push_stack(infix[i]);
                }
            }
          i++;
        }
    }
    void push_stack(char x)
    {
        top++;
        stk[top] = x;
        
    }
    void pop()
    {
        //  cout<<"\nElement popped "<<stk[top];
        top--;
    }
    int prece(char op)
    {
        if (op == '+' || op == '-')
        {
            return 1;
        }
        else if (op == '*' || op == '/')
        {
            return 2;
        }
        else if (op == '^')
        {
            return 3;
        }
        else
        {
            return 0;
        }
    }
    void add_postfix(char y)
    {

        str[k] = y;
        //cout<<"\nelement came in postfix string"<<str[k];
        k++;
        str[k] = '\0';
    }
    void show()
    {
        cout << "postfix expression-> " << str;
    }
};
main()
{
    post_eval ob;
    ob.create();
    ob.process();
    ob.show();
}
