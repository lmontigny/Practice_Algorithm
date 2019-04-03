// With the help from https://www.programiz.com/dsa/merge-sort

#include <stdio.h>

void merge(int A[], int p, int q, int r)
{
    int i,j,k;

    /* Create L ← A[p..q] and M ← A[q+1..r] */
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];
    for (i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (j = 0; j < n2; j++)
        M[j] = A[q + 1 + j];

    i = 0;
    j = 0;
    k = p;
    while(i<n1 && j<n2)
    {
        if(L[i] <= M[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        A[k] = M[j];
        j++;
        k++;
    }
}

// Merge sort algorithm
// O(n*log n)
void mergeSort(int A[], int low, int high)
{
    if (low < high){
        int middle = (low+high)/2;
        mergeSort(A, low, middle);
        mergeSort(A, middle+1, high);
        merge(A, low, middle, high);
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++) {
        printf(" %d ", A[i]);
    }
    printf("\n");
}

int main()
{
    int A[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(A)/sizeof(A[0]);

    printArray(A, n);
    mergeSort(A, 0, n-1);
    printArray(A, n);

    return 0;
}
