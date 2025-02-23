// Q1. Create a 2D Array of numbers.
// I. Perform addition of two matrix.
// II. Perform subtraction of two matrix.
// III. Perform multiplication of two matrix.
#include<stdio.h>
#include<stdlib.h>
struct matrix {
    int** cells;
    int row;
    int col;
}A, B, M;
void adder() {
    M.row = A.row;
    M.col = A.col;
    M.cells = (int**)calloc(M.row, sizeof(int*));
    for (int i = 0;i < M.row;i++) {
        M.cells[i] = (int*)calloc(M.col, sizeof(int));
        for (int j = 0;j < M.col;j++) {
            M.cells[i][j] = A.cells[i][j] + B.cells[i][j];
        }
    }
}
void subtracter() {
    M.row = A.row;
    M.col = A.col;
    M.cells = (int**)calloc(M.row, sizeof(int*));
    for (int i = 0;i < M.row;i++) {
        M.cells[i] = (int*)calloc(M.col, sizeof(int));
        for (int j = 0;j < M.col;j++) {
            M.cells[i][j] = A.cells[i][j] - B.cells[i][j];
        }
    }
}
void multiplier() {
    M.row = A.row;
    M.col = B.col;
    M.cells = (int**)calloc(M.row, sizeof(int*));
    for (int i = 0;i < M.row;i++) {
        M.cells[i] = (int*)calloc(M.col, sizeof(int));
        for (int j = 0;j < M.col;j++) {
            M.cells[i][j] = 0;
            for (int k = 0;k < A.col;k++) {
                M.cells[i][j] += A.cells[i][k] * B.cells[k][j];

            }
        }
    }
}
void main() {
    printf("Enter no. of rows in matrix A: ");
    scanf("%d", &A.row);
    printf("Enter no. of columns in matrix A: ");
    scanf("%d", &A.col);
    A.cells = (int**)calloc(A.row, sizeof(int*));
    for (int i = 0;i < A.row;i++) {
        A.cells[i] = (int*)calloc(A.col, sizeof(int));
        for (int j = 0;j < A.col;j++) {
            printf("Enter A[%d][%d]: ", i, j);
            scanf("%d", &A.cells[i][j]);
        }
    }
    printf("\n");
    printf("Enter no. of rows in matrix B: ");
    scanf("%d", &B.row);
    printf("Enter no. of columns in matrix B: ");
    scanf("%d", &B.col);
    B.cells = (int**)calloc(B.row, sizeof(int*));
    for (int i = 0;i < B.row;i++) {
        B.cells[i] = (int*)calloc(B.col, sizeof(int));
        for (int j = 0;j < B.col;j++) {
            printf("Enter B[%d][%d]: ", i, j);
            scanf("%d", &B.cells[i][j]);
        }
    }
    printf("\n");
    printf("Matrix A:\n");
    for (int i = 0;i < A.row;i++) {
        for (int j = 0;j < A.col;j++) {
            printf("%d ", A.cells[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Matrix B:\n");
    for (int i = 0;i < B.row;i++) {
        for (int j = 0;j < B.col;j++) {
            printf("%d ", B.cells[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    if (A.row != B.row || A.col != B.col) {
        printf("Addition\n");
        printf("Given matrices can't be added.\n");
        printf("\n");
        printf("Subtraction\n");
        printf("Given matrices can't be subtracted.\n");
        printf("\n");

    }
    else {
        printf("Addition\n");
        adder(A, B);
        for (int i = 0;i < M.row;i++) {
            for (int j = 0;j < M.col;j++) {
                printf("%d ", M.cells[i][j]);
            }
            printf("\n");
            free(M.cells[i]);
        }
        free(M.cells);
        printf("\n");
        printf("Subtraction\n");
        subtracter(A, B);
        for (int i = 0;i < M.row;i++) {
            for (int j = 0;j < M.col;j++) {
                printf("%d ", M.cells[i][j]);
            }
            printf("\n");
            free(M.cells[i]);
        }
        free(M.cells);
        printf("\n");
    }
    printf("Multiplication\n");
    if (A.col != B.row) {
        printf("Given matrices cannot be multiplied\n");
    }
    else {
        multiplier(A, B);
        for (int i = 0;i < M.row;i++) {
            for (int j = 0;j < M.col;j++) {
                printf("%d ", M.cells[i][j]);
            }
            printf("\n");
            free(M.cells[i]);
        }
        free(M.cells);
    }
    for (int i = 0;i < A.row;i++) {
        free(A.cells[i]);
    }
    for (int i = 0;i < B.row;i++) {
        free(B.cells[i]);
    }
    free(A.cells);
    free(B.cells);
}