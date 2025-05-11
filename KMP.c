#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX 1000

void computeLPSArray(char* pattern, int M, int* lps) {
    int len = 0;
    int i;
    
    lps[0] = 0;
    i = 1;
    
    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
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

    printf("\nLongest Prefix Suffix (LPS) Table:\n");
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
    printf("\n\nSearching for pattern...\n");
    printf("----------------------\n");

    i = 0;
    j = 0;
    while (i < N) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == M) {
            printf("Pattern found at index %d\n", i - j);
            printf("Text window: ...%.*s[%.*s]%.*s...\n",
                   (i-j) > 3 ? 3 : (i-j), &text[(i-j) > 3 ? (i-j)-3 : 0],
                   M, &text[i-j],
                   N-(i-j)-M > 3 ? 3 : N-(i-j)-M, &text[i]);
            found = 1;
            j = lps[j - 1];
        }
        else if (i < N && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
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
    //clrscr();
    char text[MAX], pattern[MAX];

    printf("KMP (Knuth-Morris-Pratt) String Matching Algorithm\n");
    printf("--------------------------------------------\n\n");

    printf("Enter the text string: ");
    scanf("%s", text);
    printf("Enter the pattern to search: ");
    scanf("%s", pattern);

    if(strlen(pattern) > strlen(text)) {
        printf("\nError: Pattern length cannot be greater than text length!\n");
        //getch();
        return 1;
    }

    printf("\nText: %s (length: %d)\n", text, strlen(text));
    printf("Pattern: %s (length: %d)\n", pattern, strlen(pattern));

    KMPSearch(pattern, text);

    printf("\nPress any key to exit...");
    //getch();
    return 0;
}