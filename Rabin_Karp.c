#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MOD 13    // A prime number for hash calculation
#define MAX 1000  // Maximum string length

// Function to calculate power of 10
int power(int exponent) {
    int result = 1;
    for(int i = 0; i < exponent; i++) {
        result = (result * 10) % MOD;
    }
    return result;
}

// Function to implement Rabin-Karp string matching algorithm
void rabinKarp(char pat[], char txt[]) {
    int M = strlen(pat);  // Length of pattern
    int N = strlen(txt);  // Length of text
    int i, j;
    int p = 0;    // Hash value for pattern
    int t = 0;    // Hash value for current text window
    int found = 0; // Flag to track if pattern was found
    
    // Calculate initial hash values for pattern and first text window
    for (i = 0; i < M; i++) {
        p = (p + (pat[i] * power(M - 1 - i))) % MOD;
        t = (t + (txt[i] * power(M - 1 - i))) % MOD;
    }
    
    printf("\nSearching for pattern using Rabin-Karp algorithm...\n");
    printf("------------------------------------------------\n");
    printf("Pattern hash value: %d\n\n", p);
    
    // Slide pattern over text one by one
    for (i = 0; i <= N-M; i++) {
        // If hash values match, check characters one by one
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
        
        // Calculate hash value for next window using rolling hash
        if (i < N-M) {
            // Remove first character of current window
            t = 0;
            // Calculate new hash for next window
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

void main() {
    //clrscr();  // Clear screen for Turbo C
    char txt[MAX], pat[MAX];
    
    printf("Rabin-Karp String Matching Algorithm\n");
    printf("--------------------------------\n\n");
    
    printf("Enter the main text: ");
    scanf("%s", txt);
    
    printf("Enter the pattern to search: ");
    scanf("%s", pat);
    
    // Input validation
    if(strlen(pat) > strlen(txt)) {
        printf("\nError: Pattern length cannot be greater than text length!\n");
        //getch();
        return;
    }
    
    printf("\nText: %s (length: %d)\n", txt, strlen(txt));
    printf("Pattern: %s (length: %d)\n", pat, strlen(pat));
    
    // Perform Rabin-Karp search
    rabinKarp(pat, txt);
    
    printf("\nPress any key to exit...");
    //getch();  // Wait for key press in Turbo C
}
