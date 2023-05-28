# Given an unsorted array, A, of integers and an integer k, write recursive program using C language for rearranging the elements in A so that all elements less than or equal to k come before any elements larger than k

    #include <stdio.h>

Function prototype for partitioning the array

     void partition(int A[], int low, int high);
Function to rearrange the array elements
       
     void rearrange(int A[], int size, int k){
Call the partition function to partition the array
    
    partition(A, 0, size-1);
Swap the last element with the element at index k

    int temp = A[size-1];
    A[size-1] = A[k];
    A[k] = temp;
}

A recursive function to partition an array A[low..high]
around a pivot element A[high]

    void partition(int A[], int low, int high)
    {
Base case: single element or empty array
   
    if (low >= high)
        return;

Swap the pivot element with the first element
    
    int temp = A[high];
    A[high] = A[low];
    A[low] = temp;
Index of the pivot element after partitioning
    
    int pivot = low;
Each time we find an element less than or equal to the pivot,
`pivot` is incremented, and that element would be placed
before the pivot
    
    for (int i = low; i < high; i++)
    {
        if (A[i] <= A[high])
        {
Swap the element with the pivot
           
           temp = A[i];
            A[i] = A[pivot];
            A[pivot] = temp;
            
Increment the pivot index
          
          pivot++;
        }
    }

Swap the pivot element with the current element pointed by `pivot`
   
    temp = A[pivot];
    A[pivot] = A[high];
    A[high] = temp;

Recur on subarray containing elements that are less than the pivot
  
    partition(A, low, pivot - 1);

 Recur on subarray containing elements that are more than the pivot
    
       partition(A, pivot + 1, high);
    }

    int main() {
          int A[] = {9, 4, 7, 2, 1, 6, 8, 3, 5};
          int size = sizeof(A) / sizeof(A[0]);
          int k = 8;
    
    printf("Original array: ");
    for (int i = 0; i < size; i++){
        printf("%i", A[i]);
    }
    
 Rearrange the array elements
    
    rearrange(A, size, k);
    
    printf("\nModified array: ");
    
    for (int i = 0; i < size; i++){
        printf("%i", A[i]);
        
 Add comma separator except for the last element
       
        if(i != size-1){
            printf(",");
        }
    }
    
    return 0;
}
