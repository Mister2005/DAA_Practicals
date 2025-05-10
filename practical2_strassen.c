#include <stdio.h>
#include <conio.h>

void add(int A[2][2], int B[2][2], int C[2][2]) {
    int i,j;
    for(i=0;i<2;i++) for(j=0;j<2;j++) C[i][j] = A[i][j] + B[i][j];
}

void sub(int A[2][2], int B[2][2], int C[2][2]) {
    int i,j;
    for(i=0;i<2;i++) for(j=0;j<2;j++) C[i][j] = A[i][j] - B[i][j];
}

void strassen(int A[2][2], int B[2][2], int C[2][2]) {
    int P1[2][2], P2[2][2], P3[2][2], P4[2][2], P5[2][2], P6[2][2], P7[2][2];
    int temp1[2][2], temp2[2][2];
    int i, j;
    
    // Create submatrices
    int A11[2][2], A12[2][2], A21[2][2], A22[2][2];
    int B11[2][2], B12[2][2], B21[2][2], B22[2][2];
    
    // Initialize submatrices
    A11[0][0] = A[0][0]; A11[0][1] = 0; A11[1][0] = 0; A11[1][1] = 0;
    A12[0][0] = A[0][1]; A12[0][1] = 0; A12[1][0] = 0; A12[1][1] = 0;
    A21[0][0] = A[1][0]; A21[0][1] = 0; A21[1][0] = 0; A21[1][1] = 0;
    A22[0][0] = A[1][1]; A22[0][1] = 0; A22[1][0] = 0; A22[1][1] = 0;
    
    B11[0][0] = B[0][0]; B11[0][1] = 0; B11[1][0] = 0; B11[1][1] = 0;
    B12[0][0] = B[0][1]; B12[0][1] = 0; B12[1][0] = 0; B12[1][1] = 0;
    B21[0][0] = B[1][0]; B21[0][1] = 0; B21[1][0] = 0; B21[1][1] = 0;
    B22[0][0] = B[1][1]; B22[0][1] = 0; B22[1][0] = 0; B22[1][1] = 0;

    // P1 = A11(B12 - B22)
    sub(B12, B22, temp1);
    for(i=0; i<2; i++) for(j=0; j<2; j++) 
        P1[i][j] = A11[0][0] * temp1[i][j];

    // P2 = (A11 + A12)B22
    add(A11, A12, temp1);
    for(i=0; i<2; i++) for(j=0; j<2; j++)
        P2[i][j] = temp1[i][j] * B22[0][0];

    // P3 = (A21 + A22)B11
    add(A21, A22, temp1);
    for(i=0; i<2; i++) for(j=0; j<2; j++)
        P3[i][j] = temp1[i][j] * B11[0][0];

    // P4 = A22(B21 - B11)
    sub(B21, B11, temp1);
    for(i=0; i<2; i++) for(j=0; j<2; j++)
        P4[i][j] = A22[0][0] * temp1[i][j];

    // P5 = (A11 + A22)(B11 + B22)
    add(A11, A22, temp1);
    add(B11, B22, temp2);
    for(i=0; i<2; i++) for(j=0; j<2; j++)
        P5[i][j] = temp1[0][0] * temp2[0][0];

    // P6 = (A12 - A22)(B21 + B22)
    sub(A12, A22, temp1);
    add(B21, B22, temp2);
    for(i=0; i<2; i++) for(j=0; j<2; j++)
        P6[i][j] = temp1[0][0] * temp2[0][0];

    // P7 = (A11 - A21)(B11 + B12)
    sub(A11, A21, temp1);
    add(B11, B12, temp2);
    for(i=0; i<2; i++) for(j=0; j<2; j++)
        P7[i][j] = temp1[0][0] * temp2[0][0];

    // Calculate C11 = P5 + P4 - P2 + P6
    C[0][0] = P5[0][0] + P4[0][0] - P2[0][0] + P6[0][0];
    
    // Calculate C12 = P1 + P2
    C[0][1] = P1[0][0] + P2[0][0];
    
    // Calculate C21 = P3 + P4
    C[1][0] = P3[0][0] + P4[0][0];
    
    // Calculate C22 = P5 + P1 - P3 - P7
    C[1][1] = P5[0][0] + P1[0][0] - P3[0][0] - P7[0][0];
}

void main() {
    //clrscr();
    int A[2][2], B[2][2], C[2][2];
    int i,j;
    printf("Enter 2x2 matrix A:\n");
    for(i=0;i<2;i++) for(j=0;j<2;j++) scanf("%d",&A[i][j]);
    printf("Enter 2x2 matrix B:\n");
    for(i=0;i<2;i++) for(j=0;j<2;j++) scanf("%d",&B[i][j]);
    strassen(A, B, C);
    printf("Resultant matrix C:\n");
    for(i=0;i<2;i++) {
        for(j=0;j<2;j++) printf("%d ",C[i][j]);
        printf("\n");
    }
    //getch();
}