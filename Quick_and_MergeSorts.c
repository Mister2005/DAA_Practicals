#include <stdio.h>
#include <conio.h>
#define MAX 50

// Function to perform Quick Sort
void quick(int a[], int low, int high) {
    // If array contains at least 2 elements
    if (low < high) {
        int i = low, j = high;
        // Choose middle element as pivot
        int pivot = a[(low + high)/2];
        
        // Partition the array
        while (i <= j) {
            // Find element greater than pivot
            while (a[i] < pivot) i++;
            // Find element smaller than pivot
            while (a[j] > pivot) j--;
            
            // If elements are found, swap them
            if (i <= j) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i++;
                j--;
            }
        }
        
        // Recursively sort sub-arrays
        if (low < j) quick(a, low, j);
        if (i < high) quick(a, i, high);
    }
}

// Function to merge two sorted sub-arrays
void merge(int a[], int l, int m, int r) {
    int L[MAX], R[MAX];  // Temporary arrays
    int i, j, k = l;
    int n1 = m - l + 1;  // Size of left array
    int n2 = r - m;      // Size of right array
    
    // Copy data to temporary arrays
    for (i = 0; i < n1; i++) L[i] = a[l + i];
    for (j = 0; j < n2; j++) R[j] = a[m + 1 + j];
    
    // Merge temporary arrays back into original array
    i = j = 0;
    while (i < n1 && j < n2) {
        a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
    
    // Copy remaining elements if any
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

// Function to perform Merge Sort
void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        // Sort first and second halves
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        // Merge the sorted halves
        merge(a, l, m, r);
    }
}

// Function to print array
void printArray(int arr[], int n, char* msg) {
    printf("%s: ", msg);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main() {
    //clrscr();  // Clear screen for Turbo C
    int n, i, choice;
    int arr[MAX];
    
    printf("Sorting Algorithms: Quick Sort and Merge Sort\n");
    printf("----------------------------------------\n\n");
    
    printf("Enter number of elements (max %d): ", MAX);
    scanf("%d", &n);
    
    if(n <= 0 || n > MAX) {
        printf("Invalid array size!\n");
        //getch();
        return;
    }
    
    // Input array elements
    printf("\nEnter array elements:\n");
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    // Display original array
    printArray(arr, n, "Original array");
    
    // Choose sorting method
    printf("\nChoose sorting method:\n");
    printf("1. Quick Sort\n");
    printf("2. Merge Sort\n");
    printf("Enter choice (1/2): ");
    scanf("%d", &choice);
    
    // Apply chosen sorting method
    if (choice == 1) {
        printf("\nApplying Quick Sort...\n");
        quick(arr, 0, n-1);
    }
    else if (choice == 2) {
        printf("\nApplying Merge Sort...\n");
        mergeSort(arr, 0, n-1);
    }
    else {
        printf("Invalid choice!\n");
        //getch();
        return;
    }
    
    // Display sorted array
    printArray(arr, n, "Sorted array");
    
    printf("\nPress any key to exit...");
    //getch();  // Wait for key press in Turbo C
}