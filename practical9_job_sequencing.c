#include <stdio.h>
#include <conio.h>
#define MAX 100

typedef struct { 
    int id, deadline, profit; 
} Job;

int compare(Job a, Job b) {
    return a.profit < b.profit;
}

void sortJobs(Job arr[], int n) {
    int i, j;
    Job temp;
    for (i = 0; i < n-1; i++)
        for (j = i+1; j < n; j++)
            if (arr[j].profit > arr[i].profit) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

void jobSequencing(Job arr[], int n) {
    sortJobs(arr, n);
    int result[MAX] = {0}, slot[MAX] = {0}, i, j;
    for (i = 0; i < n; i++) {
        for (j = arr[i].deadline-1; j >= 0; j--) {
            if (!slot[j]) {
                slot[j] = 1;
                result[j] = i;
                break;
            }
        }
    }
    printf("Scheduled jobs:\n");
    for (i = 0; i < n; i++)
        if (slot[i]) printf("%d ", arr[result[i]].id);
    printf("\n");
}

void main() {
    int n;
    Job arr[MAX];
    
    printf("Enter number of jobs (max %d): ", MAX);
    scanf("%d", &n);
    
    if(n <= 0 || n > MAX) {
        printf("Invalid number of jobs!\n");
        return;
    }
    
    printf("\nEnter details for each job:\n");
    int maxDeadline = 0;
    
    for(int i = 0; i < n; i++) {
        printf("\nJob %d:\n", i+1);
        arr[i].id = i+1;
        
        printf("Deadline: ");
        scanf("%d", &arr[i].deadline);
        if(arr[i].deadline <= 0) {
            printf("Invalid deadline! Must be positive.\n");
            return;
        }
        if(arr[i].deadline > maxDeadline) {
            maxDeadline = arr[i].deadline;
        }
        
        printf("Profit: ");
        scanf("%d", &arr[i].profit);
        if(arr[i].profit < 0) {
            printf("Invalid profit! Cannot be negative.\n");
            return;
        }
    }
    
    printf("\nJobs entered:");
    printf("\nJob ID\tDeadline\tProfit");
    for(int i = 0; i < n; i++) {
        printf("\n%d\t%d\t\t%d", 
            arr[i].id, arr[i].deadline, arr[i].profit);
    }
    printf("\n\nMaximum deadline: %d\n", maxDeadline);
    
    jobSequencing(arr, n);
}
