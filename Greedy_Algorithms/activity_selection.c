#include <stdio.h>
int main(){
    int n, i, j, last, count=0;
    printf("Enter number of activities: ");
    scanf("%d",&n);
    int s[n], f[n], activity[n];
    printf("Enter start and finish times:\n");
    for(i=0;i<n;i++){
        scanf("%d %d",&s[i],&f[i]);
        activity[i]=i+1;
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(f[j]>f[j+1]){
                int temp=f[j];
                f[j]=f[j+1];
                f[j+1]=temp;
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
                temp=activity[j];
                activity[j]=activity[j+1];
                activity[j+1]=temp;
            }
        }
    }
    printf("\nActivities after sorting by finish time:\n");
    printf("------------------------------------------\n");
    printf("Activity    Start Time    Finish Time\n");
    printf("------------------------------------------\n");
    for(i=0;i<n;i++){
        printf("%-11d%-13d%d\n",activity[i],s[i],f[i]);
    }
    printf("\nSelected Activities:\n");
    printf("------------------------------------------\n");
    printf("Activity    Start Time    Finish Time\n");
    printf("------------------------------------------\n");
    i=0;
    printf("%-11d%-13d%d\n",activity[i],s[i],f[i]);
    last=f[i];
    count=1;
    for(j=1;j<n;j++){
        if(s[j]>=last){
            printf("%-11d%-13d%d\n",activity[j],s[j],f[j]);
            last=f[j];
            count++;
        }
    }
    printf("------------------------------------------\n");
    printf("Number of activities selected: %d\n",count);
    return 0;
}