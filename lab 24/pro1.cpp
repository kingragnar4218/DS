#include <stdio.h>
int binary(int arr[], int size, int key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid; 
        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {2, 4, 7, 10, 15, 20, 25, 30}; 
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;
    printf("enter element to find  : ");
    scanf("%d", &key);
    int result = binary(arr, size, key);
    if (result != -1)
        printf("element index is  %d\n", result);
    else
        printf("element not found\n");
    return 0;
}

