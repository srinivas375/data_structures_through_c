// reverse a doubly linked list.
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} node;

node *head = NULL, *new, *temp;

void insert(int data)
{
    if (head == NULL)
    {
        head = malloc(sizeof(node));
        head->data = data;
        head->left = NULL;
        head->right = NULL;
    }
    else
    {
        new = malloc(sizeof(node));
        new->data = data;
        new->right = NULL;
        temp = head;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        temp->right = new;
        new->left = temp;
    }
}

void print()
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->right;
    }
    printf("\n");
}

void reverse()
{
    node *temp2, *next;
    temp = head;
    while (temp->right != NULL)
    {
        next = temp->right;
        temp2 = temp->left;
        temp->left = temp->right;
        temp->right = temp2;
        temp = next;
    }
    temp2 = temp->left;
    temp->left = temp->right;
    temp->right = temp2;
    head = temp;
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
    printf("the reverse of the doubly linked list is :\n");
    reverse();
    print();
    return 0;
}