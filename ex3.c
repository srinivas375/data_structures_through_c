// stack implementation using linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *next;
} node;

node *head = NULL, *new;

void push(char x)
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
}

void pop()
{
   
    
        node *temp;
        temp = head;
        head = head->next;
        free(temp);
}

int top()
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

int isvalid(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            push(s[i]);
        }
        else if (s[i] == ')' && top() == '(' || s[i] == '}' && top() == '{' || s[i] == ']' && top() == '[')
        {
            pop();
        }
        else
        {
            return 0;
        }
        i++;
    }
    if (isempty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char name[30];
    scanf("%s", name);
    int val = isvalid(name);

    if (val)
    {
        printf("true \n");
    }
    else
    {
        printf("false \n");
    }
    return 0;
}
