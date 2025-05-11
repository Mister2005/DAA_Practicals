#include <stdio.h>
#include <conio.h>

int max(int a, int b) { 
    return (a > b) ? a : b; 
}

void printTable(int K[][51], int n, int W) {
    printf("\nDynamic Programming Table:\n");
    printf("   W→  ");
    for(int w = 0; w <= W; w++) {
        printf("%4d ", w);
    }
    printf("\n");
    printf("i↓    ");
    for(int w = 0; w <= W; w++) {
        printf("----+");
    }
    printf("\n");
    
    for(int i = 0; i <= n; i++) {
        printf("%2d |  ", i);
        for(int w = 0; w <= W; w++) {
            printf("%4d ", K[i][w]);
        }
        printf("\n");
    }
}

int knapSack(int W, int wt[], int val[], int n) {
    int K[n+1][51];  // Assuming max capacity won't exceed 50
    int i, w;
    
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i-1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }
    
    // Print the DP table
    printTable(K, n, W);
    
    // Print selected items
    printf("\nSelected items:\n");
    int res = K[n][W];
    w = W;
    for (i = n; i > 0 && res > 0; i--) {
        if (res != K[i-1][w]) {
            printf("Item %d: (Weight: %d, Value: %d)\n", i, wt[i-1], val[i-1]);
            res = res - val[i-1];
            w = w - wt[i-1];
        }
    }
    
    return K[n][W];
}

void main() {
    int n, W;
    
    printf("0/1 Knapsack Problem Solver\n");
    printf("---------------------------\n\n");
    
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    int wt[n], val[n];
    
    printf("\nEnter the details for each item:\n");
    for(int i = 0; i < n; i++) {
        printf("\nItem %d:\n", i+1);
        printf("Weight: ");
        scanf("%d", &wt[i]);
        printf("Value: ");
        scanf("%d", &val[i]);
    }
    
    printf("\nEnter knapsack capacity: ");
    scanf("%d", &W);
    
    if(W > 50) {
        printf("\nError: Capacity should not exceed 50\n");
        return;
    }
    
    printf("\nKnapsack Details:");
    printf("\n----------------");
    printf("\nCapacity: %d", W);
    printf("\nNumber of items: %d\n", n);
    
    int max_value = knapSack(W, wt, val, n);
    printf("\nMaximum value that can be obtained: %d\n", max_value);
    
    printf("\nPress any key to exit...");
    getch();
}
