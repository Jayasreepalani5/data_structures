#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
struct Queue {
    int arr[MAX_SIZE];
    int front, rear;
};
void initialize(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}
int isEmpty(struct Queue *queue) {
    return queue->front == -1;
}
int isFull(struct Queue *queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}
void enqueue(struct Queue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }
    queue->arr[queue->rear] = data;
}
int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; 
    }
    int data = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return data;
}
void display(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    int i = queue->front;
    printf("Queue: ");
    while (i != queue->rear) {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue->arr[i]);
}
int main() {
    struct Queue queue;
    initialize(&queue);
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    display(&queue);
    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));
    display(&queue);
    return 0;
}
