#include <stdio.h>
#include <string.h>
#define MAX 1000

void searchNaive(char* pat, char* txt) {
    int M = strlen(pat);
    int N = strlen(txt);
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;
        if (j == M)
            printf("Pattern found at index %d\n", i);
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
    searchNaive(pat, txt);
    //getch();
    return 0;
}