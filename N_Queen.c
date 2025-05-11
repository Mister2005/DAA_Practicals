#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#define MAX 20

int *x;
int n;

void printBoard() {
    printf("\nSolution:");
    for (int i = 1; i <= n; i++) {
        printf(" %d", x[i]);
    }
    
    printf("\n\nChess Board Configuration:\n");
    printf("------------------------\n");
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

int place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(k - j)) {
            return 0;
        }
    }
    return 1;
}

void Nqueen(int k) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;
            
            if (k == n) {
                printBoard();
            } else {
                Nqueen(k + 1);
            }
        }
    }
}

int main() {
    //clrscr();
    
    printf("N-Queens Problem Solver\n");
    printf("---------------------\n\n");
    
    printf("Enter the number of queens (max %d): ", MAX);
    scanf("%d", &n);
    
    if (n <= 0 || n > MAX) {
        printf("Invalid board size! Please enter a number between 1 and %d\n", MAX);
        //getch();
        return 1;
    }
    
    x = (int *)malloc((n + 1) * sizeof(int));
    if (x == NULL) {
        printf("Memory allocation failed!\n");
        //getch();
        return 1;
    }
    
    printf("\nFinding solutions for %d-Queens problem...\n", n);
    printf("(This might take a while for larger values of n)\n\n");
    
    Nqueen(1);
    
    free(x);
    
    printf("\nPress any key to exit...");
    //getch();
    return 0;
}