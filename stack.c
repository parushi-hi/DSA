#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int stack[MAX];
int top = -1;
void push(int item);
int pop();
int peek();
int isEmpty();
int isFull();
void display();
int main()
{
    int choice,item;
    while(1)
    {
        printf("\n1.Push\n2.Pop\n3.Display the top element\n4.Display all stack elements\n5.Quit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the item to be pushed: ");
                scanf("%d",&item);
                push(item);
                break;
            case 2:
                item = pop();
                if(item != -1)
                    printf("Item popped: %d",item);
                break;
            case 3:
                item = peek();
                if(item != -1)
                    printf("Item at the top is %d",item);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong choice");
        }
    }
}
void push(int item)
{
    if (isFull())
    {
        printf("Stack overflow");
        return;
    }
    top = top + 1;
    stack[top] = item;
}
int pop()
{
    int item;
    if (isEmpty())
    {
        printf("Stack Underflow");
        return -1;
    }
    item = stack[top];
    top--;
    return item;

}
int peek()
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
void display()
{
        int i;
        if( isEmpty() )
        {
                printf("\nStack is empty");
                return;
        }
    printf("\nStack elements :\n");
        for(i=top;i>=0;i--)
                printf(" %d\n", stack[i] );
        printf("\n");
}