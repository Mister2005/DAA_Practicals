#include <stdio.h>
#include <conio.h>
#define MAX 100
#define INF __INT_MAX__

int m[MAX][MAX], s[MAX][MAX];
void MatrixChainOrder(int p[], int n) {
    int i, j, k, L, q;
    for (i = 1; i < n; i++)
        m[i][i] = 0;
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INF;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}
void PrintOptimalParens(int i, int j) {
    if (i == j)
        printf("A%d", i);
    else {
        printf("(");
        PrintOptimalParens(i, s[i][j]);
        PrintOptimalParens(s[i][j] + 1, j);
        printf(")");
    }
}
int main() {
    int size;
    //clrscr();
    printf("Enter number of matrices: ");
    scanf("%d", &size);
    size++;
    int arr[MAX];
    printf("Enter dimensions: ");
    for(int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    MatrixChainOrder(arr, size);
    printf("Optimal Parenthesization: ");
    PrintOptimalParens(1, size - 1);
    //getch();
    return 0;
}