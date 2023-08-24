// stack implementation using array.
#include <stdio.h>
#include<stdlib.h>
#define max 5
int stack[max], top = -1;

void push(int);
void pop();
int topof();
int isempty();
int size();
void print();

int main()
{
    while (1)
    {
        printf("1.push()\n2.pop()\n3.top()\n4.isempty()\n5.size()\n6.print()\n7.exit()\nenter an operation :");
        int opp, num;
        scanf("%d", &opp);
        switch (opp)
        {
        case 1:
            printf("enter value :");
            scanf("%d", &num);
            push(num);
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("top of stack is :%d\n", topof());
            break;
        case 4:
            if (isempty())
            {
                printf("the stack is empty\n");
            }
            else
            {
                printf("the stack is not empty\n");
            }
            break;
        case 5:
            printf("the current size of the stack is :%d\n", size());
            break;
        case 6:
            print();
            break;
        case 7:
            exit(0);
        }
    }
    return 0;
}
void push(int num)
{
    if (top == max - 1)
    {
        print("overflow\n");
        return;
    }
    stack[++top] = num;
    printf("value pushed into the stack\n");
}

void pop()
{
    if (top == -1)
    {
        printf("underflow\n");
        return;
    }
    --top;
    printf("value poped from stack\n");
}

int topof()
{
    return stack[top];
}

int isempty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

int size()
{
    return top + 1;
}
void print()
{
    int i = 0;
    for (i; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
    return;
}
