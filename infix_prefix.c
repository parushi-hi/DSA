#include <stdio.h>
#define MAX 20
char stack[MAX];
int top = -1;
int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(top==MAX-1)
        return 1;
    else    
        return 0;
}
char pop()
{
    char ch;
    if(isEmpty())
    {
        printf("\nStack Underflow\n");
        return -1;
    }
    else
    {
        ch = stack[top];
        top--;
        return ch;
    }
}
char peek()
{
    if(isEmpty())
    {
        printf("\nStack Underflow\n");
        return -1;
    }
    else
        return stack[top];
}
void push(char ch)
{
    if(isFull())
        return;
    stack[++top]=ch;
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
void reverse(char *exp)
{
    int len = 0,i;
    while(exp[len]!='\0')
        len++;
    for(i=0;i<len/2;i++)
    {
        char temp = exp[i];
        exp[i]=exp[len-i-1];
        exp[len-i-1]=temp;
    }
}
void infix_postfix(char *exp)
{
    int i,j=0;
    char prefix[MAX];
    for(i=0;exp[i]!='\0';i++)
    {
        if(IfOperand(exp[i]))
        {
            prefix[j++]=exp[i];
        }
        else if(exp[i]=='(')
        {
            push(exp[i]);
        }
        else if(exp[i]==')')
        {
            while(top!=-1 && peek()!='(')
            {
                prefix[j++]=pop();
            }
            pop();
        }
        else
            while(top!=-1 && precedence(exp[i])<=precedence(peek()))
            {
                prefix[j++]=pop();
            }
            push(exp[i]);
    }
    while(!isEmpty())
        prefix[j++]=pop();
    prefix[j]='\0';
}
int main()
{
    char exp[MAX];
    printf("Enter an infix expression: ");
    scanf("%s",&exp);
    reverse(exp);
    infix_postfix(exp);
    reverse(exp);
    printf("Prefix expression: %s",exp);
    return 0;
}