#include <stdio.h>
#include <conio.h>
#include <string.h>
#define d 256
#define q 101
#define MAX 1000

void rabinKarp(char pat[], char txt[]) {
    int M = strlen(pat), N = strlen(txt), i, j;
    int p = 0, t = 0, h = 1;
    int found = 0;
    
    for (i = 0; i < M-1; i++) h = (h*d) % q;
    for (i = 0; i < M; i++) {
        p = (d*p + pat[i]) % q;
        t = (d*t + txt[i]) % q;
    }
    for (i = 0; i <= N-M; i++) {
        if (p == t) {
            for (j = 0; j < M; j++)
                if (txt[i+j] != pat[j]) break;
            if (j == M) {
                printf("Pattern found at index %d\n", i);
                found = 1;
            }
        }
        if (i < N-M) {
            t = (d*(t - txt[i]*h) + txt[i+M]) % q;
            if (t < 0) t = (t + q);
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
    printf("Pattern: %s\n\n", pat);
    rabinKarp(pat, txt);
}
