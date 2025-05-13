#include <stdio.h>
#include <string.h>
#include <conio.h>
#define MAX 100
#define DIAG 'D'
#define UP   'U'
#define LEFT 'L'

int main() {
    //clrscr();
    char X[MAX+1], Y[MAX+1];
    int C[MAX+1][MAX+1];
    char B[MAX+1][MAX+1];
    int m, n, i, j;
    printf("Enter first string (max %d chars): ", MAX);
    scanf("%s", X);
    printf("Enter second string (max %d chars): ", MAX);
    scanf("%s", Y);
    m = strlen(X);
    n = strlen(Y);
    for (i = 0; i <= m; i++) {
        C[i][0] = 0;
    }
    for (j = 0; j <= n; j++) {
        C[0][j] = 0;
    }
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (X[i-1] == Y[j-1]) {
                C[i][j] = C[i-1][j-1] + 1;
                B[i][j] = DIAG;
            } else if (C[i-1][j] >= C[i][j-1]) {
                C[i][j] = C[i-1][j];
                B[i][j] = UP;
            } else {
                C[i][j] = C[i][j-1];
                B[i][j] = LEFT;
            }
        }
    }
    char lcsStr[MAX+1];
    int index = C[m][n];
    lcsStr[index] = '\0';
    i = m; 
    j = n;
    while (i > 0 && j > 0) {
        if (B[i][j] == DIAG) {
            lcsStr[--index] = X[i-1];
            i--; j--;
        } else if (B[i][j] == UP) {
            i--;
        } else {
            j--;
        }
    }
    printf("\nLength of LCS = %d\n", C[m][n]);
    printf("LCS sequence    = %s\n", lcsStr);
    //getch();
    return 0;
}