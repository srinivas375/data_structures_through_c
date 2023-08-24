// reverse a single linked list.
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
        head->next = NULL;
    }
    else
    {
        new = malloc(sizeof(node));
        new->data = data;
        new->next = NULL;
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
    }
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

void reverse()
{
    node *prev = NULL, *next;
    temp = head;
    while (temp != NULL)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
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
    printf("reversing the linked list :\n");
    reverse();
    print();
    return 0;
}