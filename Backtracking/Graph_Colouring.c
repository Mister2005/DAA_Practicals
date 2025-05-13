#include <stdio.h>
#define MAXV 20

int V; // number of vertices
int m; // number of colors
int graph[MAXV][MAXV];
int color[MAXV];

void printSolution() {
    int i;
    for(i = 0; i < V; i++)
        printf("%d ", color[i]);
    printf("\n");
}

int isSafe(int v, int c) {
    int i;
    for(i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c)
            return 0;
    }
    return 1;
}

void graphColoring(int v) {
    if (v == V) {
        printSolution();
        return;
    }
    int c;
    for(c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            color[v] = c;
            graphColoring(v + 1);
            color[v] = 0;
        }
    }
}

int main() {
    int e, i, j, src, dest;
    //clrscr();
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    for(i = 0; i < V; i++)
        for(j = 0; j < V; j++)
            graph[i][j] = 0;
    for(i = 0; i < e; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &src, &dest);
        graph[src][dest] = graph[dest][src] = 1;
    }
    printf("Enter number of colors: ");
    scanf("%d", &m);
    for(i = 0; i < V; i++)
        color[i] = 0;
    graphColoring(0);
    //getch();
    return 0;
}