// selection sort algorithm
#include <stdio.h>
#include <stdlib.h>

void selection(int arr[], int n);

int main()
{
    int n, i;
    printf("enter the size of the array :");
    scanf("%d", &n);
    int arr[n];
    printf("enter the elements of the array :\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    selection(arr, n);
    printf("the sorted array is :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

void selection(int arr[], int n) // ascending order.
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min=i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}