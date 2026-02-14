/*Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

Input:
- First line: integer n representing number of rows and columns
- Next n lines: n integers each representing the matrix elements

Output:
- Print "Identity Matrix" if the matrix satisfies the condition
- Otherwise, print "Not an Identity Matrix"

Example:
Input:
3
1 0 0
0 1 0
0 0 1

Output:
Identity Matrix*/
#include<stdio.h> 
int main()
{
    int order,i,j; 
    scanf("%d",&order);

    int matrix[order][order];

    for(i=0 ; i<order ; i++)
    {
        for(j=0 ; j<order ; j++)
        scanf("%d",&matrix[i][j]);
    }

    for(i=0 ; i<order ; i++)
    {
        for(j=0 ; j<order ; j++)
        {
        if((i<j || i>j)&&(matrix[i][j]==0))
        continue ; 
        else if((i==j)&&(matrix[i][j]==1))
        continue ; 
        else 
        {
        printf("Not an identity matrix ."); 
        return 0 ; 
        }
        }
    }
printf("Identity matrix ."); 
return 0; 
}
