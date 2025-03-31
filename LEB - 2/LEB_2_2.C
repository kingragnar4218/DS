#include <stdio.h>

int main() {
    int n;
    
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int numbers[n];
    
    
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    
    
    int largest = numbers[0];
    
    
    for (int i = 1; i < n; i++) {
        if (numbers[i] > largest) {
            largest = numbers[i];
        }
    }
    
    
    printf("The largest element is: %d\n", largest);
    
    return 0;
}
