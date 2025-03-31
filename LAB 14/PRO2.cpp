#include <stdio.h>
int main() {
    int n;    
   
    printf("enter the number of elements: ");
    scanf("%d", &n);    
   
    int arr[n];   
   
    int *ptr = arr;    
   
    printf("enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", ptr + i); 
    }    

    printf("\n elements is :\n");
    for (int i = 0; i < n; i++) {
        printf("element %d: %d\n", i + 1, *(ptr + i));  
    }    
    return 0;
}

