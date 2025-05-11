#include <stdio.h>
#include <conio.h>
#define MAX 20
#define INF 9999

// Function to find the vertex with minimum key value
int minKey(int key[], int mstSet[], int V) {
    int min = INF, min_index;
    
    // Find vertex with minimum key value from set of vertices not yet included in MST
    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    return min_index;
}

// Function to implement Prim's algorithm
void primMST(int V, int graph[MAX][MAX]) {
    int parent[MAX];    // Array to store constructed MST
    int key[MAX];       // Key values used to pick minimum weight edge
    int mstSet[MAX];    // To represent set of vertices included in MST
    int total_weight = 0;
    
    // Initialize all keys as INFINITE and mstSet[] as false
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }
    
    // First vertex is always the root of MST
    key[0] = 0;       // Make key 0 to pick first vertex
    parent[0] = -1;   // First node is always root of MST
    
    printf("\nBuilding Minimum Spanning Tree:\n");
    printf("-----------------------------\n");
    
    // Construct MST with V vertices
    for (int count = 0; count < V-1; count++) {
        // Pick the minimum key vertex not yet included in MST
        int u = minKey(key, mstSet, V);
        mstSet[u] = 1;  // Add picked vertex to MST
        
        printf("\nAdding vertex %d to MST\n", u);
        
        // Update key values and parent index of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] &&          // If there is an edge
                !mstSet[v] &&           // Vertex not in MST
                graph[u][v] < key[v]) { // Edge weight less than key
                parent[v] = u;
                key[v] = graph[u][v];
                printf("Updated: key[%d] = %d (parent: %d)\n", 
                       v, key[v], parent[v]);
            }
        }
    }
    
    // Print the constructed MST
    printf("\nMinimum Spanning Tree Edges:\n");
    printf("Edge \tWeight\n");
    printf("----------------\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        total_weight += graph[i][parent[i]];
    }
    printf("\nTotal Weight of MST: %d\n", total_weight);
}

void main() {
    //clrscr();  // Clear screen for Turbo C
    int V;
    int graph[MAX][MAX];
    
    printf("Prim's Algorithm - Minimum Spanning Tree\n");
    printf("------------------------------------\n\n");
    
    printf("Enter number of vertices (max %d): ", MAX);
    scanf("%d", &V);
    
    if(V <= 0 || V > MAX) {
        printf("Invalid number of vertices!\n");
        //getch();
        return;
    }
    
    printf("\nEnter the adjacency matrix (%dx%d):\n", V, V);
    printf("(Enter weight for edges, 0 for no edge)\n");
    printf("Example for 3 vertices:\n");
    printf("0 2 3\n2 0 4\n3 4 0\n\n");
    
    // Input the adjacency matrix
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            printf("Enter weight for edge %d-%d: ", i, j);
            scanf("%d", &graph[i][j]);
            if(graph[i][j] < 0) {
                printf("Negative weights not allowed!\n");
                //getch();
                return;
            }
        }
    }
    
    // Print the input graph
    printf("\nThe graph you entered (adjacency matrix):\n");
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    
    // Find and print MST
    primMST(V, graph);
    
    printf("\nPress any key to exit...");
    //getch();  // Wait for key press in Turbo C
}
