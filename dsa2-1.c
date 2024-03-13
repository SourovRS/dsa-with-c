#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,x,y,td,d,i,j;
    printf("Enter array length: ");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter 1st number x: ");
    scanf("%d",&x);
    printf("Enter 2nd number y: ");
    scanf("%d",&y);
    d=n-1;
    for(i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            for(j=0;j<n;j++)
            {
                if(arr[j]==y)
                {
                    td=abs(i-j);
                    if(td<d)
                      d=td;
                }
            }
        }
    }
    printf("Minimum distance between %d and %d is %d",x,y,d);
}