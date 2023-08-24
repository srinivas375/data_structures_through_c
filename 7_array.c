// array rotation by k ,using a temperory variable
#include <stdio.h>
#include <stdlib.h>

void rotate(int arr[], int n, int k);

int main()
{
    int n, i, k, j;
    printf("enter the size of the array :");
    scanf("%d", &n);
    int arr[n];
    printf("enter the array elements :\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("enter the value of k to rotate :");
    scanf("%d", &k);
    rotate(arr, n, k);
    printf("the rotated array is :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void rotate(int arr[], int n, int k)
{
    int temp, i, j;
    for (i = 0; i < k; i++)
    {
        temp = arr[n - 1];
        for (j = n - 1; j > 0; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }
}