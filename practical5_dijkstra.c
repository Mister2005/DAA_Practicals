#include <stdio.h>
#include <conio.h>
#define V 5
#define INF 9999

void displayGraph(int graph[V][V]) {
    int i, j;
    printf("\nThe graph you entered (adjacency matrix):\n");
    printf("   ");
    for(i = 0; i < V; i++)
        printf("%3d ", i);
    printf("\n");
    printf("   ");
    for(i = 0; i < V; i++)
        printf("--- ");
    printf("\n");
    
    for(i = 0; i < V; i++) {
        printf("%d |", i);
        for(j = 0; j < V; j++) {
            printf("%3d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void dijkstra(int graph[V][V], int src) {
    int dist[V], visited[V] = {0}, i, count, u, v;
    for (i = 0; i < V; i++) dist[i] = INF;
    dist[src] = 0;
    for (count = 0; count < V-1; count++) {
        int min = INF, min_index;
        for (v = 0; v < V; v++)
            if (!visited[v] && dist[v] <= min) { min = dist[v]; min_index = v; }
        u = min_index;
        visited[u] = 1;
        for (v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printf("Vertex \t Distance from Source\n");
    for (i = 0; i < V; i++) printf("%d \t\t %d\n", i, dist[i]);
}

void main() {
    //clrscr();
    int graph[V][V];
    int i, j, source;
    
    printf("Enter the adjacency matrix for the graph (%dx%d):\n", V, V);
    printf("(Enter 0 for no edge, and weight for existing edge)\n");
    
    for(i = 0; i < V; i++) {
        for(j = 0; j < V; j++) {
            printf("Enter weight for edge from vertex %d to %d: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
    
    displayGraph(graph);
    
    printf("\nEnter the source vertex (0 to %d): ", V-1);
    scanf("%d", &source);
    
    if(source >= 0 && source < V) {
        dijkstra(graph, source);
    } else {
        printf("Invalid source vertex! Please enter a vertex between 0 and %d\n", V-1);
    }
    //getch();
}