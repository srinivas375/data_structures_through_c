// closed chaining(hashing) implementation.

#include <stdio.h>
#include <stdlib.h>

#define max 6

typedef struct node
{
    int data;
    struct node *next;
} node;

node *hash[max];

void makenull()
{
    int i;
    for (i = 0; i < max; i++)
    {
        hash[i] = NULL;
    }
}

void insert(int val)
{
    int key = val % max;
    if (hash[key] == NULL)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->data = val;
        temp->next = NULL;
        hash[key]=temp;
        printf("inserted....\n");
    }
    else
    {
        node *temp = hash[key];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        node *new = (node *)malloc(sizeof(node));
        new->data = val;
        new->next = NULL;
        temp->next = new;
        printf("inserted....\n");
    }
}

int search(int val)
{
    int key = val % max;
    node *temp = hash[key];
    while (temp)
    {
        if (temp->data == val)
            return 1;
        else
        {
            temp = temp->next;
        }
    }
    return 0;
}

void print(){
    for(int i=0;i<max;i++){
        printf("hash[%d]-->",i);
        node *temp=hash[i];
        while(temp){
            printf("%d--",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main(){
    makenull();
    while (1)
    {
        printf("1.insert\n2.search\n3.print\n4.exit\n");
        printf("enter one operation : ");
        int opp;
        scanf("%d", &opp);
        switch (opp)
        {
        case 1:
            int x;
            printf("enter number :");
            scanf("%d", &x);
            insert(x);
            break;
        case 2:
            printf("enter number to search :");
            scanf("%d", &x);
            if (search(x))
            {
                printf("search found....\n");
            }
            else
            {
                printf("search not found.....\n");
            }
            break;
        case 3:
            print();
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}