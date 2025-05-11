#include <stdio.h>
#include <conio.h>
#define MAX 100

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortCoinsDescending(int coins[], int m) {
    for(int i = 0; i < m-1; i++) {
        for(int j = 0; j < m-i-1; j++) {
            if(coins[j] < coins[j+1]) {
                swap(&coins[j], &coins[j+1]);
            }
        }
    }
}

void printCoinsDP(int dp[][2], int target, int m) {
    printf("\nCoins used to make %d:\n", target);
    printf("---------------------\n");
    int remainingAmount = target;
    int totalCoins = 0;
    int coinCount[MAX] = {0};
    
    while(remainingAmount > 0) {
        int coin = dp[remainingAmount][1];
        coinCount[coin]++;
        remainingAmount = remainingAmount - coin;
        totalCoins++;
    }
    
    for(int i = 0; i < MAX; i++) {
        if(coinCount[i] > 0) {
            printf("Coin %d used %d time(s)\n", i, coinCount[i]);
        }
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

void coinChangeDP(int coins[], int m, int V) {
    int dp[MAX][2];
    
    for(int i = 0; i <= V; i++) {
        dp[i][0] = MAX;
        dp[i][1] = 0;
    }
    
    dp[0][0] = 0;
    
    printf("\nBuilding solution using Dynamic Programming...\n");
    for(int i = 1; i <= V; i++) {
        for(int j = 0; j < m; j++) {
            if(coins[j] <= i) {
                int sub_res = dp[i - coins[j]][0];
                if(sub_res != MAX && sub_res + 1 < dp[i][0]) {
                    dp[i][0] = sub_res + 1;
                    dp[i][1] = coins[j];
                    printf("Found better solution for amount %d using coin %d\n", 
                           i, coins[j]);
                }
            }
        }
    }
    
    printTable(dp, V);
    
    if(dp[V][0] != MAX) {
        printCoinsDP(dp, V, m);
    } else {
        printf("\nNo solution exists using Dynamic Programming approach!\n");
    }
}

void coinChangeGreedy(int coins[], int m, int V) {
    sortCoinsDescending(coins, m);
    
    printf("\nGreedy Approach Solution:\n");
    printf("----------------------\n");
    
    int remainingAmount = V;
    int totalCoins = 0;
    int coinsUsed[MAX] = {0};
    
    printf("Process:\n");
    for(int i = 0; i < m && remainingAmount > 0; i++) {
        if(coins[i] <= remainingAmount) {
            int count = remainingAmount / coins[i];
            coinsUsed[i] = count;
            remainingAmount -= coins[i] * count;
            totalCoins += count;
            printf("Used %d coin(s) of value %d\n", count, coins[i]);
        }
    }
    
    if(remainingAmount == 0) {
        printf("\nSolution found!\n");
        printf("\nBreakdown of coins used:\n");
        for(int i = 0; i < m; i++) {
            if(coinsUsed[i] > 0) {
                printf("Coin %d: used %d time(s)\n", coins[i], coinsUsed[i]);
            }
        }
        printf("\nTotal coins needed: %d\n", totalCoins);
    } else {
        printf("\nNo solution exists using Greedy approach!\n");
    }
}

int main() {
    //clrscr();
    int coins[MAX], m, V;
    int choice;
    
    printf("Coin Change Problem Solver\n");
    printf("------------------------\n\n");
    
    printf("Enter the number of different coins (max %d): ", MAX);
    scanf("%d", &m);
    
    if(m <= 0 || m > MAX) {
        printf("Invalid number of coins!\n");
        //getch();
        return 1;
    }
    
    printf("\nEnter the value of each coin:\n");
    for(int i = 0; i < m; i++) {
        printf("Coin %d: ", i+1);
        scanf("%d", &coins[i]);
        if(coins[i] <= 0) {
            printf("Invalid coin value! Must be positive.\n");
            //getch();
            return 1;
        }
    }
    
    printf("\nEnter the target amount: ");
    scanf("%d", &V);
    
    if(V <= 0 || V > MAX) {
        printf("Invalid target amount!\n");
        //getch();
        return 1;
    }
    
    printf("\nProblem Details:\n");
    printf("--------------\n");
    printf("Available coins: ");
    for(int i = 0; i < m; i++) {
        printf("%d ", coins[i]);
    }
    printf("\nTarget amount: %d\n", V);
    
    printf("\nSelect the method to solve:\n");
    printf("1. Dynamic Programming approach\n");
    printf("2. Greedy approach\n");
    printf("Enter your choice (1/2): ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("\nSolving using Dynamic Programming...\n");
            coinChangeDP(coins, m, V);
            break;
        case 2:
            printf("\nSolving using Greedy approach...\n");
            int tempCoins[MAX];
            for(int i = 0; i < m; i++) 
                tempCoins[i] = coins[i];
            coinChangeGreedy(tempCoins, m, V);
            break;
        default:
            printf("\nInvalid choice!\n");
    }
    
    printf("\nPress any key to exit...");
    //getch();
    return 0;
}