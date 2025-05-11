#include <stdio.h>
#include <conio.h>
#define MAX 100

// Structure to represent a job
struct Job { 
    int id;       // Job identifier
    int deadline; // Deadline of job
    int profit;   // Profit if job is completed
};

// Function to compare jobs for sorting
int compare(struct Job a, struct Job b) {
    return a.profit < b.profit;
}

// Function to sort jobs in descending order of profit
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

// Function to find the optimal sequence of jobs
void jobSequencing(struct Job arr[], int n) {
    // Sort jobs by profit
    sortJobs(arr, n);
    
    // Initialize arrays for tracking
    int result[MAX] = {0};  // To store selected jobs
    int slot[MAX] = {0};    // To track time slots
    int i, j;
    
    // Find a slot for each job starting from the last possible slot
    for (i = 0; i < n; i++) {
        for (j = arr[i].deadline-1; j >= 0; j--) {
            if (!slot[j]) {
                slot[j] = 1;
                result[j] = i;
                break;
            }
        }
    }
    
    // Print selected jobs
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

void main() {
    //clrscr();  // Clear screen for Turbo C
    int n;
    struct Job arr[MAX];
    
    printf("Job Sequencing with Deadlines\n");
    printf("----------------------------\n\n");
    
    printf("Enter number of jobs (max %d): ", MAX);
    scanf("%d", &n);
    
    if(n <= 0 || n > MAX) {
        printf("Invalid number of jobs!\n");
        //getch();
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
            //getch();
            return;
        }
        if(arr[i].deadline > maxDeadline) {
            maxDeadline = arr[i].deadline;
        }
        
        printf("Profit: ");
        scanf("%d", &arr[i].profit);
        if(arr[i].profit < 0) {
            printf("Invalid profit! Cannot be negative.\n");
            //getch();
            return;
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
    //getch();  // Wait for key press in Turbo C
}
