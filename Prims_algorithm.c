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
    int parent[MAX];
    int key[MAX];
    int mstSet[MAX];
    int total_weight = 0;
    
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }
    
    key[0] = 0;
    parent[0] = -1;
    
    printf("\nBuilding Minimum Spanning Tree:\n");
    printf("-----------------------------\n");
    
    for (int count = 0; count < V-1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = 1;
        
        printf("\nAdding vertex %d to MST\n", u);
        
        for (int v = 0; v < V; v++) {
            if (graph[u][v] &&
                !mstSet[v] &&
                graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
                printf("Updated: key[%d] = %d (parent: %d)\n", 
                       v, key[v], parent[v]);
            }
        }
    }
    
    printf("\nMinimum Spanning Tree Edges:\n");
    printf("Edge \tWeight\n");
    printf("----------------\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        total_weight += graph[i][parent[i]];
    }
    printf("\nTotal Weight of MST: %d\n", total_weight);
}

int main() {
    int V;
    int graph[MAX][MAX];
    
    printf("Prim's Algorithm - Minimum Spanning Tree\n");
    printf("------------------------------------\n\n");
    
    printf("Enter number of vertices (max %d): ", MAX);
    scanf("%d", &V);
    
    if(V <= 0 || V > MAX) {
        printf("Invalid number of vertices!\n");
        return 1;
    }
    
    printf("\nEnter the adjacency matrix (%dx%d):\n", V, V);
    printf("(Enter weight for edges, 0 for no edge)\n");
    printf("Example for 3 vertices:\n");
    printf("0 2 3\n2 0 4\n3 4 0\n\n");
    
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            printf("Enter weight for edge %d-%d: ", i, j);
            scanf("%d", &graph[i][j]);
            if(graph[i][j] < 0) {
                printf("Negative weights not allowed!\n");
                return 1;
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
    
    printf("\nPress any key to exit...");
    return 0;
}