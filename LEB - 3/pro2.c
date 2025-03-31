#include <stdio.h>

int main() {
    int matrix1[3][2], matrix2[2][3], result[3][3];

    // Reading the elements of the first matrix (3x2)
    printf("Enter elements of first 3x2 matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Enter element at position [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Reading the elements of the second matrix (2x3)
    printf("Enter elements of second 2x3 matrix:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Enter element at position [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Matrix multiplication (3x2) * (2x3) = (3x3)
    for (int i = 0; i < 3; i++) { // Loop through rows of matrix1
        for (int j = 0; j < 3; j++) { // Loop through columns of matrix2
            result[i][j] = 0; // Initialize the result matrix element
            for (int k = 0; k < 2; k++) { // Loop for summation across rows of matrix1 and columns of matrix2
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Printing the resulting matrix
    printf("Result of matrix multiplication (3x3):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}

