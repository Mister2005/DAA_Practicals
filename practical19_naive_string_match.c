#include <stdio.h>
#include <conio.h>
#include <string.h>

void naiveSearch(char txt[], char pat[]) {
    int M = strlen(pat), N = strlen(txt), i, j;
    for (i = 0; i <= N-M; i++) {
        for (j = 0; j < M; j++)
            if (txt[i+j] != pat[j]) break;
        if (j == M) printf("Pattern found at index %d\n", i);
    }
}

void main() {
    //clrscr();
    char txt[] = "AABAACAADAABAAABAA", pat[] = "AABA";
    naiveSearch(txt, pat);
    //getch();
}
