#include <stdio.h>
#include <conio.h>
#include <limits.h>
#define INF INT_MAX

void printMatrix(int vertices, int dist[vertices][vertices]) {
    printf("\n+");
    for(int i = 0; i < vertices; i++) printf("--------+");
    printf("\n");
    
    for(int i = 0; i < vertices; i++) {
        printf("|");
        for(int j = 0; j < vertices; j++) {
            if(dist[i][j] == INF)
                printf(" INF    |");
            else
                printf(" %-6d |", dist[i][j]);
        }
        printf("\n+");
        for(int j = 0; j < vertices; j++) printf("--------+");
        printf("\n");
    }
}

void floydWarshall(int vertices, int dist[vertices][vertices]) {
    printf("\nExecuting Floyd Warshall Algorithm...\n");
    for (int k = 0; k < vertices; k++) {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && 
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void main() {
    int vertices;
    //clrscr();

    printf("Floyd Warshall Algorithm - All Pairs Shortest Path\n");
    printf("------------------------------------------------\n\n");
    
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    int dist[vertices][vertices];
    
    printf("\nEnter the weighted adjacency matrix:\n");
    printf("(Enter %d for no direct edge/INF)\n\n", INF);
    
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            printf("Enter distance from vertex %d to %d: ", i, j);
            scanf("%d", &dist[i][j]);
        }
    }
    
    printf("\nInput Distance Matrix:");
    printMatrix(vertices, dist);
    
    floydWarshall(vertices, dist);
    
    printf("\nShortest Path Matrix:");
    printMatrix(vertices, dist);
    
    printf("\nPress any key to exit...");
    //getch();
}
