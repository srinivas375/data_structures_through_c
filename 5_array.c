// implementing binary search.
#include <stdio.h>
#include <stdlib.h>

int bin_search(int a[], int n, int num);

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
    printf("enter the search element :");
    scanf("%d", &num);
    int search = bin_search(arr, n, num);
    if (search == 1)
    {
        printf("elemet found\n");
    }
    else
    {
        printf("element not found\n");
    }
    return 0;
}

int bin_search(int a[], int n, int num)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] < num)
        {
            left = mid + 1;
        }
        else if (a[mid] > num)
        {
            right = mid - 1;
        }

        else if (a[mid] == num)
        {
            return 1;
        }
    }
    return 0;
}
