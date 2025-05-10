#include <stdio.h>
#include <conio.h>

void quick(int a[], int low, int high) {
    int i = low, j = high, pivot = a[(low + high)/2], temp;
    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) { temp = a[i]; a[i] = a[j]; a[j] = temp; i++; j--; }
    }
    if (low < j) quick(a, low, j);
    if (i < high) quick(a, i, high);
}

void merge(int a[], int l, int m, int r) {
    int L[50], R[50], i, j, k = l;
    int n1 = m - l + 1, n2 = r - m;
    for (i = 0; i < n1; i++) L[i] = a[l + i];
    for (j = 0; j < n2; j++) R[j] = a[m + 1 + j];
    i = j = 0;
    while (i < n1 && j < n2)
        a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
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

void main() {
    //clrscr();
    int n, i, choice;
    int arr[50];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("1. Quick Sort\n2. Merge Sort\nChoose: ");
    scanf("%d", &choice);
    if (choice == 1) quick(arr, 0, n-1);
    else mergeSort(arr, 0, n-1);
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    //getch();
}