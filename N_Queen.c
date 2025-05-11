#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#define MAX 20

// Global variables
int *x;  // Array to store the solution (column number for each row)
int n;   // Size of the chess board (n x n)

// Function to print the current board configuration
void printBoard() {
    printf("\nSolution:");
    // Print the column positions
    for (int i = 1; i <= n; i++) {
        printf(" %d", x[i]);
    }
    
    // Print the chess board
    printf("\n\nChess Board Configuration:\n");
    printf("------------------------\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == j) {
                printf("Q ");  // Queen's position
            } else {
                printf(". ");  // Empty position
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a queen can be placed on board[k][i]
int place(int k, int i) {
    // Check previous k-1 rows
    for (int j = 1; j < k; j++) {
        // Check if same column or diagonal
        if (x[j] == i || abs(x[j] - i) == abs(k - j)) {
            return 0;  // Not safe to place queen
        }
    }
    return 1;  // Safe to place queen
}

// Function to solve N Queen problem using backtracking
void Nqueen(int k) {
    // Try placing queen in each column of row k
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {  // If safe to place queen
            x[k] = i;  // Place queen
            
            if (k == n) {  // If all queens are placed
                printBoard();
            } else {
                Nqueen(k + 1);  // Try placing queen in next row
            }
        }
    }
}

void main() {
    //clrscr();  // Clear screen for Turbo C
    
    printf("N-Queens Problem Solver\n");
    printf("---------------------\n\n");
    
    printf("Enter the number of queens (max %d): ", MAX);
    scanf("%d", &n);
    
    // Input validation
    if (n <= 0 || n > MAX) {
        printf("Invalid board size! Please enter a number between 1 and %d\n", MAX);
        //getch();
        return;
    }
    
    // Allocate memory for solution array
    x = (int *)malloc((n + 1) * sizeof(int));
    if (x == NULL) {
        printf("Memory allocation failed!\n");
        //getch();
        return;
    }
    
    printf("\nFinding solutions for %d-Queens problem...\n", n);
    printf("(This might take a while for larger values of n)\n\n");
    
    // Solve N-Queens problem starting from first row
    Nqueen(1);
    
    // Free allocated memory
    free(x);
    
    printf("\nPress any key to exit...");
    //getch();  // Wait for key press in Turbo C
}