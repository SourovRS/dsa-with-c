 #include <stdio.h>

/*A sparse martix is matrix which  has more zero elements than nonzero elements */
void main ()
{
	static int arr1[10][10];
	int i,j,r,c;
	int z=0;
     printf("\n\nDetermine whether a matrix is a sparse matrix :\n");

     printf("enter the number of rows of the matrix : ");
     scanf("%d", &r); 
     printf("enter the number of columns of the matrix : ");
     scanf("%d", &c); 
	 printf("enter elements in the first matrix :\n");
       for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
	           printf("element - [%d],[%d] : ",i,j);
	           scanf("%d",&arr1[i][j]);
			if (arr1[i][j]==0)
			{
				++z;
			}
            }
        }  
	
if (z>((r*c)/2))
{
    printf("The matrix is sparse matrix.\n");
}
else{
printf("The matrix is not a sparse matrix.\n");
}
    printf("there are %d number of zero in this matrix.\n\n",z);}
