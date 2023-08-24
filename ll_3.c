// double linked list implementation.
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;

int main()
{
    node *head = NULL, *new, *temp;
    int opp, x, count,k;
    printf("enter operation :\n1.insertion at begining\n2.insertion at end\n3.insertion at middle\n4.display\n5.exit\n6.delete at begining\n7.delete at end\n8.delete at middle\n");
    while (1)
    {
        scanf("%d", &opp);
        switch (opp)
        {
        case 1:
            printf("enter a value :");
            scanf("%d", &x);
            if (head == NULL)
            {
                head = (node *)malloc(sizeof(node));
                head->data = x;
                head->next = NULL;
                head->prev = NULL;
            }
            else
            {
                new = (node *)malloc(sizeof(node));
                new->data = x;
                new->next = head;
                head->prev =new;
                new->prev = NULL;
                head = new;
            }
            printf("value inserted at begining \n");
            break;
        case 2:
            printf("enter a value :");
            scanf("%d", &x);
            if (head == NULL)
            {
                head = (node *)malloc(sizeof(node));
                head->data = x;
                head->next = NULL;
                head->prev=NULL;
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
                new->prev=temp;

            }
            printf("inserted at end\n");
            break;
        case 3:
            count = 2;
            printf("enter a value :");
            scanf("%d", &x);
            printf("enter a node position to insert : ");
            scanf("%d", &k);
            temp = head;
            new = (node *)malloc(sizeof(node));
            new->data = x;
            while (count < k)
            {
                temp = temp->next;
                count++;
            }
            new->next = temp->next;
            temp->next->prev =new;
            temp->next = new;
            new->prev = temp;
            printf("inserted at middle\n");
            break;
        case 4:
            temp = head;
            while (temp != NULL)
            {
                printf("%d ", temp->data);
                temp = temp->next;
            }
            printf("\n");
            break;
        case 5:
            exit(0);
        case 6:
            if (head == NULL)
            {
                printf("list is empty.so cant be deleted .\n");
            }
            else
            {
                temp = head;
                head = head->next;
                head->prev =NULL;
                free(temp);
                printf("deleted at begining.\n");
            }
            break;
        case 7:
            if (head == NULL)
            {
                printf("list is empty.so cant be deleted .\n");
            }
            else
            {
                temp = head;
                while (temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                node *temp2;
                temp2 = temp->next;
                temp->next = NULL;
                free(temp2);
                printf("deleted at end\n");
            }
            break;
        case 8:
            temp = head;
            count = 2;
            printf("enter a node position to insert : ");
            scanf("%d", &k);
            while (count < k)
            {
                temp = temp->next;
                count++;
            }
            node *temp2;
            temp2 = temp->next;
            temp->next = temp2->next;
            temp2->next->prev = temp;
            free(temp2);
            printf("deleted at middle");
            break;
        }

        printf("enter operation :\n1.insertion at begining\n2.insertion at end\n3.insertion at middle\n4.display\n5.exit\n6.delete at begining\n7.delete at end\n8.delete at middle\n");
    }
    return 0;
}