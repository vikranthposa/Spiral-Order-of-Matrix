#include <stdio.h>
#include "stdlib.h"

#define right 0;
#define left  1;
#define up    2;
#define down  3;

int printColumn(int arr[5][5], int *col, int *topRow, int *bottomRow, int dir)
{
    if(*bottomRow < *topRow) {
        return 0;
    }
    
    if(dir == 3) {
        for ( int row = *topRow; row <= *bottomRow ; row++) {
            printf("%d ", arr[row][*col]);
        }
        (*col)--;
    }
    if(dir == 2) {
        for ( int row = *bottomRow; row >= *topRow ; row--) {
            printf("%d ", arr[row][*col]);
        }
        (*col)++;
    }
    return 1;
}



int printRow(int arr[5][5], int *row, int *leftCol, int *rightCol, int dir)
{
    if(*rightCol < *leftCol) {
        return 0;
    }
    
    if(dir == 0) {
        for ( int col = *leftCol; col <= *rightCol ; col++) {
            printf("%d ", arr[*row][col]);
        }
        (*row)++;
    }
    if(dir == 1) {
        for ( int col = *rightCol; col >= *leftCol ; col--) {
            printf("%d ", arr[*row][col]);
        }
        (*row)--;
    }
    return 1;
}

void printMatrix(int m, int n, int arr[m][n])
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
    printf("\n");
    }
}

void printDynArr(int **arr, int m ,int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int R = 5; int C = 5;
    
    int arr[5][5] =
    {{1,2,3,4,5},
    {6,7,8,9,10},
    {11,12,13,14,15},
    {16,17,18,19,20},
    {21,22,23,24,25}};
   
    printMatrix(R,C,arr);
    
    //printDynArr(arr,R,C);

    
    printf("\n");
    
   
    int **dynArr;
    dynArr = (int **)malloc(sizeof(int*) *R);
    for (int i=0; i<R; i++) {
        dynArr[i] = (int *)malloc(sizeof(int) * C);
    }
    int k=25;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            dynArr[i][j] = k--;
        }
    }
    printDynArr(dynArr,R,C);
    
    
    int topRow = 0, bottomRow = R-1, leftCol = 0, rightCol = C-1;
    
    while(1)
    {
        if(!printRow(arr, &topRow, &leftCol, &rightCol, 0))
            break;
        if(!printColumn(arr, &rightCol, &topRow, &bottomRow, 3))
          break;
        if(!printRow(arr, &bottomRow, &leftCol, &rightCol, 1))
            break;
        if(!printColumn(arr, &leftCol, &topRow, &bottomRow, 2))
            break;
    }
    
    
    return 0;
}
