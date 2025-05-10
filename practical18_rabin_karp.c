#include <stdio.h>
#include <conio.h>
#include <string.h>
#define d 256
#define q 101

void rabinKarp(char pat[], char txt[]) {
    int M = strlen(pat), N = strlen(txt), i, j;
    int p = 0, t = 0, h = 1;
    for (i = 0; i < M-1; i++) h = (h*d) % q;
    for (i = 0; i < M; i++) {
        p = (d*p + pat[i]) % q;
        t = (d*t + txt[i]) % q;
    }
    for (i = 0; i <= N-M; i++) {
        if (p == t) {
            for (j = 0; j < M; j++)
                if (txt[i+j] != pat[j]) break;
            if (j == M) printf("Pattern found at index %d\n", i);
        }
        if (i < N-M)
            t = (d*(t - txt[i]*h) + txt[i+M]) % q;
        if (t < 0) t = (t + q);
    }
}

void main() {
    //clrscr();
    char txt[] = "ABCCDDAEFG", pat[] = "CDD";
    rabinKarp(pat, txt);
    //getch();
}
