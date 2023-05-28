#include <stdio.h>

void partition(int A[], int low, int high);

void rearrange(int A[], int size, int k){
    partition(A,0,size-1);
    int temp = A[size-1];
    A[size-1] = A[k];
    A[k] = temp;
}

// A recursive function to partition an array A[low..high]
// around a pivot element A[high]
void partition(int A[], int low, int high)
{
    // base case: single element or empty array
    if (low >= high)
        return;

    // swap the pivot element with the last element
    int temp = A[high];
    A[high] = A[low];
    A[low] = temp;

    // index of the pivot element after partitioning
    int pivot = low;

    // each time we find an element less than or equal to the pivot,
    // `pivot` is incremented, and that element would be placed
    // before the pivot
    for (int i = low; i < high; i++)
    {
        if (A[i] <= A[high])
        {
            temp = A[i];
            A[i] = A[pivot];
            A[pivot] = temp;
            pivot++;
        }
    }

    // swap the pivot element with the current element pointed by `pivot`
    temp = A[pivot];
    A[pivot] = A[high];
    A[high] = temp;

    // recur on subarray containing elements that are less than the pivot
    partition(A, low, pivot - 1);

    // recur on subarray containing elements that are more than the pivot
    partition(A, pivot + 1, high);
}

int main() {
    int A[] = {9,4,7,2,1,6,8,3,5};
    int size = sizeof(A) / sizeof(A[0]);
    int k = 8;
    
    printf("Original array: ");
    for (int i=0; i<size; i++){
        printf("%i", A[i]);
    }
    
    rearrange(A,size,k);
    
    printf("\nModified array: ");
    
    for (int i=0; i<size; i++){
        printf("%i", A[i]);
        if(i!=size-1){
            printf(",");
        }
        
    }
    
    return 0;
}
