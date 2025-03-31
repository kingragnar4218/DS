#include <stdio.h>


void selection(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
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
    selection(arr1, size1);
    printf(" Array 1 (Selection Sort): ");
    printArray(arr1, size1);

    printf("\n Array 2: ");
    printArray(arr2, size2);
    selection(arr2, size2);
    printf(" Array 2 (Selection Sort): ");
    printArray(arr2, size2);

    return 0;
}

