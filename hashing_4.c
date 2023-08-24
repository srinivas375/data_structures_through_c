// double hashing (open addressing implementation).
#include <stdio.h>
#include <stdlib.h>
#define max 6
int hash[max];

void insert(int val)
{
    int i;
    int key = val % max;
    int index1 = max - (key % max);
    for (i = 0; i < max; i++)
    {
        int index = (key + i * index1) % max;
        if (hash[index] == -1)
        {
            hash[index] = val;
            printf("value inserted.....\n");
            break;
        }
    }
    if (i == max)
    {
        printf("the hash table is full.....\n");
    }
}

int search(int val)
{
    int i;
    int key = val % max;
    int index1 = max - (key % max);
    for (i = 0; i < max; i++)
    {
        int index = (key + i * index1) % max;
        if (hash[index] == val)
        {
            return 1;
        }
    }
    return 0;
}

void print()
{
    int i;
    for (i = 0; i < max; i++)
    {
        if (hash[i] != -1)
        {
            printf("%d ", hash[i]);
        }
    }
    printf("\n");
}

int main()
{
    int opp;
    for (int i = 0; i < max; i++)
    {
        hash[i] = -1;
    }
    while (1)
    {
        printf("1.insert\n2.search\n3.print\n4.exit\n");
        printf("enter one operation : ");
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