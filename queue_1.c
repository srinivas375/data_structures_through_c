// queue implementaion using linked list.
#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL, *new, *temp;

void enqueue(int x)
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
        new->next = NULL;
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
    }
    printf("enqueued a value in queue\n");
}

void dequeue()
{
    if (head == NULL)
    {
        printf("underflow\n");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int front()
{
    return head->data;
}

int rear()
{
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp->data;
}

int isnull()
{
    if (head == NULL)
    {
        return 1;
    }
    else
        return 0;
}

void print()
{
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
        printf("1.enqueue()\n2.dequeue()\n3.front()\n4.rear()\n5.isnull()\n6.print()\n7.exit()\nenter an operation :");
        int opp, num;
        scanf("%d", &opp);
        switch (opp)
        {
        case 1:
            printf("enter value :");
            scanf("%d", &num);
            enqueue(num);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printf("front of queue is :%d\n", front());
            break;
        case 4:

            printf("rear of queue is :%d\n", rear());

            break;
        case 5:
            if (isnull())
            {
                printf("the queue is empty\n");
            }
            else
            {
                printf("the queue is no empty\n");
            }
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