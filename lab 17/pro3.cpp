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
            printf("Duplicate value! %d already exist in the list\n", value);
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


void printList(struct Node* head) {
	
    if (head == NULL) {
    	
        printf("list is empty.\n");
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
    int value;

    while (1) {
        printf("Enter value to insert list (enter -1 to stop): ");
        scanf("%d", &value);

        if (value == -1) {
            break;
        }

        insertOrdered(&head, value);
        printList(head);
    }

    return 0;
}

