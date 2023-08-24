// circular single linked list implimentation.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

int main()
{
    node *head = NULL, *new, *temp,*temp2;
    int opp, x, count, k;
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
                head->next = head;
            }
            else
            {
                new = (node *)malloc(sizeof(node));
                new->data = x;
                new->next = head;
                temp = head;
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                temp->next = new;
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
                head->next = head;
            }
            else
            {
                new = (node *)malloc(sizeof(node));
                new->data = x;
                new->next = head;
                temp = head;
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                temp->next = new;
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
            temp->next = new;
            printf("inserted at middle\n");
            break;
        case 4:
            temp = head->next;
            printf("%d ", head->data);
            while (temp != head)
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
                temp2 = head;
                while(temp->next !=head){
                    temp=temp->next;
                }
                temp->next =head->next;
                head = head->next;
                free(temp2);
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
                while (temp->next->next != head)
                {
                    temp = temp->next;
                }
                temp2 = temp->next;
                temp->next = head;
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
            temp2 = temp->next;
            temp->next = temp2->next;
            free(temp2);
            printf("deleted at middle");
            break;
        }

        printf("enter operation :\n1.insertion at begining\n2.insertion at end\n3.insertion at middle\n4.display\n5.exit\n6.delete at begining\n7.delete at end\n8.delete at middle\n");
    }
    return 0;
}
