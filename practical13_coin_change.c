#include <stdio.h>
#include <conio.h>
#define MAX 100

int min(int a, int b) { 
    return (a < b) ? a : b; 
}

void printCoins(int table[], int coins[], int m, int V) {
    printf("\nCoins used: ");
    int value = V;
    while(value > 0) {
        for(int j = 0; j < m; j++) {
            if(value >= coins[j] && table[value] == table[value - coins[j]] + 1) {
                printf("%d ", coins[j]);
                value -= coins[j];
                break;
            }
        }
    }
    printf("\n");
}

void printTable(int table[], int V) {
    printf("\nDynamic Programming Table:\n");
    printf("Amount: ");
    for(int i = 0; i <= V; i++) {
        printf("%4d ", i);
    }
    printf("\nCoins : ");
    for(int i = 0; i <= V; i++) {
        if(table[i] == 9999)
            printf(" INF ");
        else
            printf("%4d ", table[i]);
    }
    printf("\n");
}

int coinChange(int coins[], int m, int V) {
    int table[MAX];
    int i, j;
    
    // Initialize table with maximum value
    for (i = 0; i <= V; i++) 
        table[i] = 9999;
    
    // Base case
    table[0] = 0;
    
    // Fill the table in bottom-up manner
    for (i = 1; i <= V; i++) {
        for (j = 0; j < m; j++) {
            if (coins[j] <= i) {
                int sub_res = table[i-coins[j]];
                if (sub_res != 9999 && sub_res + 1 < table[i])
                    table[i] = sub_res + 1;
            }
        }
    }
    
    // Print the DP table
    printTable(table, V);
    
    // If solution exists, print the coins used
    if(table[V] != 9999) {
        printCoins(table, coins, m, V);
    }
    
    return table[V];
}

void main() {
    int coins[MAX], m, V;
    
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
    
    int result = coinChange(coins, m, V);
    
    if(result == 9999)
        printf("\nIt's not possible to make the amount %d with given coins\n", V);
    else
        printf("\nMinimum coins required: %d\n", result);
    
    printf("\nPress any key to exit...");
    getch();
}
