#include <stdio.h>
void swap(int a, int b) {
    int temp;
    temp = a;  
    a = b;     
    b = temp;  
    printf("Inside swap function: a = %d, b = %d\n", a, b);
}
int main() {
    int num1, num2;
   
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
   
    printf("Before swap: num1 = %d, num2 = %d\n", num1, num2);
    
    swap(num1, num2);
    
    printf("After swap : num1 = %d, num2 = %d\n", num1, num2);
    return 0;
}
