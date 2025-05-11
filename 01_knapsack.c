#include <stdio.h>
#include <conio.h>

int max(int a, int b) { 
    return (a > b) ? a : b; 
}

void showSolutionSteps(int K[][51], int n, int W) {
    printf("\nSolution Construction Process:\n");
    printf("---------------------------\n");
    for (int i = 1; i <= n; i++) {
        printf("After considering item %d:\n", i);
        for (int w = 0; w <= W; w++) {
            if (K[i][w] > K[i-1][w]) {
                printf("  Weight %d: Value increased to %d\n", w, K[i][w]);
            }
        }
        printf("\n");
    }
}

int knapSack(int W, int wt[], int val[], int n) {
    int K[n+1][51];
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
    
    showSolutionSteps(K, n, W);
    
    printf("\nSelected items for optimal solution:\n");
    printf("-------------\n");
    w = W;
    int totalWeight = 0;
    for (i = n; i > 0 && K[i][w] > 0; i--) {
        if (K[i][w] != K[i-1][w]) {
            printf("Item %d: (Weight: %d, Value: %d)\n", 
                   i, wt[i-1], val[i-1]);
            totalWeight += wt[i-1];
            w = w - wt[i-1];
        }
    }
    printf("\nTotal weight used: %d/%d\n", totalWeight, W);
    
    return K[n][W];
}

int main() {
    int n, W;
    
    printf("0/1 Knapsack Problem Solver\n");
    printf("-------------------------\n\n");
    
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    if(n <= 0) {
        printf("Invalid number of items!\n");
        return 1;
    }
    
    int wt[n], val[n];
    
    printf("\nEnter the details for each item:\n");
    for(int i = 0; i < n; i++) {
        printf("\nItem %d:\n", i+1);
        printf("Weight: ");
        scanf("%d", &wt[i]);
        printf("Value: ");
        scanf("%d", &val[i]);
        
        if(wt[i] <= 0 || val[i] < 0) {
            printf("Invalid input! Weight must be positive and value non-negative.\n");
            return 1;
        }
    }
    
    printf("\nEnter knapsack capacity (max 50): ");
    scanf("%d", &W);
    
    if(W <= 0 || W > 50) {
        printf("\nError: Capacity should be between 1 and 50\n");
        return 1;
    }
    
    printf("\nKnapsack Details:\n");
    printf("----------------\n");
    printf("Capacity: %d\n", W);
    printf("Number of items: %d\n\n", n);
    printf("Available Items:\n");
    printf("Item\tWeight\tValue\tValue/Weight\n");
    printf("----------------------------------\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%.2f\n", 
               i+1, wt[i], val[i], (float)val[i]/wt[i]);
    }
    
    int max_value = knapSack(W, wt, val, n);
    printf("\nMaximum value that can be obtained: %d\n", max_value);
    
    printf("\nPress any key to exit...");
    return 0;
}