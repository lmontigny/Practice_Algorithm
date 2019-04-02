#include <stdio.h>

// Selection sort algorithm
// O(n^2)
void selectionSort(int arr[], int n)
{
    int i;
    for (i=0; i < n-1; i++) {
        int min_pos = i;
        int j;
        for (j=min_pos+1; j < n; j++){
            if(arr[j] < arr[min_pos]){
                min_pos = j;
            }
        }

        // Swap element
        int tmp = arr[i];
        arr[i] = arr[min_pos];
        arr[min_pos] = tmp;
    }

}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++) {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);

    printArray(arr, n);
    return 0;
}
