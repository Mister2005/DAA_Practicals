#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <limits.h>
#define MAX 30

void printOptimalParenthesis(int s[][MAX], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParenthesis(s, i, s[i][j]);
        printOptimalParenthesis(s, s[i][j] + 1, j);
        printf(")");
    }
}

void matrixChainMultiplication(int dimensions[], int n) {
    int m[MAX][MAX] = {0};
    int s[MAX][MAX] = {0};
    int i, j, k, L, cost;
    
    for (i = 1; i < n; i++) {
        m[i][i] = 0;
    }
    
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            
            for (k = i; k <= j - 1; k++) {
                cost = m[i][k] + m[k + 1][j] + 
                       dimensions[i - 1] * dimensions[k] * dimensions[j];
                
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    
    printf("\nResults:\n");
    printf("--------\n");
    printf("Minimum number of multiplications needed: %d\n", m[1][n-1]);
    
    printf("Optimal Parenthesization: ");
    printOptimalParenthesis(s, 1, n-1);
    printf("\n\n");
    
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

int main() {
    int dimensions[MAX], n;
    
    printf("Matrix Chain Multiplication Optimizer\n");
    printf("----------------------------------\n\n");
    
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    
    if(n <= 0 || n > MAX-1) {
        printf("Invalid number of matrices! Should be between 1 and %d\n", MAX-1);
        return 1;
    }
    
    n++; 
    
    printf("\nEnter dimensions:\n");
    printf("For example, if you have matrices A1(10x20) and A2(20x30),\n");
    printf("enter dimensions as: 10 20 30\n\n");
    
    for (int i = 0; i < n; i++) {
        printf("d%d: ", i);
        scanf("%d", &dimensions[i]);
        
        if(dimensions[i] <= 0) {
            printf("Invalid dimension! Must be positive.\n");
            return 1;
        }
    }
    
    printf("\nInput Matrices:\n");
    for(int i = 1; i < n; i++) {
        printf("A%d: %dx%d\n", i, dimensions[i-1], dimensions[i]);
    }
    
    matrixChainMultiplication(dimensions, n);
    
    printf("\nPress any key to exit...");
    return 0;
}