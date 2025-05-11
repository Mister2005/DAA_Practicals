#include <stdio.h>
#include <conio.h>
#define MAX 100

typedef struct { 
    int weight, value; 
    float ratio; 
} Item;

void sortItems(Item arr[], int n) {
    int i, j;
    Item temp;
    for (i = 0; i < n-1; i++)
        for (j = i+1; j < n; j++)
            if (arr[j].ratio > arr[i].ratio) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

void fractionalKnapsack(Item arr[], int n, int W) {
    sortItems(arr, n);
    int i;
    float used = 0.0, profit = 0.0;
    for (i = 0; i < n; i++) {
        if (used + arr[i].weight <= W) {
            used += arr[i].weight;
            profit += arr[i].value;
        } else {
            int remain = W - used;
            profit += arr[i].ratio * remain;
            break;
        }
    }
    printf("Max profit = %.2f\n", profit);
}

void main() {
    int n, W;
    Item arr[MAX];
    
    printf("Enter number of items (max %d): ", MAX);
    scanf("%d", &n);
    
    if(n <= 0 || n > MAX) {
        printf("Invalid number of items!\n");
        return;
    }
    
    printf("\nEnter details for each item:\n");
    for(int i = 0; i < n; i++) {
        printf("\nItem %d:\n", i+1);
        printf("Weight: ");
        scanf("%d", &arr[i].weight);
        printf("Value: ");
        scanf("%d", &arr[i].value);
        if(arr[i].weight <= 0 || arr[i].value < 0) {
            printf("Invalid input! Weight must be positive and value non-negative.\n");
            return;
        }
        arr[i].ratio = (float)arr[i].value / arr[i].weight;
    }
    
    printf("\nEnter knapsack capacity: ");
    scanf("%d", &W);
    
    if(W <= 0) {
        printf("Invalid capacity! Must be positive.\n");
        return;
    }
    
    printf("\nItems entered:");
    printf("\nItem\tWeight\tValue\tValue/Weight");
    for(int i = 0; i < n; i++) {
        printf("\n%d\t%d\t%d\t%.2f", 
            i+1, arr[i].weight, arr[i].value, arr[i].ratio);
    }
    printf("\nKnapsack capacity: %d\n", W);
    
    fractionalKnapsack(arr, n, W);
}