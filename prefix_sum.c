#include <stdio.h>

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++) {
        printf(" %d ", A[i]);
    }
    printf("\n");
}

void scan(int A[], int n)
{
    int i;
    for (i=1; i < n; i++) {
        A[i] += A[i-1];
    }

}

int main()
{
    int A[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(A)/sizeof(A[0]);

    printArray(A, n);
    scan(A, n);
    printArray(A, n);

    return 0;
}
