#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 100

void printLCSTable(int L[][MAX+1], char *X, char *Y, int m, int n) {
    printf("\nDynamic Programming Table:\n");
    printf("   ");
    printf("  ");
    for(int j = 0; j < n; j++)
        printf("%3c ", Y[j]);
    printf("\n   ");
    for(int j = 0; j <= n; j++)
        printf("----");
    printf("\n");
    
    for(int i = 0; i <= m; i++) {
        if(i == 0)
            printf("  |");
        else
            printf("%c |", X[i-1]);
        for(int j = 0; j <= n; j++) {
            printf("%3d ", L[i][j]);
        }
        printf("\n");
    }
}

void printLCS(int L[][MAX+1], char *X, char *Y, int m, int n) {
    char lcs[MAX];
    int index = L[m][n];
    lcs[index] = '\0';
    
    int i = m, j = n;
    while(i > 0 && j > 0) {
        if(X[i-1] == Y[j-1]) {
            lcs[index-1] = X[i-1];
            i--; j--; index--;
        }
        else if(L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }
    
    printf("\nLongest Common Subsequence: %s\n", lcs);
    printf("Length of LCS: %d\n", strlen(lcs));
    
    printf("\nVisualization of matching characters:\n");
    printf("String 1: ");
    for(i = 0; i < m; i++) {
        int found = 0;
        for(int k = 0; lcs[k] != '\0'; k++) {
            if(X[i] == lcs[k]) {
                found = 1;
                break;
            }
        }
        if(found)
            printf("[%c] ", X[i]);
        else
            printf("%c ", X[i]);
    }
    
    printf("\nString 2: ");
    for(j = 0; j < n; j++) {
        int found = 0;
        for(int k = 0; lcs[k] != '\0'; k++) {
            if(Y[j] == lcs[k]) {
                found = 1;
                break;
            }
        }
        if(found)
            printf("[%c] ", Y[j]);
        else
            printf("%c ", Y[j]);
    }
    printf("\n");
}

int lcs(char *X, char *Y, int m, int n) {
    int L[MAX+1][MAX+1];
    int i, j;
    
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = (L[i-1][j] > L[i][j-1])? L[i-1][j] : L[i][j-1];
        }
    }
    
    printLCSTable(L, X, Y, m, n);
    printLCS(L, X, Y, m, n);
    
    return L[m][n];
}

int main() {
    //clrscr();
    char X[MAX], Y[MAX];
    
    printf("Longest Common Subsequence (LCS) Finder\n");
    printf("------------------------------------\n\n");
    
    printf("Enter first string: ");
    scanf("%s", X);
    
    printf("Enter second string: ");
    scanf("%s", Y);
    
    int m = strlen(X);
    int n = strlen(Y);
    
    if(m > MAX || n > MAX) {
        printf("String length exceeds maximum limit of %d\n", MAX);
        //getch();
        return 1;
    }
    
    printf("\nInput strings:");
    printf("\nString 1: %s (length: %d)", X, m);
    printf("\nString 2: %s (length: %d)\n", Y, n);
    
    int length = lcs(X, Y, m, n);
    printf("\nLength of Longest Common Subsequence = %d\n", length);
    
    printf("\nPress any key to exit...");
    //getch();
    return 0;
}