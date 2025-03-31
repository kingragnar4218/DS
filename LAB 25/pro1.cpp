#include <stdio.h>


void bubble(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {38, 27, 43, 10};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    
    int arr2[] = {10, 80, 40, 30, 90, 40};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    printf(" Array 1: ");
    printArray(arr1, size1);
    bubble(arr1, size1);
    printf("Sort Array 1 Bubble Sort: ");
    printArray(arr1, size1);

    printf("\n Array 2: ");
    printArray(arr2, size2);
    bubble(arr2, size2);
    printf(" Array 2 (Bubble Sort): ");
    printArray(arr2, size2);

    return 0;
}

