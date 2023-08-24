// array rotation by k ,using another array
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, k, j;
    printf("enter the size of the array :");
    scanf("%d", &n);
    int arr[n];
    int new_arr[n];
    printf("enter the array elements :\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("enter the value of k to rotate :");
    scanf("%d", &k);
    for (i = 0; i < n; i++)
    {
        j = (i + k) % n;
        new_arr[j] = arr[i];
    }
    printf("the rotated array is :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", new_arr[i]);
    }
    printf("\n");
    return 0;
}