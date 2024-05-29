#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// 큐 초기화
void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

// 큐 비어 있는지 확인
int isEmpty(Queue* queue) {
    return queue->size == 0;
}

// 큐 가득 찼는지 확인
int isFull(Queue* queue) {
    return queue->size >= MAX_SIZE;
}

// 큐에 값 추가
void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue overflow: Cannot enqueue to a full queue\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = newNode;
    }
    else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    queue->size++;
}

// 큐에서 값 제거
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow: Cannot dequeue from an empty queue\n");
        exit(1);
    }
    Node* temp = queue->front;
    int dequeuedValue = temp->value;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    queue->size--;
    return dequeuedValue;
}

// 큐의 현재 상태 출력
void printQueue(Queue* queue) {
    Node* p;
    for (p= queue -> front; p != NULL; p=p->next)
        printf("%d->", p->value);
    printf("NULL\n");
    }

int main() {
    Queue queue;
    initQueue(&queue);

    // 큐에 값 추가
    for (int i = 0; i < 10; i++) {
        enqueue(&queue, i);
        printQueue(&queue);  // 큐 상태 출력
    }

    // 큐에서 값 제거
    while (!isEmpty(&queue)) {
        dequeue(&queue);
        printQueue(&queue);  // 큐 상태 출력
    }

    return 0;
}
