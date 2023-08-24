// finding duplicate elements in the array
#include <stdio.h>
#include <stdlib.h>

int search(int arr[],int n,int temp);

int main()
{
    int n, i,temp,j,k=0;
    printf("enter the size of the array :");
    scanf("%d", &n);
    int arr[n];
    int arr2[n];
    printf("enter the elements of the array :\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i=0;i<n;i++){
        temp = arr[i];
        for(j=i+1;j<n;j++){
            if(temp == arr[j] && !search(arr2,n,temp)){
                arr2[k] = temp;
                k++;
            }
        }
    }
    printf("the duplicate elements in the array are :\n");
    for(i=0;i<k;i++){
        printf("%d ",arr2[i]);
    }
    printf("\n");
    return 0;
}

int search(int arr[],int n,int temp){
    int i;
    for(i=0;i<n;i++){
        if(arr[i]==temp){
            return 1;
        }
    }
    return 0;
}