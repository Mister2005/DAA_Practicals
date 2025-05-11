#include <stdio.h>
#include <conio.h>
#define INF 9999

typedef struct { int u, v, w; } Edge;

void bellmanFord(Edge edges[], int V, int E, int src) {
    int dist[100], i, j;
    
    for (i = 0; i < V; i++) 
        dist[i] = INF;
    dist[src] = 0;
    
    for (i = 1; i <= V-1; i++)
        for (j = 0; j < E; j++)
            if (dist[edges[j].u] + edges[j].w < dist[edges[j].v])
                dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
    
    for (j = 0; j < E; j++) {
        if (dist[edges[j].u] + edges[j].w < dist[edges[j].v]) {
            printf("\nNegative weight cycle detected!\n");
            return;
        }
    }
    
    printf("\nVertex\tDistance from Source\n");
    for (i = 0; i < V; i++) 
        printf("%d\t%d\n", i, dist[i]);
}

void main() {
    Edge edges[100];  // Maximum 100 edges
    int V, E, src, i;
    
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    
    printf("Enter number of edges: ");
    scanf("%d", &E);
    
    printf("\nEnter edge details (source destination weight):\n");
    for(i = 0; i < E; i++) {
        printf("Edge %d: ", i+1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    
    printf("\nEnter source vertex: ");
    scanf("%d", &src);
    bellmanFord(edges, V, E, src);
}