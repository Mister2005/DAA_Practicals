#include <stdio.h>
#include <conio.h>
#define MAX 20
#define INF 9999

int minKey(int key[], int mstSet[], int V) {
    int min = INF, min_index;
    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min) { 
            min = key[v]; 
            min_index = v; 
        }
    return min_index;
}

void primMST(int V, int graph[MAX][MAX]) {
    int parent[MAX], key[MAX], mstSet[MAX] = {0}, i, count, u, v;
    int total_weight = 0;
    
    for (i = 0; i < V; i++) key[i] = INF;
    key[0] = 0;
    parent[0] = -1;
    
    for (count = 0; count < V-1; count++) {
        u = minKey(key, mstSet, V);
        mstSet[u] = 1;
        for (v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }
    
    printf("\nMinimum Spanning Tree Edges:\n");
    printf("Edge \tWeight\n");
    for (i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        total_weight += graph[i][parent[i]];
    }
    printf("\nTotal Weight of MST: %d\n", total_weight);
}

void main() {
    int V;
    int graph[MAX][MAX];
    
    printf("Enter number of vertices (max %d): ", MAX);
    scanf("%d", &V);
    
    if(V <= 0 || V > MAX) {
        printf("Invalid number of vertices!\n");
        return;
    }
    
    printf("\nEnter the adjacency matrix (%dx%d):\n", V, V);
    printf("(Enter weight for edges, 0 for no edge)\n");
    
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            printf("Enter weight for edge %d-%d: ", i, j);
            scanf("%d", &graph[i][j]);
            if(graph[i][j] < 0) {
                printf("Negative weights not allowed!\n");
                return;
            }
        }
    }
    
    printf("\nThe graph you entered (adjacency matrix):\n");
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    
    primMST(V, graph);
}
