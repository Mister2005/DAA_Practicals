#include <stdio.h>
#include <conio.h>
#define MAX 100

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort coins in descending order
void sortCoinsDescending(int coins[], int m) {
    for(int i = 0; i < m-1; i++) {
        for(int j = 0; j < m-i-1; j++) {
            if(coins[j] < coins[j+1]) {
                swap(&coins[j], &coins[j+1]);
            }
        }
    }
}

// Function to track and print coins used in Dynamic Programming
void printCoinsDP(int dp[][2], int target, int m) {
    printf("\nCoins used to make %d: ", target);
    int remainingAmount = target;
    int totalCoins = 0;
    
    while(remainingAmount > 0) {
        printf("%d ", dp[remainingAmount][1]);
        remainingAmount = remainingAmount - dp[remainingAmount][1];
        totalCoins++;
    }
    printf("\nTotal coins needed: %d\n", totalCoins);
}

void printTable(int dp[][2], int V) {
    printf("\nDynamic Programming Table:\n");
    printf("Amount: ");
    for(int i = 0; i <= V; i++) {
        printf("%4d ", i);
    }
    printf("\nMin Coins: ");
    for(int i = 0; i <= V; i++) {
        if(dp[i][0] == MAX)
            printf(" INF ");
        else
            printf("%4d ", dp[i][0]);
    }
    printf("\n");
}

// Dynamic Programming approach
void coinChangeDP(int coins[], int m, int V) {
    int dp[MAX][2];  // dp[i][0] stores min coins, dp[i][1] stores last coin used
    
    // Initialize dp table
    for(int i = 0; i <= V; i++) {
        dp[i][0] = MAX;  // Number of coins
        dp[i][1] = 0;    // Coin used
    }
    
    // Base case
    dp[0][0] = 0;
    
    // Fill the dp table
    for(int i = 1; i <= V; i++) {
        for(int j = 0; j < m; j++) {
            if(coins[j] <= i) {
                int sub_res = dp[i - coins[j]][0];
                if(sub_res != MAX && sub_res + 1 < dp[i][0]) {
                    dp[i][0] = sub_res + 1;
                    dp[i][1] = coins[j];  // Store the coin used
                }
            }
        }
    }
    
    // Print the DP table
    printTable(dp, V);
    
    // If solution exists, print the coins used
    if(dp[V][0] != MAX) {
        printCoinsDP(dp, V, m);
    } else {
        printf("\nNo solution exists using Dynamic Programming approach!\n");
    }
}

// Greedy approach
void coinChangeGreedy(int coins[], int m, int V) {
    // Sort coins in descending order
    sortCoinsDescending(coins, m);
    
    printf("\nGreedy Approach Solution:");
    printf("\n------------------------");
    
    int remainingAmount = V;
    int totalCoins = 0;
    int coinsUsed[MAX] = {0};  // To store count of each coin used
    
    // Try to use the largest possible coins first
    for(int i = 0; i < m && remainingAmount > 0; i++) {
        while(remainingAmount >= coins[i]) {
            remainingAmount -= coins[i];
            coinsUsed[i]++;
            totalCoins++;
        }
    }
    
    if(remainingAmount == 0) {
        printf("\nCoins used: ");
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < coinsUsed[i]; j++) {
                printf("%d ", coins[i]);
            }
        }
        printf("\nBreakdown of coins used:");
        for(int i = 0; i < m; i++) {
            if(coinsUsed[i] > 0) {
                printf("\nCoin %d: used %d time(s)", coins[i], coinsUsed[i]);
            }
        }
        printf("\nTotal number of coins needed: %d\n", totalCoins);
    } else {
        printf("\nNo solution exists using Greedy approach!\n");
    }
}

void main() {
    int coins[MAX], m, V;
    int choice;
    
    printf("Coin Change Problem Solver\n");
    printf("-------------------------\n\n");
    
    // Get number of coins
    printf("Enter the number of different coins: ");
    scanf("%d", &m);
    
    if(m <= 0 || m > MAX) {
        printf("Invalid number of coins!\n");
        return;
    }
    
    // Get coin denominations
    printf("\nEnter the value of each coin:\n");
    for(int i = 0; i < m; i++) {
        printf("Coin %d: ", i+1);
        scanf("%d", &coins[i]);
        if(coins[i] <= 0) {
            printf("Invalid coin value! Coins must be positive.\n");
            return;
        }
    }
    
    // Get target amount
    printf("\nEnter the target amount: ");
    scanf("%d", &V);
    
    if(V <= 0 || V > MAX) {
        printf("Invalid target amount!\n");
        return;
    }
    
    printf("\nProblem Details:");
    printf("\n---------------");
    printf("\nAvailable coins: ");
    for(int i = 0; i < m; i++) {
        printf("%d ", coins[i]);
    }
    printf("\nTarget amount: %d\n", V);
    
    // Method selection
    printf("\nSelect the method to solve:");
    printf("\n1. Dynamic Programming approach");
    printf("\n2. Greedy approach");
    printf("\nEnter your choice (1/2): ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: {
            printf("\nUsing Dynamic Programming Approach:");
            printf("\n--------------------------------");
            coinChangeDP(coins, m, V);
            break;
        }
        case 2: {
            printf("\nUsing Greedy Approach:");
            printf("\n---------------------");
            int tempCoins[MAX];
            // Make a copy of coins array as it will be sorted for greedy approach
            for(int i = 0; i < m; i++) tempCoins[i] = coins[i];
            coinChangeGreedy(tempCoins, m, V);
            break;
        }
        default:
            printf("\nInvalid choice!\n");
    }
    
    printf("\nPress any key to exit...");
    getch();
}
