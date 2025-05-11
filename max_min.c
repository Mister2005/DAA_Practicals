#include <stdio.h>
#include <conio.h>

struct MinMax { 
    int min, max; 
};

struct MinMax getMinMax(int arr[], int low, int high) {
    struct MinMax mm, mml, mmr;
    int mid;
    
    if (low == high) { 
        mm.min = mm.max = arr[low]; 
        return mm; 
    }
    
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
    
    mid = (low + high) / 2;
    mml = getMinMax(arr, low, mid);
    mmr = getMinMax(arr, mid + 1, high);
    
    mm.min = (mml.min < mmr.min) ? mml.min : mmr.min;
    mm.max = (mml.max > mmr.max) ? mml.max : mmr.max;
    return mm;
}

int main() {
    //clrscr();
    int n, i;
    
    printf("Divide and Conquer: Find Minimum and Maximum\n");
    printf("-----------------------------------------\n\n");
    
    printf("Enter number of elements (max 50): ");
    scanf("%d", &n);
    
    if(n <= 0 || n > 50) {
        printf("Invalid array size! Please enter between 1 and 50.\n");
        //getch();
        return 1;
    }
    
    int arr[50];
    printf("\nEnter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    printf("\nInput array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    struct MinMax result = getMinMax(arr, 0, n-1);
    
    printf("\n\nResults:\n");
    printf("Minimum = %d\n", result.min);
    printf("Maximum = %d\n", result.max);
    
    printf("\nPress any key to exit...");
    //getch();
    return 0;
}