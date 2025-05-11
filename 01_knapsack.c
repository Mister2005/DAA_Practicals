#include <stdio.h>
#include <conio.h>

// Function to return maximum of two numbers
int max(int a, int b) { 
    return (a > b) ? a : b; 
}

// Function to show the solution construction process
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

// Function to solve 0-1 Knapsack problem
int knapSack(int W, int wt[], int val[], int n) {
    int K[n+1][51];  // DP table (max weight assumed 50)
    int i, w;
    
    // Build table K[][] in bottom-up manner
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
    
    // Show solution construction process
    showSolutionSteps(K, n, W);
    
    // Print selected items
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

void main() {
    //clrscr();  // Clear screen for Turbo C
    int n, W;
    
    printf("0/1 Knapsack Problem Solver\n");
    printf("-------------------------\n\n");
    
    // Get number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    if(n <= 0) {
        printf("Invalid number of items!\n");
        //getch();
        return;
    }
    
    int wt[n], val[n];  // Arrays for weights and values
    
    // Input item details
    printf("\nEnter the details for each item:\n");
    for(int i = 0; i < n; i++) {
        printf("\nItem %d:\n", i+1);
        printf("Weight: ");
        scanf("%d", &wt[i]);
        printf("Value: ");
        scanf("%d", &val[i]);
        
        // Validate input
        if(wt[i] <= 0 || val[i] < 0) {
            printf("Invalid input! Weight must be positive and value non-negative.\n");
            //getch();
            return;
        }
    }
    
    // Get knapsack capacity
    printf("\nEnter knapsack capacity (max 50): ");
    scanf("%d", &W);
    
    if(W <= 0 || W > 50) {
        printf("\nError: Capacity should be between 1 and 50\n");
        //getch();
        return;
    }
    
    // Print problem details
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
    
    // Solve knapsack problem
    int max_value = knapSack(W, wt, val, n);
    printf("\nMaximum value that can be obtained: %d\n", max_value);
    
    printf("\nPress any key to exit...");
    //getch();  // Wait for key press in Turbo C
}
