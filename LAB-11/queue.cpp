#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the queue

// Queue structure
struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

// Function to initialize the queue
void initializeQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to add an element to the queue (ENQUEUE)
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue is full. Cannot enqueue %d\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0; // Queue was empty, set front to 0
        }
        q->rear++;
        q->arr[q->rear] = value; // Insert the element at the rear
        printf("Enqueued %d\n", value);
    }
}

// Function to remove an element from the queue (DEQUEUE)
void dequeue(struct Queue* q) {
    if (q->front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        printf("Dequeued %d\n", q->arr[q->front]);
        // Move the front to the next element
        if (q->front == q->rear) {
            q->front = q->rear = -1; // Reset queue if it's empty
        } else {
            q->front++;
        }
    }
}

// Function to display the elements of the queue
void displayQueue(struct Queue* q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

// Main function to test the queue operations
int main() {
    struct Queue q;
    initializeQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    displayQueue(&q);  // Display queue

    dequeue(&q);       // Dequeue an element
    dequeue(&q);       // Dequeue another element
    
    displayQueue(&q);  // Display queue again

    enqueue(&q, 60);   // Enqueue another element
    displayQueue(&q);  // Display queue again

    return 0;
}
