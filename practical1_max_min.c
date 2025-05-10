#include <stdio.h>
#include <conio.h>

typedef struct { int min, max; } Pair;

Pair getMinMax(int arr[], int low, int high) {
    Pair mm, mml, mmr;
    int mid;
    if (low == high) { mm.min = mm.max = arr[low]; return mm; }
    if (high == low + 1) {
        if (arr[low] < arr[high]) { mm.min = arr[low]; mm.max = arr[high]; }
        else { mm.min = arr[high]; mm.max = arr[low]; }
        return mm;
    }
    mid = (low + high) / 2;
    mml = getMinMax(arr, low, mid);
    mmr = getMinMax(arr, mid + 1, high);
    mm.min = (mml.min < mmr.min) ? mml.min : mmr.min;
    mm.max = (mml.max > mmr.max) ? mml.max : mmr.max;
    return mm;
}

void main() {
    //clrscr();
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[50];
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    Pair result = getMinMax(arr, 0, n-1);
    printf("Minimum = %d\nMaximum = %d", result.min, result.max);
    //getch();
}