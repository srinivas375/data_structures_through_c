// infix to postfix conversion and its evalution using stack.
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *next;

} node;

node *head = NULL, *new, *temp;

int stack2[50], top = -1;

void push2(int val)
{
    stack2[++top] = val;
}

int pop2()
{
    return stack2[--top];
}

void push(char val)
{
    if (head == NULL)
    {
        head = (node *)malloc(sizeof(node));
        head->data = val;
        head->next = NULL;
    }
    else
    {
        new = (node *)malloc(sizeof(node));
        new->data = val;
        new->next = head;
        head = new;
    }
}

char pop()
{
    temp = head;
    head = head->next;
    char value = temp->data;
    free(temp);
    return value;
}

int isempty()
{
    if (head == NULL)
        return 1;
    return 0;
}

int pres(char val)
{
    if (val == '^')
        return 3;
    else if (val == '*' || val == '/')
        return 2;
    else if (val == '+' || val == '-')
        return 1;
    return 0;
}

int opp(int a, int b, char c)
{
    if (c == '/')
        return a / b;
    else if (c == '*')
        return a * b;
    else if (c == '-')
        return a - b;
    else if (c == '+')
        return a + b;
}

int main()
{
    char arr1[20], arr2[20];
    int i = 0, j = 0;
    printf("enter the infix expression :");
    scanf("%s", arr1);
    while (arr1[i] != '\0')
    {
        if (arr1[i] >= 'a' && arr1[i] <= 'z')
        {
            arr2[j] = arr1[i];
            j++;
        }
        else if (isempty() || pres(arr1[i]) > pres(head->data) || arr1[i] == '(')
        {
            push(arr1[i]);
        }
        else if (arr1[i] == ')')
        {
            char x = pop();
            while (x != '(' && !isempty())
            {
                arr2[j] = x;
                j++;
                x = pop();
            }
        }
        else if (pres(arr1[i]) <= pres(head->data))
        {
            while (!isempty() && head->data != '(')
            {
                if (pres(arr1[i] <= pres(head->data)))
                {
                    arr2[j] = pop();
                    j++;
                }
                else
                    break;
            }
            push(arr1[i]);
        }
        i++;
    }
    while(!isempty()){
        arr2[j]=pop();
        j++;
    }
    printf("the postfix expression is : %s\n",arr2);
    return 0;
}