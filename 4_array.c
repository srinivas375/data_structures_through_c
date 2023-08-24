// linear search of an array
#include <stdio.h>
#include<stdlib.h>
int main()
{
    int n, i, num;
    printf("enter the size of the array :");
    scanf("%d", &n);
    int arr[n];
    printf("enter the array elements :\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("enter the search element : ");
    scanf("%d", &num);
    for (i = 0; i < n; i++)
    {
        if (num == arr[i])
        {
            printf("element found");
            exit(0);
        }
    }
    printf("element not found");
    return 0;
}