// printing a name in the given format.
// i/p:-india.
// o/p:-ianid.
#include <stdio.h>
int main()
{
    char name[50];
    printf("enter your name : ");
    scanf("%s", name);
    int i, j, count = 0;
    for (i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    for (i = 0; i < count / 2; i++)
    {
        int k = count - i - 1;
        printf("%c%c", name[i], name[k]);
    }
    return 0;
}