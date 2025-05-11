/* Practical: Modification of Quick Sort to Count Swaps */
#include <stdio.h>
#include <conio.h>
#define MAX 100

// Global variable to track number of swaps
int swapCount = 0;

// Function to swap two elements and count the swap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    swapCount++;
    printf("Swap performed: %d <-> %d (Total swaps: %d)\n", *a, *b, swapCount);
}

// Modified Quick Sort function that counts swaps
void quickModified(int a[], int low, int high) {
    // If array contains at least 2 elements
    if (low < high) {
        int i = low, j = high;
        // Choose middle element as pivot
        int pivot = a[(low + high)/2];
        
        printf("\nPartitioning array around pivot %d\n", pivot);
        printf("Current array segment: ");
        for(int k = low; k <= high; k++)
            printf("%d ", a[k]);
        printf("\n");
        
        // Partition array around pivot
        while (i <= j) {
            while (a[i] < pivot) i++;
            while (a[j] > pivot) j--;
            
            if (i <= j) {
                if(i != j) {  // Only swap if elements are different
                    swap(&a[i], &a[j]);
                }
                i++;
                j--;
            }
        }
        
        // Print array after partition
        printf("After partition: ");
        for(int k = low; k <= high; k++)
            printf("%d ", a[k]);
        printf("\n");
        
        // Recursively sort sub-arrays
        if (low < j) {
            printf("\nProcessing left sub-array...\n");
            quickModified(a, low, j);
        }
        if (i < high) {
            printf("\nProcessing right sub-array...\n");
            quickModified(a, i, high);
        }
    }
}

void main() {
    //clrscr();  // Clear screen for Turbo C
    int n, i;
    int arr[MAX];
    
    printf("Modified Quick Sort - Counting Swaps\n");
    printf("--------------------------------\n\n");
    
    printf("Enter the number of elements (max %d): ", MAX);
    scanf("%d", &n);
    
    if(n <= 0 || n > MAX) {
        printf("Invalid array size! Please enter a number between 1 and %d\n", MAX);
        //getch();
        return;
    }
    
    printf("\nEnter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    printf("\nOriginal array: ");
    for(i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    printf("\n\nStarting Quick Sort...\n");
    
    // Reset swap counter
    swapCount = 0;
    
    // Sort array and count swaps
    quickModified(arr, 0, n-1);
    
    printf("\nFinal Results:\n");
    printf("-------------\n");
    printf("Sorted array: ");
    for(i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    printf("\nTotal number of swaps performed: %d\n", swapCount);
    
    printf("\nPress any key to exit...");
    //getch();  // Wait for key press in Turbo C
}
