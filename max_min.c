#include <stdio.h>
#include <conio.h>

// Define a structure to hold both minimum and maximum values
struct MinMax { 
    int min, max; 
};

// Function to find minimum and maximum using divide and conquer
struct MinMax getMinMax(int arr[], int low, int high) {
    struct MinMax mm, mml, mmr;  // mm for result, mml for left subarray, mmr for right subarray
    int mid;
    
    // Base case: if only one element
    if (low == high) { 
        mm.min = mm.max = arr[low]; 
        return mm; 
    }
    
    // Base case: if only two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) { 
            mm.min = arr[low]; 
            mm.max = arr[high]; 
        }
        else { 
            mm.min = arr[high]; 
            mm.max = arr[low]; 
        }
        return mm;
    }
    
    // Recursive case: divide array into two parts
    mid = (low + high) / 2;
    mml = getMinMax(arr, low, mid);       // Get min-max for left half
    mmr = getMinMax(arr, mid + 1, high);  // Get min-max for right half
    
    // Combine results
    mm.min = (mml.min < mmr.min) ? mml.min : mmr.min;
    mm.max = (mml.max > mmr.max) ? mml.max : mmr.max;
    return mm;
}

void main() {
    //clrscr();  // Clear screen for Turbo C
    int n, i;
    
    printf("Divide and Conquer: Find Minimum and Maximum\n");
    printf("-----------------------------------------\n\n");
    
    // Input array size
    printf("Enter number of elements (max 50): ");
    scanf("%d", &n);
    
    // Validate input
    if(n <= 0 || n > 50) {
        printf("Invalid array size! Please enter between 1 and 50.\n");
        //getch();
        return;
    }
    
    // Input array elements
    int arr[50];
    printf("\nEnter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    // Print input array
    printf("\nInput array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    // Find min and max using divide and conquer
    struct MinMax result = getMinMax(arr, 0, n-1);
    
    // Print results
    printf("\n\nResults:\n");
    printf("Minimum = %d\n", result.min);
    printf("Maximum = %d\n", result.max);
    
    printf("\nPress any key to exit...");
    //getch();  // Wait for key press in Turbo C
}