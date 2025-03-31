#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

// Stack structure to store words
struct Stack {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int top;
};

// Initialize stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Check if stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Check if stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX_WORDS - 1;
}

// Push word onto stack
void push(struct Stack* stack, char* word) {
    if (isFull(stack)) {
        printf("Stack is full! Cannot add more words.\n");
        return;
    }
    stack->top++;
    strcpy(stack->words[stack->top], word);
    printf("Word '%s' added successfully.\n", word);
}

// Pop word from stack (undo)
void pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Nothing to undo! Document is empty.\n");
        return;
    }
    printf("Undo: Removed word '%s'\n", stack->words[stack->top]);
    stack->top--;
}

// Display current document
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Document is empty.\n");
        return;
    }
    
    printf("\nCurrent Document: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%s ", stack->words[i]);
    }
    printf("\n\n");
}

int main() {
    struct Stack stack;
    initialize(&stack);
    int choice;
    char word[MAX_WORD_LENGTH];

    while (1) {
        printf("1. Add word\n");
        printf("2. Undo last word\n");
        printf("3. Display document\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Clear input buffer
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                printf("Enter a word: ");
                fgets(word, MAX_WORD_LENGTH, stdin);
                word[strcspn(word, "\n")] = 0; // Remove newline
                push(&stack, word);
                break;
                
            case 2:
                pop(&stack);
                break;
                
            case 3:
                display(&stack);
                break;
                
            case 4:
                printf("Exiting...\n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
