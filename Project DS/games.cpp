#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100  // Maximum number of words in the stack
#define MAX_LENGTH 50  // Maximum length of a word

// Stack structure
typedef struct {
    char words[MAX_WORDS][MAX_LENGTH];
    int top;
} Stack;

// Initialize stack
void init(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(Stack *s) {
    return s->top == MAX_WORDS - 1;
}

// Push word onto stack
void push(Stack *s, char *word) {
    if (isFull(s)) {
        printf("Stack is full! Cannot add more words.\n");
        return;
    }
    s->top++;
    strcpy(s->words[s->top], word);
}

// Pop word from stack (undo last action)
void pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Nothing to undo!\n");
        return;
    }
    s->top--;
}

// Display document content
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Document is empty.\n");
        return;
    }
    printf("Current document: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%s ", s->words[i]);
    }
    printf("\n");
}

int main() {
    Stack doc;
    init(&doc);
    int choice;
    char word[MAX_LENGTH];

    while (1) {
        printf("\n1. Add word\n2. Undo last action\n3. Display document\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a word: ");
                scanf("%s", word);
                push(&doc, word);
                break;
            case 2:
                pop(&doc);
                break;
            case 3:
                display(&doc);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

