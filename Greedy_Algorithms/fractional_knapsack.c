#include <stdio.h>
void main(){
    int i, j, n, capacity;
    float ratio[20], profit[20], weight[20], x[20], tp=0;
    int seq[20];
    printf("Enter number of items: ");
    scanf("%d",&n);
    printf("Enter weights and profits:\n");
    for(i=0;i<n;i++){
        scanf("%f %f",&weight[i],&profit[i]);
        ratio[i]=profit[i]/weight[i];
        x[i]=0.0;
        seq[i]=i+1;
    }
    printf("Enter capacity of knapsack: ");
    scanf("%d",&capacity);
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(ratio[i]<ratio[j]){
                float temp=ratio[i]; ratio[i]=ratio[j]; ratio[j]=temp;
                temp=weight[i]; weight[i]=weight[j]; weight[j]=temp;
                temp=profit[i]; profit[i]=profit[j]; profit[j]=temp;
                int temps=seq[i]; seq[i]=seq[j]; seq[j]=temps;
            }
        }
    }
    printf("\nSelection Details:\n");
    printf("----------------\n");
    printf("Seq No.\tRatio\tFraction\n");
    printf("----------------\n");
    for(i=0;i<n;i++){
        if(weight[i]>capacity) break;
        x[i]=1.0;
        tp+=profit[i];
        capacity-=weight[i];
        printf("%d\t%.2f\t%.2f\n",seq[i],ratio[i],x[i]);
    }
    if(i<n){
        x[i]=capacity/weight[i];
        tp+=(x[i]*profit[i]);
        printf("%d\t%.2f\t%.2f\n",seq[i],ratio[i],x[i]);
    }
    printf("----------------\n");
    printf("Total profit: %.2f\n",tp);
}