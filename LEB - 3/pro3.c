#include <stdio.h>

int main() {
    int n;

    // Asking user for the size of the square matrix
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    int matrix[n][n], transpose[n][n];

    // Reading the elements of the matrix
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter element at position [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Finding the transpose of the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            transpose[i][j] = matrix[j][i];
        }
    }

    // Printing the transpose of the matrix
    printf("Transpose of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}

