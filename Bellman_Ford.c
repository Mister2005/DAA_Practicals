#include <stdio.h>
#include <conio.h>
#define INF 9999
#define MAX_EDGES 100
#define MAX_VERTICES 50

struct Edge { 
    int u;
    int v;
    int w;
};

void bellmanFord(struct Edge edges[], int V, int E, int src) {
    int dist[MAX_VERTICES];
    int i, j;
    
    printf("\nInitializing distances...\n");
    for (i = 0; i < V; i++) {
        dist[i] = INF;
        printf("Distance to vertex %d = INF\n", i);
    }
    dist[src] = 0;
    printf("Distance to source vertex %d = 0\n", src);
    
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

int main() {
    //clrscr();
    struct Edge edges[MAX_EDGES];
    int V, E, src;
    
    printf("Bellman-Ford Algorithm Implementation\n");
    printf("---------------------------------\n\n");
    
    printf("Enter number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &V);
    
    if (V <= 0 || V > MAX_VERTICES) {
        printf("Invalid number of vertices!\n");
        //getch();
        return 1;
    }
    
    printf("Enter number of edges (max %d): ", MAX_EDGES);
    scanf("%d", &E);
    
    if (E <= 0 || E > MAX_EDGES) {
        printf("Invalid number of edges!\n");
        //getch();
        return 1;
    }
    
    printf("\nEnter edge details (format: source destination weight):\n");
    printf("Example: 0 1 5 means edge from vertex 0 to 1 with weight 5\n\n");
    
    for(int i = 0; i < E; i++) {
        printf("Edge %d: ", i+1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        
        if (edges[i].u < 0 || edges[i].u >= V || 
            edges[i].v < 0 || edges[i].v >= V) {
            printf("Invalid vertex number! Vertices should be from 0 to %d\n", V-1);
            //getch();
            return 1;
        }
    }
    
    printf("\nEnter source vertex (0 to %d): ", V-1);
    scanf("%d", &src);
    
    if (src < 0 || src >= V) {
        printf("Invalid source vertex!\n");
        //getch();
        return 1;
    }
    
    bellmanFord(edges, V, E, src);
    
    printf("\nPress any key to exit...");
    //getch();
    return 0;
}