#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<limits.h>

#define MAX 30
void printOptimalParenthesis(int s[][MAX], int i, int j) 
{
    if (i == j)
        printf("A%d", i);
    else 
    {
        printf("(");
        printOptimalParenthesis(s, i, s[i][j]);
        printOptimalParenthesis(s, s[i][j] + 1, j);
        printf(")");
    }
}
void matrixChainMultiplication(int dimensions[], int n) 
{
    int m[MAX][MAX] = {0};
    int s[MAX][MAX] = {0};
    int i, j, k, L, cost;
    for (i = 1; i < n; i++) 
    {
        m[i][i] = 0;
    }
    for (L = 2; L < n; L++) 
    {
        for (i = 1; i < n - L + 1; i++) 
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;       
            for (k = i; k <= j - 1; k++) 
            {
                cost = m[i][k] + m[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
                if (cost < m[i][j]) 
                {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("\nMinimum number of multiplications: %d\n", m[1][n-1]);
    printf("Optimal Parenthesization: ");
    printOptimalParenthesis(s, 1, n-1);
    printf("\n\n");
    printf("M-table (Cost Table):\n");
    for (i = 1; i < n; i++) 
    {
        for (j = 1; j < n; j++) 
        {
            if (j >= i)
                printf("%d\t", m[i][j]);
            else
                printf("0\t");
        }
        printf("\n");
    }
    printf("\nK-table (Split Points):\n");
    for (i = 1; i < n; i++) 
    {
        for (j = 1; j < n; j++) 
        {
            if (j > i)
                printf("%d\t", s[i][j]);
            else
                printf("0\t");
        }
        printf("\n");
    }
}
int main() 
{
    int dimensions[MAX], n;
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    n++;    
    printf("Enter dimensions:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("d%d: ", i);
        scanf("%d", &dimensions[i]);
    }
    matrixChainMultiplication(dimensions, n);
    return 0;
}