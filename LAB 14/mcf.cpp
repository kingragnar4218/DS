#include <stdio.h>
#include <stdlib.h>

int main() {
    int n , sum=0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
         
    
    int *ptr = (int*)malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed using malloc.\n");
        return 1;
    }
   
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", ptr + i);
        sum +=ptr[i];
    }

    printf("\nElements entered using malloc:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: %d\n", i + 1, *(ptr + i),sum);
    }
    
    free(ptr);
   

    return 0;
}

