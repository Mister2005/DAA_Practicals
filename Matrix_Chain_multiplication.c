#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <limits.h>
#define MAX 30

// Function to print the optimal parenthesization
void printOptimalParenthesis(int s[][MAX], int i, int j) {
    if (i == j) {
        printf("A%d", i);  // Single matrix
    } else {
        printf("(");  // Open parenthesis
        printOptimalParenthesis(s, i, s[i][j]);
        printOptimalParenthesis(s, s[i][j] + 1, j);
        printf(")");  // Close parenthesis
    }
}

// Function to implement Matrix Chain Multiplication using dynamic programming
void matrixChainMultiplication(int dimensions[], int n) {
    int m[MAX][MAX] = {0};  // Cost table
    int s[MAX][MAX] = {0};  // Split points table
    int i, j, k, L, cost;
    
    // Initialize diagonal elements to 0 (single matrix multiplication cost)
    for (i = 1; i < n; i++) {
        m[i][i] = 0;
    }
    
    // L is chain length (number of matrices in the chain)
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;  // Initialize with infinity
            
            // Try all possible split points between i and j
            for (k = i; k <= j - 1; k++) {
                cost = m[i][k] + m[k + 1][j] + 
                       dimensions[i - 1] * dimensions[k] * dimensions[j];
                
                // Update if this cost is less than current minimum
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;  // Save the split point
                }
            }
        }
    }
    
    // Print results
    printf("\nResults:\n");
    printf("--------\n");
    printf("Minimum number of multiplications needed: %d\n", m[1][n-1]);
    
    printf("Optimal Parenthesization: ");
    printOptimalParenthesis(s, 1, n-1);
    printf("\n\n");
    
    // Print the cost table (M-table)
    printf("Cost Table (M-table):\n");
    printf("-------------------\n");
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            if (j >= i)
                printf("%6d ", m[i][j]);
            else
                printf("%6d ", 0);
        }
        printf("\n");
    }
    
    // Print the split points table (K-table)
    printf("\nSplit Points Table (K-table):\n");
    printf("---------------------------\n");
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            if (j > i)
                printf("%6d ", s[i][j]);
            else
                printf("%6d ", 0);
        }
        printf("\n");
    }
}

void main() {
    //clrscr();  // Clear screen for Turbo C
    int dimensions[MAX], n;
    
    printf("Matrix Chain Multiplication Optimizer\n");
    printf("----------------------------------\n\n");
    
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    
    if(n <= 0 || n > MAX-1) {
        printf("Invalid number of matrices! Should be between 1 and %d\n", MAX-1);
        //getch();
        return;
    }
    
    // We need n+1 dimensions for n matrices
    n++; 
    
    printf("\nEnter dimensions:\n");
    printf("For example, if you have matrices A1(10x20) and A2(20x30),\n");
    printf("enter dimensions as: 10 20 30\n\n");
    
    for (int i = 0; i < n; i++) {
        printf("d%d: ", i);
        scanf("%d", &dimensions[i]);
        
        if(dimensions[i] <= 0) {
            printf("Invalid dimension! Must be positive.\n");
            //getch();
            return;
        }
    }
    
    // Print input matrices
    printf("\nInput Matrices:\n");
    for(int i = 1; i < n; i++) {
        printf("A%d: %dx%d\n", i, dimensions[i-1], dimensions[i]);
    }
    
    // Calculate optimal multiplication sequence
    matrixChainMultiplication(dimensions, n);
    
    printf("\nPress any key to exit...");
    //getch();  // Wait for key press in Turbo C
}