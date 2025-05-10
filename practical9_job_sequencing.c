#include <stdio.h>
#include <conio.h>
#define MAX 100

typedef struct { int id, deadline, profit; } Job;

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
    //clrscr();
    Job arr[] = {{1,2,100}, {2,1,19}, {3,2,27}, {4,1,25}, {5,3,15}};
    int n = sizeof(arr)/sizeof(arr[0]);
    jobSequencing(arr, n);
    //getch();
}
