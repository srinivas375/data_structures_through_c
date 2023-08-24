// middle element of a linked list.
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

void middle(){
    node *slow,*fast;
    slow=fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    printf("the middle value is : %d",slow->data);
    printf("\n");
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
    middle();
    return 0;
}