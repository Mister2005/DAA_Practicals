#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 1000

void computeLPS(char pat[], int M, int lps[]) {
    int len = 0, i = 1;
    lps[0] = 0;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) len = lps[len-1];
            else { lps[i] = 0; i++; }
        }
    }
}

void KMPSearch(char pat[], char txt[]) {
    int M = strlen(pat), N = strlen(txt);
    int lps[MAX], i = 0, j = 0;
    computeLPS(pat, M, lps);
    while (i < N) {
        if (pat[j] == txt[i]) { i++; j++; }
        if (j == M) {
            printf("Found pattern at index %d\n", i - j);
            j = lps[j-1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0) j = lps[j-1];
            else i++;
        }
    }
}

void main() {
    //clrscr();
    char txt[] = "ABABDABACDABABCABAB", pat[] = "ABABCABAB";
    KMPSearch(pat, txt);
    //getch();
}
