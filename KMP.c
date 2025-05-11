#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX 1000

// Function to compute the Longest Proper Prefix which is also Suffix (LPS) array
void computeLPSArray(char* pattern, int M, int* lps) {
    int len = 0;  // Length of the previous longest prefix & suffix
    int i;
    
    lps[0] = 0;  // First element is always 0
    i = 1;
    
    // Calculate lps[i] for i = 1 to M-1
    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                // Try to find a shorter prefix which is also a suffix
                len = lps[len - 1];
            }
            else {
                // No prefix found
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Function to implement KMP string matching algorithm
void KMPSearch(char* pattern, char* text) {
    int M = strlen(pattern);
    int N = strlen(text);
    int* lps = (int*)malloc(M * sizeof(int));
    int i = 0;  // Index for text
    int j = 0;  // Index for pattern
    int found = 0;  // Flag to track if pattern was found

    // Compute the LPS array
    computeLPSArray(pattern, M, lps);

    // Print the LPS Table for understanding
    printf("\nLongest Prefix Suffix (LPS) Table:\n");
    printf("Index:  ");
    for (i = 0; i < M; i++) printf("%2d ", i);
    printf("\nPattern: ");
    for (i = 0; i < M; i++) printf("%2c ", pattern[i]);
    printf("\nLPS:    ");
    for (i = 0; i < M; i++) printf("%2d ", lps[i]);
    printf("\n\nSearching for pattern...\n");
    printf("----------------------\n");

    // Search for pattern in text
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

void main() {
    //clrscr();  // Clear screen for Turbo C
    char text[MAX], pattern[MAX];

    printf("KMP (Knuth-Morris-Pratt) String Matching Algorithm\n");
    printf("--------------------------------------------\n\n");

    printf("Enter the text string: ");
    scanf("%s", text);
    printf("Enter the pattern to search: ");
    scanf("%s", pattern);

    // Input validation
    if(strlen(pattern) > strlen(text)) {
        printf("\nError: Pattern length cannot be greater than text length!\n");
        //getch();
        return;
    }

    // Display inputs
    printf("\nText: %s (length: %d)\n", text, strlen(text));
    printf("Pattern: %s (length: %d)\n", pattern, strlen(pattern));

    // Perform KMP search
    KMPSearch(pattern, text);

    printf("\nPress any key to exit...");
    //getch();  // Wait for key press in Turbo C
}