#include <stdio.h>
#include <stdlib.h>

#define MAX 5 


struct Queue {
    int arr[MAX];
    int front;
    int rear;
};


void cretaeQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}


void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("queue is full. %d\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0; 
        }
        q->rear++;
        q->arr[q->rear] = value; 
        printf("insert %d\n", value);
    }
}


void dequeue(struct Queue* q) {
    if (q->front == -1) {
        printf("queue is empty. \n");
    } else {
        printf("delete %d\n", q->arr[q->front]);

        if (q->front == q->rear) {
            q->front = q->rear = -1;
        } else {
            q->front++;
        }
    }
}


void displayqueue(struct Queue* q) {
    if (q->front == -1) {
        printf("queue is empty\n");
    } else {
        printf("queue: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}


int main() {
    struct Queue q;
    cretaeQueue(&q);
    
    int choice, value;
    
    while (1) {

        printf("\nselect :\n");
        printf("1. enqueue\n");
        printf("2. dequeue\n");
        printf("3. display queue\n");
        printf("4. Exit\n");
        printf("select (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:

                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:

                dequeue(&q);
                break;
            case 3:

                displayqueue(&q);
                break;
            case 4:

                printf("exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}

