#include <stdio.h>
#include <conio.h>

typedef struct { int weight, value; float ratio; } Item;

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
    //clrscr();
    Item arr[] = {{10,60,0}, {20,100,0}, {30,120,0}};
    int n = sizeof(arr)/sizeof(arr[0]), W = 50, i;
    for (i = 0; i < n; i++)
        arr[i].ratio = (float)arr[i].value / arr[i].weight;
    fractionalKnapsack(arr, n, W);
    //getch();
}