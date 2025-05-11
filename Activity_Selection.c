#include <stdio.h>
#include <conio.h>

// Structure to represent an activity
struct Activity {
    int start;   // Start time of activity
    int finish;  // Finish time of activity
    int id;      // Activity identifier
};

// Function to sort activities by finish time
void sortActivities(struct Activity arr[], int n) {
    int i, j;
    struct Activity temp;
    for (i = 0; i < n-1; i++)
        for (j = i+1; j < n; j++)
            if (arr[i].finish > arr[j].finish) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

// Function to display all activities
void displayActivities(struct Activity arr[], int n) {
    printf("\nAll activities:\n");
    printf("Activity\tStart Time\tFinish Time\n");
    printf("----------------------------------------\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", arr[i].id, arr[i].start, arr[i].finish);
    }
}

// Function to select maximum number of activities
void activitySelection(struct Activity arr[], int n) {
    // Sort activities by finish time
    sortActivities(arr, n);
    
    printf("\nSelected activities (sorted by finish time):\n");
    printf("Activity\tStart Time\tFinish Time\n");
    printf("----------------------------------------\n");
    
    // First activity is always selected
    int count = 1;
    int last_finish = arr[0].finish;
    printf("%d\t%d\t\t%d\n", arr[0].id, arr[0].start, arr[0].finish);
    
    // Consider rest of the activities
    for (int i = 1; i < n; i++) {
        // If this activity has start time greater than
        // or equal to the finish time of previously
        // selected activity, then select it
        if (arr[i].start >= last_finish) {
            printf("%d\t%d\t\t%d\n", arr[i].id, arr[i].start, arr[i].finish);
            last_finish = arr[i].finish;
            count++;
        }
    }
    
    printf("\nTotal activities selected: %d\n", count);
}

void main() {
    //clrscr();  // Clear screen for Turbo C
    int n;
    struct Activity arr[100];  // Maximum 100 activities
    
    printf("Activity Selection Problem Solver\n");
    printf("------------------------------\n\n");
    
    // Get number of activities
    printf("Enter the number of activities (max 100): ");
    scanf("%d", &n);
    
    if(n <= 0 || n > 100) {
        printf("Invalid number of activities!\n");
        //getch();
        return;
    }
    
    // Input activity details
    printf("\nEnter the start and finish time for each activity:\n");
    for(int i = 0; i < n; i++) {
        printf("\nActivity %d:\n", i+1);
        arr[i].id = i+1;  // Assign activity ID
        
        printf("Start time: ");
        scanf("%d", &arr[i].start);
        
        printf("Finish time: ");
        scanf("%d", &arr[i].finish);
        
        // Validate input
        while(arr[i].finish <= arr[i].start) {
            printf("Error: Finish time must be greater than start time!\n");
            printf("Enter finish time again: ");
            scanf("%d", &arr[i].finish);
        }
    }
    
    // Display all activities
    displayActivities(arr, n);
    
    // Find and display optimal selection
    printf("\nFinding optimal selection of activities...\n");
    activitySelection(arr, n);
    
    printf("\nPress any key to exit...");
    //getch();  // Wait for key press in Turbo C
}