#include <stdio.h>
#include <conio.h>
#define V 5
#define INF 9999

int minKey(int key[], int mstSet[]) {
    int min = INF, min_index, v;
    for (v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min) { min = key[v]; min_index = v; }
    return min_index;
}

void primMST(int graph[V][V]) {
    int parent[V], key[V], mstSet[V] = {0}, i, count, u, v;
    for (i = 0; i < V; i++) key[i] = INF;
    key[0] = 0;
    parent[0] = -1;
    for (count = 0; count < V-1; count++) {
        u = minKey(key, mstSet);
        mstSet[u] = 1;
        for (v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }
    printf("Edge \tWeight\n");
    for (i = 1; i < V; i++)
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
}

void main() {
    //clrscr();
    int graph[V][V] = {{0,2,0,6,0},{2,0,3,8,5},{0,3,0,0,7},{6,8,0,0,9},{0,5,7,9,0}};
    primMST(graph);
    //getch();
}
