// finding a ll is circular or not.
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL, *new, *temp;

void insert(int data)
{
    if (head == NULL)
    {
        head = malloc(sizeof(node));
        head->data = data;
        head->next = head;
    }
    else
    {
        new = malloc(sizeof(node));
        new->data = data;
        new->next = head;
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = new;
    }
}

void print()
{
    temp = head->next;
    printf("%d ",head->data);
    while (temp != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int circular()
{
    node *slow, *fast;
    slow = fast = head;
    while (slow != NULL && fast != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    insert(4);
    insert(5);
    insert(6);
    insert(7);
    insert(8);
    insert(1);
    // insert(2);
    print();
    if (circular())
        printf("the linked list is circular\n");
    else
        printf("not circular\n");
    return 0;
}