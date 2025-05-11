#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *x;
int n;

void printBoard() 
{
    printf("\nSolution: ");for (int i = 1; i <= n; i++) 
    {
        printf("%d ", x[i]);
    }
    printf("\n");
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            if (x[i] == j) 
            {
                printf("Q ");
            } 
            else 
            {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int place(int k, int i) 
{
    for (int j = 1; j < k; j++) 
    {
        if (x[j] == i || abs(x[j] - i) == abs(k - j)) 
        {
            return 0;
        }
    }
    return 1;
}

void Nqueen(int k) 
{
    for (int i = 1; i <= n; i++) 
    {
        if (place(k, i)) 
        {
            x[k] = i;
            if (k == n) 
            {
                printBoard();
            } 
            else 
            {
                Nqueen(k + 1);
            }
        }
    }
}

int main() 
{
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    x = (int *)malloc((n + 1) * sizeof(int));
    if (x == NULL) 
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Solutions for %d-Queens problem:\n", n);
    Nqueen(1);
    free(x);
    return 0;
}