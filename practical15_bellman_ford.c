#include <stdio.h>
#include <conio.h>
#define V 5
#define E 8
#define INF 9999

typedef struct { int u, v, w; } Edge;

void bellmanFord(Edge edges[], int src) {
    int dist[V], i, j;
    for (i = 0; i < V; i++) dist[i] = INF;
    dist[src] = 0;
    for (i = 1; i <= V-1; i++)
        for (j = 0; j < E; j++)
            if (dist[edges[j].u] + edges[j].w < dist[edges[j].v])
                dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
    /* Check negative cycles omitted */
    printf("Vertex Distance from Source\n");
    for (i = 0; i < V; i++) printf("%d \t %d\n", i, dist[i]);
}

void main() {
    //clrscr();
    Edge edges[E] = {{0,1,-1},{0,2,4},{1,2,3},{1,3,2},{1,4,2},{3,2,5},{3,1,1},{4,3,-3}};
    bellmanFord(edges, 0);
    //getch();
}
