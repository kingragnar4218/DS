#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;


void insertmidd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    
    if (head == NULL) { 
        newNode->prev = newNode->next = NULL;
        head = newNode;
        return;
    }
   
    struct Node* slow = head;
    struct Node* fast = head;
    
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    
    newNode->next = slow->next;
    newNode->prev = slow;
    
    if (slow->next != NULL) {
        slow->next->prev = newNode;
    }
    slow->next = newNode;
}


void deletenode(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Node not found.\n");
        return;
    }
    
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }
    
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    
    free(temp);
   
}


void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    int choice, value;
    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert in Middle\n");
        printf("2. Display List\n");
        printf("3. Delete Node\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertmidd(value); 
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deletenode(value);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

