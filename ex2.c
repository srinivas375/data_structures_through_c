// print a name in pyramid form

#include <stdio.h>
int main()
{
    char name[50];
    printf("enter your name :");
    scanf("%s", name);
    int i, count = 0, j;
    for (i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    for (i = count-1; i >= 0; i--)
    {
        int k = i;
        int num = 0;
        for (j = 0; j < 2 * count; j++)
        {
            if (j != k)
            {
                printf(" ");
            }
            else if(j==k)
            {
                printf("%c", name[num++]);
                k = k + 2;
            }
        }
        printf("\n");
    }
    return 0;
}