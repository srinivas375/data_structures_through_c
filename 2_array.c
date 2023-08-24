// code to find out avegage of the subject marks
#include <stdio.h>
int main()
{
    int n, i, sum = 0;
    float avg;
    printf("enter the number of subjects : ");
    scanf("%d", &n);
    int marks[n];
    for (i = 0; i < n; i++)
    {
        printf("enter marks of subject %d :", i + 1);
        scanf("%d", &marks[i]);
        sum += marks[i];
    }
    printf("average of all the marks is : ");
    avg = sum / (float)n;
    printf("%.3f\n", avg);
    return 0;
}
