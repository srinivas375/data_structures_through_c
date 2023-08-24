// quick sort implementation
#include <stdio.h>
#include <stdlib.h>

void quick_sort(int[], int, int);
int partition(int[], int, int);

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

    quick_sort(arr, 0, n - 1);

    printf("the sorted array is :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

void quick_sort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int position = partition(arr, lb, ub);
        quick_sort(arr, lb, position - 1);
        quick_sort(arr, position + 1, ub);
    }
}

int partition(int arr[], int lb, int ub)
{
    int pivot = arr[lb], start = lb, end = ub, temp;
    while (start < end)
    {
        while (arr[start] <= pivot)
            start++;
        while (arr[end] > pivot)
            end--;
        if (start < end)
        {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    temp = arr[end];
    arr[end] = pivot;
    arr[lb] = temp;
    return end;
}
