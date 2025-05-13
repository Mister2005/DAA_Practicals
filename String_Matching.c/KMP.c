#include <stdio.h>
#include <string.h>
#define MAX 1000

void computeLPS(char* pat, int M, int* lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char* pat, char* txt) {
    int M = strlen(pat);
    int N = strlen(txt);
    int lps[MAX];
    computeLPS(pat, M, lps);
    int i = 0;
    int j = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }
        if (j == M) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    char txt[MAX];
    char pat[MAX];
    //clrscr();
    printf("Enter text: ");
    scanf("%s", txt);
    printf("Enter pattern: ");
    scanf("%s", pat);
    printf("\nSearching for \"%s\" in \"%s\"...\n\n", pat, txt);
    KMPSearch(pat, txt);
    //getch();
    return 0;
}