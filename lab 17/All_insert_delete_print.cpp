#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    
    return newNode;
}


void insertOrdered(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    struct Node* current = *head;
    struct Node* previous = NULL;

    
    while (current != NULL) {
        if (current->data == value) {
            printf("Duplicate value! %d already exists in the list.\n", value);
            free(newNode);
            return;
        }
        previous = current;
        current = current->next;
    }

    
    if (*head == NULL || (*head)->data > value) {
        newNode->next = *head;
        *head = newNode;
    } else {
        previous->next = newNode;
        newNode->next = current;
    }
}


void deleteNode(struct Node** head, int value) {
    struct Node* current = *head;
    struct Node* previous = NULL;


    if (current == NULL) {
        printf("The list is empty.\n");
        return;
    }


    if (current->data == value) {
        *head = current->next;
        free(current);
        printf("Node with value %d deleted.\n", value);
        return;
    }

  
    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with value %d not found.\n", value);
        return;
    }

  
    previous->next = current->next;
    free(current);
    printf("Node with value %d deleted.\n", value);
}


void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert value\n");
        printf("2. Delete value\n");
        printf("3. Print list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertOrdered(&head, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

