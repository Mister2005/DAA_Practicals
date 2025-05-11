#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MOD 13
#define MAX 1000

int power(int exponent) {
    int result = 1;
    for(int i = 0; i < exponent; i++) {
        result = (result * 10) % MOD;
    }
    return result;
}

void rabinKarp(char pat[], char txt[]) {
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0;
    int t = 0;
    int found = 0;
    
    for (i = 0; i < M; i++) {
        p = (p + (pat[i] * power(M - 1 - i))) % MOD;
        t = (t + (txt[i] * power(M - 1 - i))) % MOD;
    }
    
    printf("\nSearching for pattern using Rabin-Karp algorithm...\n");
    printf("------------------------------------------------\n");
    printf("Pattern hash value: %d\n\n", p);
    
    for (i = 0; i <= N-M; i++) {
        if (p == t) {
            printf("Hash match found at index %d, verifying characters...\n", i);
            for (j = 0; j < M; j++) {
                if (txt[i+j] != pat[j]) 
                    break;
            }
            if (j == M) {
                printf("Pattern found at index %d\n", i);
                printf("Text window: ...%.*s[%.*s]%.*s...\n\n",
                       i > 3 ? 3 : i, &txt[i > 3 ? i-3 : 0],
                       M, &txt[i],
                       N-i-M > 3 ? 3 : N-i-M, &txt[i+M]);
                found = 1;
            }
        }
        
        if (i < N-M) {
            t = 0;
            for(j = 0; j < M; j++) {
                t = (t + (txt[i + 1 + j] * power(M - 1 - j))) % MOD;
            }
            printf("Rolling hash at index %d: %d\n", i+1, t);
        }
    }
    
    if (!found) {
        printf("\nPattern not found in the text\n");
    }
}

int main() {
    //clrscr();
    char txt[MAX], pat[MAX];
    
    printf("Rabin-Karp String Matching Algorithm\n");
    printf("--------------------------------\n\n");
    
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
    
    rabinKarp(pat, txt);
    
    printf("\nPress any key to exit...");
    //getch();
    return 0;
}