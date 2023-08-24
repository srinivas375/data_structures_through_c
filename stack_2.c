// stack implementation using linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL, *new;

void push(int x)
{
    if (head == NULL)
    {
        head = (node *)malloc(sizeof(node));
        head->data = x;
        head->next = NULL;
    }
    else
    {
        new = (node *)malloc(sizeof(node));
        new->data = x;
        new->next = head;
        head = new;
    }
    printf("value pushed into the stack.\n");
}

void pop()
{
    if (head == NULL)
    {
        printf("underflow\n");
    }
    else
    {
        node *temp;
        temp = head;
        head = head->next;
        free(temp);
        printf("value poped form the stack.\n");
    }
}

int topof()
{
    if (head == NULL)
    {
        return -1;
    }
    else
    {
        return head->data;
    }
}

int isempty()
{
    if (head == NULL)
        return 1;
    else
        return 0;
}

int size()
{
    node *temp;
    int count = 0;
    temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

int print()
{
    node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

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
            if (topof() == -1)
            {
                printf("stack is empty.\n");
            }
            else
            {
                printf("top of stack is :%d\n", topof());
            }
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