#include <stdio.h>

void printArray(int *arr, int n)
{
    int i;
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int findMax(int *A, int n)
{
    int i;
    int max = A[0];
    for(i=1; i<n; i++){
        if(A[i]>A[i-1])
            max = A[i];
    }
    return max;
}

void countingSort(int *A, int n, int digit)
{
    int i;
    int decimal = 10;
    int C[10];
    for(i=0; i<10; i++){
        C[i] = 0;
    }

    // Count only the least_significant_digit
    // decimal is constant, always 10
    // Ex: (250/1)%10  = 0
    // Ex: (250/10)%10 = 5
    for(i=0; i<n; i++){
        C[(A[i]/digit)%decimal]++;
    }

    for(i=1; i<10; i++){
        C[i] += C[i-1];
    }

    int B[n];
    for(i=n-1; i>=0; i--){
        B[--C[(A[i]/digit)%decimal]] = A[i];
    }

    for(i=0; i<n; i++){
        A[i] = B[i];
    }

}

void radixSort(int *A, int n)
{
    int max_value = findMax(A,n);
    int least_significant_digit = 1;

    // Operate on the least_significant_digit first
    // Ex: 250/1 = 250 hence 0
    //     next iteration 250/10 = 25, hence 5
    while(max_value/least_significant_digit > 0){
        countingSort(A,n,least_significant_digit);
        least_significant_digit *= 10;
    }
}


int main()
{
    int arr[5] = {10,4,11,5,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    radixSort(arr, n);
    printArray(arr, n);

    return 0;
}
