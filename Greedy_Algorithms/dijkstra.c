#include <stdio.h>
#define INF 99
int main(){
    int G[10][10], i, j, n, u, v, count, w, dist[10], visited[10], from[10], path[10], pathLen;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d", &G[i][j]);
    for(i=1;i<=n;i++){
        dist[i]=INF;
        visited[i]=0;
        from[i]=0;
    }
    printf("Enter source vertex: ");
    scanf("%d",&u);
    dist[u]=0;
    visited[u]=1;
    count=1;
    while(count<n){
        for(v=1;v<=n;v++)
            if(G[u][v]!=INF && !visited[v])
                if(dist[u]+G[u][v] < dist[v]){
                    dist[v]=dist[u]+G[u][v];
                    from[v]=u;
                }
        w=INF;
        for(i=1;i<=n;i++)
            if(!visited[i] && dist[i]<w){
                w=dist[i];
                u=i;
            }
        visited[u]=1;
        count++;
    }
    printf("\nVertex\tDistance\tPath\n");
    printf("--------------------------------\n");
    for(i=1;i<=n;i++){
        printf("%d\t%d\t\t", i, dist[i]);
        pathLen=0;
        j=i;
        while(j!=0){
            path[pathLen++]=j;
            j=from[j];
        }
        for(j=pathLen-1;j>0;j--)
            printf("%d->", path[j]);
        printf("%d\n", path[0]);
    }
    printf("--------------------------------\n");
    return 0;
}