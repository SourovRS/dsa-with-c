#include <stdio.h>
 
int search(int arr[], int N, int x)
{
    int i;
    for (i = 0; i < N; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
 
int main(void)
{
    int arr[30];
    int count,x;
    printf("How many elements are u going to enter?: ");
   scanf("%d",&count);

   printf("Enter %d elements: ", count);
   for(int i=0;i<count;i++)
      scanf("%d",&arr[i]);
    printf("Enter the element:");
    scanf("%d",&x);

    int N = sizeof(arr) / sizeof(arr[0]);
 
    int result = search(arr, N, x);
    (result == -1)
        ? printf("%d is not present in array",x)
        : printf("%d is present at index %d",x ,result);
    return 0;
}