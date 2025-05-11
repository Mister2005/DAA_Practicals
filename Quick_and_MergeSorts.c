#include <stdio.h>
#include <conio.h>
#define MAX 50

void quick(int a[], int low, int high) {
    if (low < high) {
        int i = low, j = high;
        int pivot = a[(low + high)/2];
        
        while (i <= j) {
            while (a[i] < pivot) i++;
            while (a[j] > pivot) j--;
            
            if (i <= j) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i++;
                j--;
            }
        }
        
        if (low < j) quick(a, low, j);
        if (i < high) quick(a, i, high);
    }
}

void merge(int a[], int l, int m, int r) {
    int L[MAX], R[MAX];
    int i, j, k = l;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    for (i = 0; i < n1; i++) L[i] = a[l + i];
    for (j = 0; j < n2; j++) R[j] = a[m + 1 + j];
    
    i = j = 0;
    while (i < n1 && j < n2) {
        a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
    
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

void printArray(int arr[], int n, char* msg) {
    printf("%s: ", msg);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    //clrscr();
    int n, i, choice;
    int arr[MAX];
    
    printf("Sorting Algorithms: Quick Sort and Merge Sort\n");
    printf("----------------------------------------\n\n");
    
    printf("Enter number of elements (max %d): ", MAX);
    scanf("%d", &n);
    
    if(n <= 0 || n > MAX) {
        printf("Invalid array size!\n");
        //getch();
        return 1;
    }
    
    printf("\nEnter array elements:\n");
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    printArray(arr, n, "Original array");
    
    printf("\nChoose sorting method:\n");
    printf("1. Quick Sort\n");
    printf("2. Merge Sort\n");
    printf("Enter choice (1/2): ");
    scanf("%d", &choice);
    
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
        return 1;
    }
    
    printArray(arr, n, "Sorted array");
    
    printf("\nPress any key to exit...");
    //getch();
    return 0;
}