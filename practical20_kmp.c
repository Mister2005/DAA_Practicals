#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void computeLPSArray(char* pattern, int M, int* lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char* pattern, char* text) {
    int M = strlen(pattern);
    int N = strlen(text);
    int* lps = (int*)malloc(M * sizeof(int));
    int i = 0;
    int j = 0;
    int found = 0;

    computeLPSArray(pattern, M, lps);

    printf("\nLPS Table:\n");
    printf("Index:  ");
    for (i = 0; i < M; i++) {
        printf("%2d ", i);
    }
    printf("\nPattern: ");
    for (i = 0; i < M; i++) {
        printf("%2c ", pattern[i]);
    }
    printf("\nLPS:    ");
    for (i = 0; i < M; i++) {
        printf("%2d ", lps[i]);
    }
    printf("\n\n");

    i = 0;
    j = 0;
    while (i < N) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == M) {
            printf("Pattern found at index %d\n", i - j);
            found = 1;
            j = lps[j - 1];
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    if (!found) {
        printf("Pattern not found in the text\n");
    }

    free(lps);
}

int main() {
    char text[1000], pattern[100];

    printf("Enter the text string: ");
    scanf("%s", text);
    printf("Enter the pattern to search: ");
    scanf("%s", pattern);

    KMPSearch(pattern, text);

    return 0;
}