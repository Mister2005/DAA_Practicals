#include <stdio.h>
#include <conio.h>

struct Activity {
    int start;
    int finish;
    int id;
};

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

void displayActivities(struct Activity arr[], int n) {
    printf("\nAll activities:\n");
    printf("Activity\tStart Time\tFinish Time\n");
    printf("----------------------------------------\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", arr[i].id, arr[i].start, arr[i].finish);
    }
}

void activitySelection(struct Activity arr[], int n) {
    sortActivities(arr, n);
    
    printf("\nSelected activities (sorted by finish time):\n");
    printf("Activity\tStart Time\tFinish Time\n");
    printf("----------------------------------------\n");
    
    int count = 1;
    int last_finish = arr[0].finish;
    printf("%d\t%d\t\t%d\n", arr[0].id, arr[0].start, arr[0].finish);
    
    for (int i = 1; i < n; i++) {
        if (arr[i].start >= last_finish) {
            printf("%d\t%d\t\t%d\n", arr[i].id, arr[i].start, arr[i].finish);
            last_finish = arr[i].finish;
            count++;
        }
    }
    
    printf("\nTotal activities selected: %d\n", count);
}

int main() {
    //clrscr();
    int n;
    struct Activity arr[100];
    
    printf("Activity Selection Problem Solver\n");
    printf("------------------------------\n\n");
    
    printf("Enter the number of activities (max 100): ");
    scanf("%d", &n);
    
    if(n <= 0 || n > 100) {
        printf("Invalid number of activities!\n");
        //getch();
        return 1;
    }
    
    printf("\nEnter the start and finish time for each activity:\n");
    for(int i = 0; i < n; i++) {
        printf("\nActivity %d:\n", i+1);
        arr[i].id = i+1;
        
        printf("Start time: ");
        scanf("%d", &arr[i].start);
        
        printf("Finish time: ");
        scanf("%d", &arr[i].finish);
        
        while(arr[i].finish <= arr[i].start) {
            printf("Error: Finish time must be greater than start time!\n");
            printf("Enter finish time again: ");
            scanf("%d", &arr[i].finish);
        }
    }
    
    displayActivities(arr, n);
    
    printf("\nFinding optimal selection of activities...\n");
    activitySelection(arr, n);
    
    printf("\nPress any key to exit...");
    //getch();
    return 0;
}