#include <stdio.h>

void printArray(int *arr, int n)
{
    int i;
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void countingSort(int *A, int n)
{
    int i;

    /* Find max */
    int max = 0;
    for(i=1; i<n; i++){
        if(A[i]>A[i-1])
            max = A[i];
    }

    // Init count array
    int count[max+1];
    for(i=0; i<max+1; i++){
        count[i] = 0;
    }

    /* Count number of occurence */
    for(i=0; i<n; i++){
        count[A[i]] += 1;
    }

    /* Prefix sum */
    for(i=1; i<max+1; i++){
        count[i] += count[i-1];
    }

    /* Fill sorted array */
    int B[n];
    for(i=n-1; i>=0; i--){
        B[--count[A[i]]] = A[i];
    }

    /* Replace array */
    for(i=0; i<n; i++){
        A[i] = B[i];
    }
}


int main()
{
    int arr[5] = {10,4,11,5,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    countingSort(arr, n);
    printArray(arr, n);

    return 0;
}
