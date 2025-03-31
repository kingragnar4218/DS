#include <stdio.h>

int findIndex(int arr[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            return i; 
        }
    }
    return -1;  
}

int main() {
    int arr1[] = {1, 2, 3, 4}, x1 = 3;
    int arr2[] = {10, 8, 30, 4, 5}, x2 = 5;
    int arr3[] = {10, 8, 30}, x3 = 6;

    printf("Index of %d: %d\n", x1, findIndex(arr1, 4, x1));
    printf("Index of %d: %d\n", x2, findIndex(arr2, 5, x2));
    printf("Index of %d: %d\n", x3, findIndex(arr3, 3, x3));

    return 0;
}

