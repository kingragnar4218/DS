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
    for (int i = 0; i < n; i++) {
            printf("%d\n ", arr[i]);
        }
        
    int num1, num2;
    
   
    printf("Enter  number to replace: ");
    scanf("%d", &num1);
    
    printf("Enter  new number   ");
    scanf("%d", &num2);
    
    
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == num1) {
            arr[i] = num2;
            found = 1;
            break;
        }
    }

   
    if (found) {
        printf("updated array: \n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf(" number is not found in the array  \n");
    }    
    return 0;
}

