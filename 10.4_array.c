// merge sort technique.
#include <stdio.h>
#include <stdlib.h>

void mergesort(int[], int, int);
void merge(int[], int, int, int);

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

    mergesort(arr, 0, n - 1);

    printf("the sorted array is :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

void mergesort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        mergesort(arr, lb, mid);
        mergesort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

void merge(int arr[], int lb, int mid, int ub)
{
    int i = lb, j = mid + 1, k = lb;
    int b[ub];
    while (i <= mid && j <= ub)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= ub)
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            b[k] = arr[i];
            i++;
            k++;
        }
    }
    for (i = 0; i <= ub; i++)
    {
        arr[i] = b[i];
    }
}
