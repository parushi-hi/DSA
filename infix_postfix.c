#include <stdio.h>
#include <stdlib.h>
#define MAX 20
char stack[MAX];
int top = -1;
int isFull()
{
    if(top == MAX-1)
        return 1;
    else 
        return 0;
}
int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
void push(char ch)
{
    if (isFull())
    {
        printf("Stack overflow");
        return;
    }
    top = top + 1;
    stack[top] = ch;
}
char pop()
{
    char ch;
    if (isEmpty())
    {
        printf("Stack Underflow");
        return -1;
    }
    ch = stack[top];
    top--;
    return ch;
}
char peek()
{
    {
        if( isEmpty() )
        {
                printf("\nStack Underflow\n");
                return -1;
        }
        return stack[top];
    }
}
int IfOperand(char ch)
{
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
    {
        return 1;
    } 
    return 0;
}
int precedence(char ch)
{
    if(ch=='+' || ch=='-')
        return 1;
    else if(ch=='*' || ch=='/')
        return 2;
    else if(ch=='^')
        return 3;
    else
        return -1;
}
void infix_postfix(char* exp)
{
    int i,j=0;
    char postfix[MAX];
    for(i=0;exp[i]!='\0';i++)
    {
        if (IfOperand(exp[i]))   
            postfix[j++] = exp[i];
        else if (exp[i] == '(')   
            push(exp[i]); 
        else if(exp[i]==')')
        {
            while(top!=-1 && peek()!='(')
            {
                postfix[j++]=pop();
            }
            pop();
        }
        else
        {
            while(top!=-1 && precedence(exp[i])<=precedence(peek()))
            {
                postfix[j++]=pop();
            }
            push(exp[i]);
        }
    }
    while (!isEmpty())   
        postfix[j++] = pop();
    postfix[j]='\0';
    printf("Postfix expression: %s\n",postfix);
}
int main()
{
    char exp[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", exp);
    infix_postfix(exp);
    return 0;

}