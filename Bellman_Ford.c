#include <stdio.h>
#include <conio.h>
#define INF 9999
#define MAX_EDGES 100
#define MAX_VERTICES 50

// Structure to represent an edge in the graph
struct Edge { 
    int u;  // Source vertex
    int v;  // Destination vertex
    int w;  // Weight of edge
};

// Function to implement Bellman-Ford Algorithm
void bellmanFord(struct Edge edges[], int V, int E, int src) {
    int dist[MAX_VERTICES];  // Array to store shortest distances
    int i, j;
    
    // Step 1: Initialize distances
    printf("\nInitializing distances...\n");
    for (i = 0; i < V; i++) {
        dist[i] = INF;
        printf("Distance to vertex %d = INF\n", i);
    }
    dist[src] = 0;
    printf("Distance to source vertex %d = 0\n", src);
    
    // Step 2: Relax all edges |V| - 1 times
    printf("\nRelaxing edges...\n");
    for (i = 1; i <= V-1; i++) {
        printf("\nIteration %d:\n", i);
        for (j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                printf("Updated: Distance to vertex %d = %d via vertex %d\n", 
                    v, dist[v], u);
            }
        }
    }
    
    // Step 3: Check for negative weight cycles
    printf("\nChecking for negative weight cycles...\n");
    for (j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("\nERROR: Graph contains negative weight cycle!\n");
            printf("Edge %d->%d with weight %d is part of a negative cycle\n", 
                u, v, w);
            return;
        }
    }
    
    // Print results
    printf("\nFinal Shortest Distances:\n");
    printf("------------------------\n");
    printf("Vertex\tDistance from Source\n");
    for (i = 0; i < V; i++) {
        if (dist[i] == INF)
            printf("%d\tINF (Not reachable)\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }
}

void main() {
    //clrscr();  // Clear screen for Turbo C
    struct Edge edges[MAX_EDGES];
    int V, E, src, i;
    
    printf("Bellman-Ford Algorithm Implementation\n");
    printf("---------------------------------\n\n");
    
    printf("Enter number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &V);
    
    if (V <= 0 || V > MAX_VERTICES) {
        printf("Invalid number of vertices!\n");
        //getch();
        return;
    }
    
    printf("Enter number of edges (max %d): ", MAX_EDGES);
    scanf("%d", &E);
    
    if (E <= 0 || E > MAX_EDGES) {
        printf("Invalid number of edges!\n");
        //getch();
        return;
    }
    
    printf("\nEnter edge details (format: source destination weight):\n");
    printf("Example: 0 1 5 means edge from vertex 0 to 1 with weight 5\n\n");
    
    for(i = 0; i < E; i++) {
        printf("Edge %d: ", i+1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        
        // Validate vertex numbers
        if (edges[i].u < 0 || edges[i].u >= V || 
            edges[i].v < 0 || edges[i].v >= V) {
            printf("Invalid vertex number! Vertices should be from 0 to %d\n", V-1);
            //getch();
            return;
        }
    }
    
    printf("\nEnter source vertex (0 to %d): ", V-1);
    scanf("%d", &src);
    
    if (src < 0 || src >= V) {
        printf("Invalid source vertex!\n");
        //getch();
        return;
    }
    
    bellmanFord(edges, V, E, src);
    
    printf("\nPress any key to exit...");
    //getch();  // Wait for key press in Turbo C
}