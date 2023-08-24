// sorting an character array.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n, i, j;
    char temp[100];
    printf("enter the number of names to be entered : ");
    scanf("%d", &n);
    char arr[n][100];
    printf("enter the names :\n");
    for (int i = 0; i < 3; i++)
    {
        scanf("%99s", arr[i]);
    }
    int length = sizeof(arr)/sizeof(arr[0]);
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < length - 1; j++)
        {
            if (strcmp(arr[j], arr[j + 1]) > 0)
            {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        printf("%s  ", arr[i]);
    }
    return 0;
}