#include <stdio.h>
#define MAX 21
#define INF 9999

void printLine(int n) {
    for(int i = 0; i < 40; i++) printf("-");
    printf("\n");
}

int main() {
    int G[MAX][MAX], cost[MAX][MAX], visited[MAX], n, i, j, count, mincost, u, v;
    //clrscr();
    printf("Enter number of vertices (max %d): ", MAX-1);
    scanf("%d", &n);
    if(n <= 0 || n >= MAX) {
        printf("Invalid number of vertices! Must be between 1 and %d\n", MAX-1);
        return 1;
    }
    printf("\nEnter the adjacency matrix:\n");
    printf("(Enter 0 for no edge, and weight for connected edges)\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &G[i][j]);
            if(G[i][j] < 0) {
                printf("Error: Negative weights not allowed!\n");
                return 1;
            }
            if(G[i][j] == 0) cost[i][j] = INF;
            else cost[i][j] = G[i][j];
        }
        visited[i] = 0;
    }
    /*for(i = 1; i <= n; i++) {
        visited[i] = 0;
    }*/
    visited[1] = 1;
    count = 1;
    mincost = 0;
    printf("\nMINIMUM SPANNING TREE EDGES:\n\n");
    printf("Edge\t\tWeight\n");
    while(count < n) {
        int min = INF;
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                if(cost[i][j] < min && visited[i] && !visited[j]) {
                    min = cost[i][j];
                    u = i; 
                    v = j;
                }   
        printf("%d -- %d\t\t%d\n", u, v, cost[u][v]);
        mincost += cost[u][v];
        visited[v] = 1;
        count++;
    }
    printf("Total MST Cost: %d\n", mincost);
    //getch();
    return 0;
}