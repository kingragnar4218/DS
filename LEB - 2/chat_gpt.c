#include <stdio.h>

int main() {
    int n;
    
    // Ask the user for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int numbers[n];  // Declare an array of size n
    int sum = 0;
    
    // Input n numbers into the array
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
        sum += numbers[i];  // Add the current number to the sum
    }
    
    // Calculate the average
    double average = (double)sum / n;
    
    // Print the sum and average
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    
    return 0;
}
_____________________________________________________________________________________________________
#include <stdio.h>

int main() {
    int n;
    
    // Ask the user for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int numbers[n];  // Declare an array of size n
    
    // Input n numbers into the array
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    
    // Initialize the largest element as the first element of the array
    int largest = numbers[0];
    
    // Loop through the array to find the largest element
    for (int i = 1; i < n; i++) {
        if (numbers[i] > largest) {
            largest = numbers[i];
        }
    }
    
    // Print the largest element
    printf("The largest element is: %d\n", largest);
    
    return 0;
}
_____________________________________________________________________________________________
#include <stdio.h>

int main() {
    int n;
    
    // Ask the user for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int numbers[n];  // Declare an array of size n
    
    // Input n numbers into the array
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    
    int num1, num2;
    
    // Read the two different numbers
    printf("Enter the first number to replace: ");
    scanf("%d", &num1);
    
    printf("Enter the second number to replace with: ");
    scanf("%d", &num2);
    
    // Find the index of num1 and replace it with num2
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (numbers[i] == num1) {
            numbers[i] = num2;
            found = 1;
            break;
        }
    }

    // If num1 is found, print the updated array
    if (found) {
        printf("Updated array: \n");
        for (int i = 0; i < n; i++) {
            printf("%d ", numbers[i]);
        }
        printf("\n");
    } else {
        printf("The first number was not found in the array.\n");
    }
    
    return 0;
}
