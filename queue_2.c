// queue implementation using array.

#include <stdio.h>
#include <stdlib.h>
#define max 5

int queue[max], front = -1, rear = -1;

int isfull();
int isnull();

void enqueue(int x)
{
    if (!isfull())
    {
        queue[++rear] = x;
        if (rear == 0)
            ++front;
        printf("value is enqueued into the queue\n");
    }
    else
    {
        printf("overflow\n");
    }
}

void dequeue()
{
    if (!isnull() && front <= rear)
    {
        ++front;
        printf("dequeued from queue\n");
    }
    else
    {
        printf("underflow\n");
    }
}

int frontee()
{
    return queue[front];
}

int rearee()
{
    return queue[rear];
}

void print()
{
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int isfull()
{
    if (rear == max - 1)
    {
        return 1;
    }
    return 0;
}

int isnull()
{
    if (front == -1)
        return 1;
    return 0;
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