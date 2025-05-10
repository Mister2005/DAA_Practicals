#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define INF 999999

void printOptimalParens(int **s, int i, int j) {
    if (i == j)
        printf("A%d", i);
    else {
        printf("(");
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        printf(")");
    }
}

// Function to display the M table (costs)
void displayTable(int **m, int n) {
    printf("\nCost Table (M):\n");
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            if(j >= i)
                printf("%d\t", m[i][j]);
            else
                printf("\t");
        }
        printf("\n");
    }
}

void matrixChain(int *p, int n) {
    n = n + 1; // Adjusting for dimension array size
    
    // Dynamically allocate memory for tables
    int **m = (int **)malloc(n * sizeof(int *));
    int **s = (int **)malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++) {
        m[i] = (int *)malloc(n * sizeof(int));
        s[i] = (int *)malloc(n * sizeof(int));
    }

    // Initialize tables
    for(int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n-L+1; i++) {
            int j = i+L-1;
            m[i][j] = INF;
            for (int k = i; k <= j-1; k++) {
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    // Display results
    printf("\nOptimal number of multiplications: %d\n", m[1][n-1]);
    
    // Display parenthesization
    printf("\nOptimal Parenthesization: ");
    printOptimalParens(s, 1, n-1);
    printf("\n");
    
    // Display the cost table
    displayTable(m, n);

    // Free allocated memory
    for(int i = 0; i < n; i++) {
        free(m[i]);
        free(s[i]);
    }
    free(m);
    free(s);
}

void main() {
    //clrscr();
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    
    if(n < 2) {
        printf("At least 2 matrices are needed for multiplication!\n");
        return;
    }

    int *dimensions = (int *)malloc((n + 1) * sizeof(int));
    printf("\nEnter the dimensions:\n");
    for(int i = 0; i <= n; i++) {
        if(i == 0)
            printf("Enter dimension %d (rows of first matrix): ", i+1);
        else if(i == n)
            printf("Enter dimension %d (columns of last matrix): ", i+1);
        else
            printf("Enter dimension %d (columns of matrix %d, rows of matrix %d): ", i+1, i, i+1);
        
        scanf("%d", &dimensions[i]);
        
        if(dimensions[i] <= 0) {
            printf("Dimensions must be positive integers!\n");
            free(dimensions);
            return;
        }
    }

    printf("\nMatrices are: \n");
    for(int i = 0; i < n; i++) {
        printf("Matrix A%d: %d x %d\n", i+1, dimensions[i], dimensions[i+1]);
    }

    matrixChain(dimensions, n);
    free(dimensions);
    //getch();
}
