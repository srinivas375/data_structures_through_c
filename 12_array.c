// counting sort
#include <stdio.h>
#include <stdlib.h>

int max(int[], int);
int countsort(int[], int, int);

int main()
{
    int i, k, n;
    printf("enter the size of the array :");
    scanf("%d", &n);
    int arr[n];
    printf("enter the array elements :\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    k = max(arr, n);
    countsort(arr, n, k);
    printf("\n");
    return 0;
}

int max(int arr[], int n)
{
    int max = -99999, i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
int countsort(int arr[], int n, int k)
{
    int count[k + 1], i;
    // initilazing the count array to 0 ;
    for (i = 0; i < k + 1; i++)
    {
        count[i] = 0;
    }
    // finding the frequency of each key value and storing in the count array.
    for (i = 0; i < n; i++)
    {
        ++count[arr[i]];
    }
    // updating the count array (cummulative sum)
    for (i = 0; i < k; i++)
    {
        count[i + 1] += count[i];
    }
    int b[n];
    // sorting the values in the new array based on updated count array;
    for (i = n - 1; i >= 0; i--)
    {
        b[--count[arr[i]]] = arr[i];
    }
    printf("the elements of the array are :\n");
    for (i = 0; i < n; i++)
    {
        arr[i] = b[i];
        printf("%d ", arr[i]);
    }
}