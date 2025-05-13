#include <stdio.h>
#include <conio.h>
#define MAX 1000

void printCoinCombination(int coins[], int trackCoins[], int V) {
    if (V <= 0) return;
    int currentCoin = trackCoins[V];
    printCoinCombination(coins, trackCoins, V - coins[currentCoin]);
    printf("%d ", coins[currentCoin]);
}

int minCoins(int coins[], int m, int V) {
    int table[V+1];
    int trackCoins[V+1];
    table[0] = 0;
    for (int i = 1; i <= V; i++) {
        table[i] = MAX;
        trackCoins[i] = -1;
    }
    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < m; j++) {
            if (coins[j] <= i) {
                int sub_res = table[i - coins[j]] + 1;
                if (sub_res < table[i]) {
                    table[i] = sub_res;
                    trackCoins[i] = j;
                }
            }
        }
    }
    if (table[V] == MAX) 
        return -1;
    printf("\nCoins used in solution: ");
    printCoinCombination(coins, trackCoins, V);
    printf("\n");
    return table[V];
}

int main() {
    int m, V;
    //clrscr();
    printf("Enter number of coin types: ");
    scanf("%d", &m);
    int coins[m];
    for (int i = 0; i < m; i++) {
        printf("Enter value of coin %d: ", i + 1);
        scanf("%d", &coins[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &V);
    int result = minCoins(coins, m, V);
    if (result == -1)
        printf("\nNo solution possible to make %d with given coins.\n", V);
    else
        printf("Minimum coins required to make %d is %d\n", V, result);
    //getch();
    return 0;
}