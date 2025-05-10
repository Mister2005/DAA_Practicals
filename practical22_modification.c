/* Practical 22: Any Small Modification in Algorithm */
/* Example: Modify Quick Sort to count swaps */

#include <stdio.h>
#include <conio.h>

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
    //clrscr();
    int arr[] = {10, 7, 8, 9, 1, 5}, n = 6, i;
    quickMod(arr, 0, n-1);
    printf("Sorted array: ");
    for (i=0;i<n;i++) printf("%d ", arr[i]);
    printf("\\nSwap count = %d", swapCount);
    //getch();
}
