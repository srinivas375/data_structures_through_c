// sample code of basic array;
#include <stdio.h>
int main()
{
    int array[10];
    printf("enter the array elements :\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("the array elements are :\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d \n", array[i]);
    }
    return 0;
}