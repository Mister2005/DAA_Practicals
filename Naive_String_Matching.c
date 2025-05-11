#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 1000

void naiveSearch(char txt[], char pat[]) {
    int M = strlen(pat), N = strlen(txt), i, j;
    int found = 0;
    for (i = 0; i <= N-M; i++) {
        for (j = 0; j < M; j++)
            if (txt[i+j] != pat[j]) break;
        if (j == M) {
            printf("Pattern found at index %d\n", i);
            found = 1;
        }
    }
    if (!found) {
        printf("Pattern not found in the text\n");
    }
}

void main() {
    char txt[MAX], pat[MAX];
    printf("Enter the main text: ");
    scanf("%s", txt);
    printf("Enter the pattern to search: ");
    scanf("%s", pat);
    
    printf("\nText: %s\n", txt);
    printf("Pattern: %s\n", pat);
    
    naiveSearch(txt, pat);
}
