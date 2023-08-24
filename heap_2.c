// heapsort of max-heap gives a ascending ordered array.
// heapsort of min-heap gives a descending ordered array.
// maxheapify() is used to make the subtree to be max heap.
// by applying maxheapify() to all the elements,we can construct the max heap of overall array.
// heapsort() makes the array to be in the sorted order.
// in this example i am building a max-heap and sorting it to ascending order.
#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int i, int heapsize)
{
    int left = i * 2;
    int right = i * 2 + 1;
    int largest;
    if (left <= heapsize && arr[left] > arr[i])
    {
        largest = left;
    }
    else
    {
        largest = i;
    }
    if (right <= heapsize && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, largest, heapsize);
    }
}

void build_max_heap(int arr[], int n)
{
    int heapsize = n;
    int i = heapsize / 2;
    while (i >= 1)
    {
        heapify(arr, i, heapsize);
        i--;
    }
}

void heapsort(int arr[],int n){
    int i=n;
    while(i>1){
        int temp=arr[i];
        arr[i]=arr[1];
        arr[1]=temp;
        i=i-1;
        heapify(arr,1,i);
    }
}

int main()
{
    int n, i;
    printf("enter the array size :");
    scanf("%d", &n);
    int arr[n + 1];
    printf("enter the array elements :\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    build_max_heap(arr, n);

    printf("the array that converted into the max-heap is :\n");
    for (i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    heapsort(arr,n);

    printf("the sorted array is :\n");
    for (i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
