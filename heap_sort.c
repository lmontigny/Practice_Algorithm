#include <stdio.h>

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void maxHeap(int *arr, int n, int i)
{
    /*
     * If the index of any element in the array is i, the element in the index
     * 2i+1 will become the left child and element in 2i+2 index will become the
     * right child.
     */
    int left = 2*i+1;
    int right = 2*i+2;
    int largest = i;

    if(left<n && arr[left] > arr[largest])
        largest = left;
    if(right<n && arr[right] > arr[largest])
        largest = right;

    if(largest!=i){
        swap(&arr[i], &arr[largest]);
        maxHeap(arr, n, largest);
    }
}

void printArray(int *arr, int n)
{
    int i;
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[5] = {10,4,11,5,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);

    /* Start from the first NON-leaf node */
    /* In the case of complete tree, the first index of non-leaf node is given by n/2 - 1. */
    /* find the largest and swap and continue locally to rearrange the node below */
    int i;
    for(i=n/2-1; i>=0; i--){
        maxHeap(arr, n, i);
    }

    /* Heap Sort */
    /* We know where the largest is: arr[0] */
    /* We put it at the end, reduce the size of the array */
    /* and we redo the maxHeap to find the second largest */
    /* we do maxHeap from the node 0 */
    for(i=n-1; i>=0; i--){
        swap(&arr[0], &arr[i]);
        maxHeap(arr, i, 0);
    }

    printArray(arr, n);

    return 0;
}
