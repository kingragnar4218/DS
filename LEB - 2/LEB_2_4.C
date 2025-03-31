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
            printf("%d main array  \n ", arr[i]);
        }
        
    int array[10];
	for (int i = 0; i < n; i++) {
         array[i]=arr[i];
        }
	
	for (int i = 0; i < n; i++) {
            printf("%d copy array  \n ", array[i]);
        } 
		
		   
    return 0;
}

