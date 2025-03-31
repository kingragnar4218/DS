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
    
    for (int i = n-1; i >= 0 ; i--) {
            printf("%d reverse array  \n ", arr[i]);
        }
        
		
		   
    return 0;
}

