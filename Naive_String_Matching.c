#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 1000

void naiveSearch(char txt[], char pat[]) {
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int found = 0;
    
    printf("\nSearching for pattern...\n");
    printf("-------------------\n");
    
    for (i = 0; i <= N-M; i++) {
        for (j = 0; j < M; j++) {
            if (txt[i+j] != pat[j]) 
                break;
        }
        
        if (j == M) {
            printf("Pattern found at index %d\n", i);
            printf("Text window: ...%.*s[%.*s]%.*s...\n",
                   i > 3 ? 3 : i, &txt[i > 3 ? i-3 : 0],
                   M, &txt[i],
                   N-i-M > 3 ? 3 : N-i-M, &txt[i+M]);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Pattern not found in the text\n");
    }
}

int main() {
    //clrscr();
    char txt[MAX], pat[MAX];
    
    printf("Naive String Matching Algorithm\n");
    printf("-----------------------------\n\n");
    
    printf("Enter the main text: ");
    scanf("%s", txt);
    
    printf("Enter the pattern to search: ");
    scanf("%s", pat);
    
    if(strlen(pat) > strlen(txt)) {
        printf("\nError: Pattern length cannot be greater than text length!\n");
        //getch();
        return 1;
    }
    
    printf("\nText: %s (length: %d)\n", txt, strlen(txt));
    printf("Pattern: %s (length: %d)\n", pat, strlen(pat));
    
    naiveSearch(txt, pat);
    
    printf("\nPress any key to exit...");
    //getch();
    return 0;
}