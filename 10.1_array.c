// bubble sort algorithm
#include <stdio.h>
#include <stdlib.h>

void bubble(int arr[], int n);

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
    bubble(arr, n);
    printf("the sorted array is :\n");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

void bubble(int arr[], int n)//ascending order.
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}