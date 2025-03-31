#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* last = NULL;


void insertfirst(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    
    if (last == NULL) {
        newNode->next = newNode;
        last = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
}


void insertlast(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    
    if (last == NULL) {
        newNode->next = newNode;
        last = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}


void display() {
    if (last == NULL) {
        printf("list is empty.\n");
        return;
    }
    struct Node* temp = last->next;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("( )\n");
}


void deletefirst() {
    if (last == NULL) {
        printf("list is empty.\n");
        return;
    }
    struct Node* temp = last->next;
    if (last->next == last) {
        last = NULL;
    } else {
        last->next = temp->next;
    }
    free(temp);
}


void deletesecond() {
    if (last == NULL) {
        printf("list is empty.\n");
        return;
    }
    struct Node* temp = last->next;
    if (last->next == last) {
        free(last);
        last = NULL;
    } else {
        while (temp->next != last) {
            temp = temp->next;
        }
        temp->next = last->next;
        free(last);
        last = temp;
    }
}


int main() {
    int choice, value;
    while (1) {
        printf("\n linked List :\n");
        printf("1. insert fisrt\n");
        printf("2. insert last\n");
        printf("3. display\n");
        printf("4. delete first\n");
        printf("5. delete last\n");
        printf("6. exit\n");
        printf("enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("enter value  insert first : ");
                scanf("%d", &value);
                insertfirst(value);//
                break;
            case 2:
                printf("enter value  insert last : ");
                scanf("%d", &value);
                insertlast(value);
                break;
            case 3:
                display();
                break;
            case 4:
                deletefirst();
                break;
            case 5:
                deletesecond();
                break;
            case 6:
                printf("goood byee\n");
                exit(0);
            default:
                printf("invalid choice\n");
        }
    }
    return 0;
}

