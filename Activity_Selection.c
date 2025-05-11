#include <stdio.h>
#include <conio.h>

typedef struct { int start, finish; } Activity;

int compare(Activity a, Activity b) {
    return a.finish > b.finish;
}

void sortActivities(Activity arr[], int n) {
    int i, j;
    Activity temp;
    for (i = 0; i < n-1; i++)
        for (j = i+1; j < n; j++)
            if (arr[i].finish > arr[j].finish) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

void displayActivities(Activity arr[], int n) {
    printf("\nAll activities:\n");
    printf("Activity No.\tStart Time\tFinish Time\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\n", i+1, arr[i].start, arr[i].finish);
    }
    printf("\n");
}

void activitySelection(Activity arr[], int n) {
    sortActivities(arr, n);
    printf("\nSelected activities (after sorting by finish time):\n");
    printf("Activity No.\tStart Time\tFinish Time\n");
    int last_finish = 0, i;
    int count = 0;
    for (i = 0; i < n; i++) {
        if (arr[i].start >= last_finish) {
            printf("%d\t\t%d\t\t%d\n", ++count, arr[i].start, arr[i].finish);
            last_finish = arr[i].finish;
        }
    }
}

void main() {
    //clrscr();
    int n, i;
    Activity arr[100];  // assuming maximum 100 activities
    
    printf("Enter the number of activities: ");
    scanf("%d", &n);
    
    printf("\nEnter the start and finish time for each activity:\n");
    for(i = 0; i < n; i++) {
        printf("Activity %d:\n", i+1);
        printf("Start time: ");
        scanf("%d", &arr[i].start);
        printf("Finish time: ");
        scanf("%d", &arr[i].finish);
        
        // Validate that finish time is after start time
        while(arr[i].finish <= arr[i].start) {
            printf("Error: Finish time must be greater than start time!\n");
            printf("Enter finish time again: ");
            scanf("%d", &arr[i].finish);
        }
    }
    
    displayActivities(arr, n);
    activitySelection(arr, n);
    //getch();
}