#include <stdio.h>

int main() {
   int n;   
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
   
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\n");
    
    for (int i = 0; i < n; i++) {
            printf("%d \n ", arr[i]);
        }
    return 0;
}

