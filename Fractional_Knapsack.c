#include <stdio.h>
#include <conio.h>
#define MAX 100

struct Item { 
    int weight;
    int value;
    float ratio;
};

void sortItems(struct Item arr[], int n) {
    int i, j;
    struct Item temp;
    for (i = 0; i < n-1; i++)
        for (j = i+1; j < n; j++)
            if (arr[j].ratio > arr[i].ratio) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

void fractionalKnapsack(struct Item arr[], int n, int W) {
    sortItems(arr, n);
    
    float used = 0.0;
    float profit = 0.0;
    
    printf("\nSolution Steps:\n");
    printf("-------------\n");
    
    for (int i = 0; i < n; i++) {
        if (used + arr[i].weight <= W) {
            used += arr[i].weight;
            profit += arr[i].value;
            printf("Take 100%% of item with value/weight ratio = %.2f\n", arr[i].ratio);
            printf("Added weight: %d, Added value: %d\n", arr[i].weight, arr[i].value);
        } else {
            float remain = W - used;
            profit += arr[i].ratio * remain;
            printf("Take %.2f%% of item with value/weight ratio = %.2f\n", 
                (remain/arr[i].weight) * 100, arr[i].ratio);
            printf("Added weight: %.2f, Added value: %.2f\n", 
                remain, arr[i].ratio * remain);
            break;
        }
        printf("Current total: Weight = %.2f, Profit = %.2f\n\n", used, profit);
    }
    
    printf("\nFinal Result:\n");
    printf("Maximum profit = %.2f\n", profit);
    printf("Total weight used = %.2f\n", used);
}

int main() {
    //clrscr();
    int n, W;
    struct Item arr[MAX];
    
    printf("Fractional Knapsack Problem Solver\n");
    printf("--------------------------------\n\n");
    
    printf("Enter number of items (max %d): ", MAX);
    scanf("%d", &n);
    
    if(n <= 0 || n > MAX) {
        printf("Invalid number of items!\n");
        //getch();
        return 1;
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
            //getch();
            return 1;
        }
        
        arr[i].ratio = (float)arr[i].value / arr[i].weight;
    }
    
    printf("\nEnter knapsack capacity: ");
    scanf("%d", &W);
    
    if(W <= 0) {
        printf("Invalid capacity! Must be positive.\n");
        //getch();
        return 1;
    }
    
    printf("\nInput Summary:");
    printf("\nItem\tWeight\tValue\tValue/Weight");
    printf("\n------------------------------------");
    for(int i = 0; i < n; i++) {
        printf("\n%d\t%d\t%d\t%.2f", 
            i+1, arr[i].weight, arr[i].value, arr[i].ratio);
    }
    printf("\nKnapsack capacity: %d\n", W);
    
    fractionalKnapsack(arr, n, W);
    
    printf("\nPress any key to exit...");
    //getch();
    return 0;
}