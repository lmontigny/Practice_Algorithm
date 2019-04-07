#include <stdio.h>

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++) {
        printf(" %d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high)
{
    int i,j,p,tmp;
    p = high;
    i = low;
    j = high;
    while(i<j){
        // Search for element bigger than pivot to be moved
        while(A[i]<=A[p] && i<high)
            i++;
        // Search for elements smaller than pivot to be moved
        while(A[j]>A[p])
            j--;
        // Swap elements
        if(i<j){
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    return p;
}

void quickSort(int A[], int low, int high)
{
    if(low<high){ //if segment only one element, avoid 
        int p = partition(A, low, high);
        quickSort(A, low, p-1); // left part
        quickSort(A, p+1, high); // right part
    }
}

int main()
{
    int A[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(A)/sizeof(A[0]);

    printArray(A, n);
    quickSort(A, 0, n-1);
    /* printArray(A, n); */

    return 0;
}
