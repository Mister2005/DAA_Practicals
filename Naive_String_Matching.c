#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 1000

// Function to implement naive string matching algorithm
void naiveSearch(char txt[], char pat[]) {
    int M = strlen(pat);  // Length of pattern
    int N = strlen(txt);  // Length of text
    int i, j;
    int found = 0;       // Flag to track if pattern was found
    
    printf("\nSearching for pattern...\n");
    printf("-------------------\n");
    
    // Loop through all possible starting positions
    for (i = 0; i <= N-M; i++) {
        // Try to match pattern starting at position i
        for (j = 0; j < M; j++) {
            if (txt[i+j] != pat[j]) 
                break;  // Mismatch found, break inner loop
        }
        
        // If inner loop completed (j == M), we found a match
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

void main() {
    //clrscr();  // Clear screen for Turbo C
    char txt[MAX], pat[MAX];
    
    printf("Naive String Matching Algorithm\n");
    printf("-----------------------------\n\n");
    
    // Get input text
    printf("Enter the main text: ");
    scanf("%s", txt);
    
    // Get pattern to search
    printf("Enter the pattern to search: ");
    scanf("%s", pat);
    
    // Input validation
    if(strlen(pat) > strlen(txt)) {
        printf("\nError: Pattern length cannot be greater than text length!\n");
        //getch();
        return;
    }
    
    // Display inputs
    printf("\nText: %s (length: %d)\n", txt, strlen(txt));
    printf("Pattern: %s (length: %d)\n", pat, strlen(pat));
    
    // Perform search
    naiveSearch(txt, pat);
    
    printf("\nPress any key to exit...");
    //getch();  // Wait for key press in Turbo C
}
