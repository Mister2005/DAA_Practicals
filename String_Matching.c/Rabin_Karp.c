#include <stdio.h>
#include <string.h>
#define MAX 1000
#define d 256
// d is the number of characters in the input alphabet

void searchRK(char* pat, char* txt, int mod) {
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    // The value of h would be "pow(d, M-1)%mod"

    for (i = 0; i < M - 1; i++)
        h = (h * d) % mod;
    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % mod;
        t = (d * t + txt[i]) % mod;
    }
    for (i = 0; i <= N - M; i++) {
        if (p == t) {
            for (j = 0; j < M; j++)
                if (txt[i + j] != pat[j])
                    break;
            if (j == M)
                printf("Pattern found at index %d\n", i);
        }
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % mod;
            if (t < 0)
                t += mod;
        }
    }
}

int main() {
    char txt[MAX];
    char pat[MAX];
    int mod;
    // clrscr();
    printf("Enter text: ");
    scanf("%s", txt);
    printf("Enter pattern: ");
    scanf("%s", pat);
    printf("Enter prime modulus mod: ");
    scanf("%d", &mod);
    printf("\nSearching for \"%s\" in \"%s\" using (mod=%d)...\n\n", pat, txt, mod);
    searchRK(pat, txt, mod);
    // getch();
    return 0;
}