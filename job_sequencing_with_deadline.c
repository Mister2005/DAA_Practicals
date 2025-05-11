#include <stdio.h>
#include <conio.h>
#define MAX 100

struct Job { 
    int id;
    int deadline;
    int profit;
};

void sortJobs(struct Job arr[], int n) {
    int i, j;
    struct Job temp;
    for (i = 0; i < n-1; i++)
        for (j = i+1; j < n; j++)
            if (arr[j].profit > arr[i].profit) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

void jobSequencing(struct Job arr[], int n) {
    sortJobs(arr, n);
    
    int result[MAX] = {0};
    int slot[MAX] = {0};
    int i, j;
    
    for (i = 0; i < n; i++) {
        for (j = arr[i].deadline-1; j >= 0; j--) {
            if (!slot[j]) {
                slot[j] = 1;
                result[j] = i;
                break;
            }
        }
    }
    
    printf("Selected jobs in optimal sequence:\n");
    printf("Job\tDeadline\tProfit\n");
    printf("--------------------------------\n");
    int totalProfit = 0;
    for (i = 0; i < n; i++) {
        if (slot[i]) {
            printf("%d\t%d\t\t%d\n", 
                arr[result[i]].id,
                arr[result[i]].deadline,
                arr[result[i]].profit);
            totalProfit += arr[result[i]].profit;
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    int n;
    struct Job arr[MAX];
    
    printf("Job Sequencing with Deadlines\n");
    printf("----------------------------\n\n");
    
    printf("Enter number of jobs (max %d): ", MAX);
    scanf("%d", &n);
    
    if(n <= 0 || n > MAX) {
        printf("Invalid number of jobs!\n");
        return 1;
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
            return 1;
        }
        if(arr[i].deadline > maxDeadline) {
            maxDeadline = arr[i].deadline;
        }
        
        printf("Profit: ");
        scanf("%d", &arr[i].profit);
        if(arr[i].profit < 0) {
            printf("Invalid profit! Cannot be negative.\n");
            return 1;
        }
    }
    
    printf("\nInput Summary:");
    printf("\nJob ID\tDeadline\tProfit");
    printf("\n---------------------------");
    for(int i = 0; i < n; i++) {
        printf("\n%d\t%d\t\t%d", 
            arr[i].id, arr[i].deadline, arr[i].profit);
    }
    printf("\n\nMaximum deadline among all jobs: %d\n\n", maxDeadline);
    
    jobSequencing(arr, n);
    
    printf("\nPress any key to exit...");
    return 0;
}