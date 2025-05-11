#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <conio.h>

int minDistanceVertex(int distance[], bool visited[], int V) {
    int min = INT_MAX;
    int min_index = -1;
    
    for (int v = 0; v < V; v++) {
        if (visited[v] == false && distance[v] <= min) {
            min = distance[v];
            min_index = v;
        }
    }
    return min_index;
}

void printPath(int parent[], int dest, char vertices[]) {
    if (parent[dest] == -1) {
        return;
    }
    printPath(parent, parent[dest], vertices);
    printf(" -> %c", vertices[dest]);
}

void printResult(int src, int dest, int distance[], int parent[], char vertices[]) {
    printf("\nShortest Path from %c to %c:\n", vertices[src], vertices[dest]);
    printf("Path: %c", vertices[src]);
    printPath(parent, dest, vertices);
    printf("\nTotal Distance: %d\n", distance[dest]);
}

void dijkstra(int **graph, int src, int dest, int V, char vertices[]) {
    int *distance = (int *)malloc(V * sizeof(int));
    bool *visited = (bool *)malloc(V * sizeof(bool));
    int *parent = (int *)malloc(V * sizeof(int));
    
    for (int i = 0; i < V; i++) {
        distance[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }
    
    distance[src] = 0;
    
    printf("\nExecuting Dijkstra's Algorithm...\n");
    printf("------------------------------\n");
    
    for (int count = 0; count < V - 1; count++) {
        int u = minDistanceVertex(distance, visited, V);
        if (u == dest) {
            break;
        }
            
        visited[u] = true;
        printf("\nProcessing vertex %c:\n", vertices[u]);
        
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && 
                distance[u] != INT_MAX && 
                distance[u] + graph[u][v] < distance[v]) {
                
                distance[v] = distance[u] + graph[u][v];
                parent[v] = u;
                printf("Updated: Distance to %c = %d (via %c)\n", 
                    vertices[v], distance[v], vertices[u]);
            }
        }
    }
    
    printResult(src, dest, distance, parent, vertices);
    
    free(distance);
    free(visited);
    free(parent);
}

int main() {
    //clrscr();
    int V;
    printf("Dijkstra's Shortest Path Algorithm\n");
    printf("--------------------------------\n\n");
    
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    
    if(V <= 0) {
        printf("Invalid number of vertices!\n");
        //getch();
        return 1;
    }
    
    char *vertices = (char *)malloc(V * sizeof(char));
    printf("Enter the names of vertices (single characters): ");
    getchar();
    for (int i = 0; i < V; i++) {
        scanf("%c", &vertices[i]);
        getchar();
    }
    
    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph[i] = (int *)malloc(V * sizeof(int));
    }
    
    printf("\nEnter the distance matrix (%d x %d):\n", V, V);
    printf("(Enter 0 for no connection, positive value for distance)\n");
    
    for (int i = 0; i < V; i++) {
        printf("Enter row %d: ", i);
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
            if(graph[i][j] < 0) {
                printf("Error: Negative distances not allowed!\n");
                //getch();
                return 1;
            }
        }
    }
    
    printf("\nThe distance graph is:\n");
    printf("  ");
    for (int i = 0; i < V; i++) {
        printf("%c ", vertices[i]);
    }
    printf("\n");
    
    for (int i = 0; i < V; i++) {
        printf("%c ", vertices[i]);
        for (int j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    
    int choice = 1;
    while (choice == 1) {
        char srcChar, destChar;
        int src = -1, dest = -1;
        
        printf("\nEnter the source vertex: ");
        getchar();
        scanf("%c", &srcChar);
        
        printf("Enter the destination vertex: ");
        getchar();
        scanf("%c", &destChar);
        
        for (int i = 0; i < V; i++) {
            if (vertices[i] == srcChar) src = i;
            if (vertices[i] == destChar) dest = i;
        }
        
        if (src == -1 || dest == -1) {
            printf("Invalid source or destination vertex!\n");
        } else {
            dijkstra(graph, src, dest, V, vertices);
        }
        
        printf("\nDo you want to find another path? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    }
    
    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);
    free(vertices);
    
    printf("\nPress any key to exit...");
    //getch();
    return 0;
}