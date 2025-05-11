/* Practical 22: Any Small Modification in Algorithm */
/* Example: Modify Quick Sort to count swaps */

#include <stdio.h>
#include <conio.h>
#define MAX 100

int swapCount = 0;

void quickMod(int a[], int low, int high) {
    int i = low, j = high, pivot = a[(low+high)/2], temp;
    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            temp = a[i]; a[i] = a[j]; a[j] = temp;
            swapCount++;
            i++; j--;
        }
    }
    if (low < j) quickMod(a, low, j);
    if (i < high) quickMod(a, i, high);
}

void main() {
    int n, i;
    int arr[MAX];
    
    printf("Enter the number of elements (max %d): ", MAX);
    scanf("%d", &n);
    
    if(n <= 0 || n > MAX) {
        printf("Invalid array size! Please enter a number between 1 and %d\n", MAX);
        return;
    }
    
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    printf("\nOriginal array: ");
    for(i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    
    quickMod(arr, 0, n-1);
    
    printf("\nSorted array: ");
    for(i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    printf("\nNumber of swaps performed: %d\n", swapCount);
}
