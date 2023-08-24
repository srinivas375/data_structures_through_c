// insertion sort algorithm
#include <stdio.h>
#include <stdlib.h>

void insertion(int arr[], int n);

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
    insertion(arr, n);
    printf("the sorted array is :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

void insertion(int arr[], int n) // ascending order.
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while(arr[j]>temp && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}