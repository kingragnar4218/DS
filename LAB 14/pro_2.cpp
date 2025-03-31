#include <stdio.h>

int main (){
	int n ;
	
	printf("enter number of elemenm you enter hare :");
	scanf ("%d" , &n );
	
	int  arr [n];
	int *ptr = arr;
	
	printf("enter %d element ");
	
	for(int i = 0  ; i<n ;i ++){
		printf("elements is %d" , i+1 );
		scanf ("%d ", ptr +1 );		
	}
	
	printf("\n elemen is : \n ");
	for (int i = 0; i < n; i++) {
        printf("Element %d: %d\n", i + 1, *(ptr + i));  
    }  
    return 0 ; 
	
}
