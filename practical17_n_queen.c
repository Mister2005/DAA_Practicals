#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 20

void printBoard(int *x, int n) {
    printf("\nSolution: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == j) {
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int place(int *x, int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(k - j)) {
            return 0;
        }
    }
    return 1;
}

void Nqueen(int *x, int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (place(x, k, i)) {
            x[k] = i;
            if (k == n) {
                printBoard(x, n);
            } else {
                Nqueen(x, k + 1, n);
            }
        }
    }
}

void main() {
    int n;
    printf("Enter the number of queens (1-%d): ", MAX);
    scanf("%d", &n);
    
    if(n <= 0 || n > MAX) {
        printf("Invalid board size! Please enter a number between 1 and %d\n", MAX);
        return;
    }
    
    int *x = (int *)malloc((n + 1) * sizeof(int));
    if (x == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    printf("Solving %d-Queens problem...\n", n);
    printf("Solutions for %d-Queens problem:\n", n);
    Nqueen(x, 1, n);
    
    free(x);
}
