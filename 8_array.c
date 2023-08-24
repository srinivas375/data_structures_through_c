// reversal of an array,using temp variables.
#include <stdio.h>
#include <stdlib.h>

void reverse(int arr[], int n);

int main()
{
    int n, i;
    printf("enter the size of the array :");
    scanf("%d", &n);
    int arr[n];
    printf("enter the array elements :\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    reverse(arr, n);
    printf("the reversed array is :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void reverse(int arr[], int n)
{
    int temp, i, j;
    for (i = 0; i < n / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    return;
}