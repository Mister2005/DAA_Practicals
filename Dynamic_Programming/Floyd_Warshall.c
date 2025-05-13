#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define INF 9999
#define V 20

void floydWarshall(int dist[][V], int n) {
    int i, j, k;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && 
                    (dist[i][k] + dist[k][j] < dist[i][j]))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}
void printMatrix(int dist[][V], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d   ", dist[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int n, i, j;
    int graph[V][V];
    printf("Enter number of vertices (max 20): ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix (Enter INF for infinity):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            char input[5];
            scanf("%s", input);
            if (strcmp(input, "INF") == 0)
                graph[i][j] = INF;
            else
                graph[i][j] = atoi(input);
        }
    }
    floydWarshall(graph, n);
    printf("\nShortest distances matrix:\n");
    printMatrix(graph, n);
    return 0;
}