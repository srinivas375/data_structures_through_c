// circular queue implementation.

#include <stdio.h>
#include <stdlib.h>

#define max 5

int queue[max], front = -1, rear = -1;

void enqueue(int x)
{
    if (front == -1 && rear == -1)
    {
        queue[++rear] = x;
        ++front;
        printf("value enqueued in the queue\n");
    }
    else if ((rear + 1) % max == front)
    {
        printf("overflow\n");
    }
    else
    {
        rear = (rear + 1) % max;
        queue[rear] = x;
        printf("value enqueued in the queue\n");
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("underflow\n");
    }
    else if (front == rear)
    {
        printf("the value is dequeued from the queue.\n");
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % max;
        printf("the value is dequeued from the queue\n");
    }
}

int isempty()
{
    if (front == -1 && rear == -1)
    {
        return 1;
    }
    return 0;
}

int isfull()
{
    if ((rear + 1) % max == front)
    {
        return 1;
    }
    return 0;
}

int print()
{
    int i=front;
    while (i != rear)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % max;
    }
    printf(" %d\n",queue[rear]);
}

int frontee()
{
    return queue[front];
}

int rearee()
{
    return queue[rear];
}

int main()
{
    while (1)
    {
        printf("1.enqueue()\n2.dequeue()\n3.front()\n4.rear()\n5.isnull()\n6.print()\n7.isfull()\n8.exit\nenter an operation :");
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
            printf("front of queue is :%d\n", frontee());
            break;
        case 4:

            printf("rear of queue is :%d\n", rearee());

            break;
        case 5:
            if (isempty())
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
            if (isfull())
                printf("the queue is full\n");
            else
                printf("the queue is not full\n");
            break;
        case 8:
            exit(0);
        }
    }
    return 0;
}
