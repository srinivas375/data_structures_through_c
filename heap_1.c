// heap implementaion.
// heap is basically two types.1)max heap 2)min heap.
// any heap should maintain its property and also the complete binary tree property.
// so any insertion should be done at leaf and then swaped to mainaint the heap property.
// deletion should be only done from the top by moving the last element to the root and then maintaining the property of the heap.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int arr[], int i)
{
    printf("enter a value : ");
    int val;
    scanf("%d", &val);
    i += 1;
    arr[i] = val;
    while (i > 1)
    {
        int parent = i / 2;
        if (arr[parent] < arr[i])
        {
            swap(&arr[parent], &arr[i]);
            i = parent;
        }
    }
}

// void delete(int arr[],int n){
//     int val =arr[1];
//     printf("the delete value is : %d \n",val);
//     arr[1]=arr[n];
//     n-=1;
//     int i=1;
//     while (i<n){
//         int left=i*2;
//         int right=i*2+1;
//         if(arr[left]>arr[right]){
//             if(arr[i])
//         }
//     }
// }


int main()
{
    printf("enter how many elements to be inserted in the heap : ");
    int n, i = 0;
    scanf("%d", &n);
    int arr[n + 1];
    while (i < n)
    {
        insert(arr, i);
        i++;
    }
    printf("the heap is :\n");
    for (i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // printf("want to delete an element : ");
    // int yes;
    // scanf("%d", &yes);
    // if (yes == 1)
    //     delete (arr,n);

    // printf("the heap is :\n");
    // for (i = 1; i <= n; i++)
    // {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");

    return 0;
}