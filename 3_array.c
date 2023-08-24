// maximum and minimum elements in the array
#include <stdio.h>
int main()
{
    int n, i;
    float min = 9999.00, max = -9999.00;
    printf("enter the size of the array :");
    scanf("%d", &n);
    float arr[n];
    printf("enter the array elements :\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("maximum element of the array is : %f\n", max);
    printf("minimu element of the array is : %f\n", min);
    return 0;
}