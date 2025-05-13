#include <stdio.h>
#define MAX 10
#define INF 9999

int parent[MAX];

void printLine(int n) {
    for(int i = 0; i < n; i++) printf("-");
    printf("\n");
}

int find(int i) {
    if(parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

void union_sets(int i, int j) {
    parent[find(i)] = find(j);
}

int main() {
    int G[MAX][MAX], n, i, j, ne = 0, mincost = 0, u, v;
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
        }
    }

    for(i = 1; i <= n; i++)
        parent[i] = i;

    printf("\nMINIMUM SPANNING TREE EDGES:\n");
    printLine(40);
    printf("Edge\t\tWeight\n");
    printLine(40);

    while(ne < n - 1) {
        int min = INF;
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                if(G[i][j] < min && G[i][j] != 0) {
                    min = G[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if(find(u) != find(v)) {
            printf("%d -- %d\t\t%d\n", u, v, min);
            mincost += min;
            union_sets(u, v);
            ne++;
        }
        G[u][v] = G[v][u] = INF;
    }

    printLine(40);
    printf("Total MST Cost: %d\n", mincost);
    printLine(40);
    //getch();
    return 0;
}