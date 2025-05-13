#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int N;
int board[MAX];

void printSolution() {
    int i;
    for(i = 0; i < N; i++)
        printf("%d ", board[i]);
    printf("\n");
}

int isSafe(int row, int col) {
    int i;
    for(i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void solve(int row) {
    if (row == N) {
        printSolution();
        return;
    }
    int col;
    for(col = 1; col <= N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solve(row + 1);
        }
    }
}

int main() {
    //clrscr();
    printf("Enter number of queens: ");
    scanf("%d", &N);
    solve(0);
    //getch();
    return 0;
}