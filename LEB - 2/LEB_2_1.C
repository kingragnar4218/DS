#include <stdio.h>

int main() {
    int n, i;
    float sum = 0, average;

    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; 

    
    
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    
    average = sum / n;

    
    printf("\nSum: %.2f", sum);
    printf("\nAverage: %.2f\n", average);

    return 0;
}
