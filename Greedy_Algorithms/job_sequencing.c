#include <stdio.h>
#include <string.h>
int main(){
    int n, i, j, max=0;
    printf("Enter number of jobs: ");
    scanf("%d",&n);
    char job[n];
    int deadline[n], profit[n], result[n];
    printf("Enter job name, deadline and profit:\n");
    for(i=0;i<n;i++){
        scanf(" %c %d %d", &job[i], &deadline[i], &profit[i]);
        if(deadline[i]>max) max = deadline[i];
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(profit[j]<profit[j+1]){
                int tempP = profit[j];
                profit[j] = profit[j+1];
                profit[j+1] = tempP;
                int tempD = deadline[j];
                deadline[j] = deadline[j+1];
                deadline[j+1] = tempD;
                char tempJ = job[j];
                job[j] = job[j+1];
                job[j+1] = tempJ;
            }
        }
    }
    int slot[max];
    for(i=0;i<max;i++) slot[i] = -1;
    for(i=0;i<n;i++){
        for(j=deadline[i]-1;j>=0;j--){
            if(slot[j] == -1){
                slot[j] = i;
                break;
            }
        }
    }
    int finalProfit = 0;
    printf("Scheduled jobs: ");
    for(i=0;i<max;i++){
        if(slot[i] != -1){
            printf("%c ", job[slot[i]]);
            finalProfit += profit[slot[i]];
        }
    }
    printf("\nTotal profit: %d", finalProfit);
    return 0;
}