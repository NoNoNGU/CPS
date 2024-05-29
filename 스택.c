#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
    int size;
} Stack;

// ���� �ʱ�ȭ
void initStack(Stack* stack) {
    stack->top = NULL;
    stack->size = 0;
}

// ���� ��� �ִ��� Ȯ��
int isEmpty(Stack* stack) {
    return stack->size == 0;
}

// ���� ���� á���� Ȯ��
int isFull(Stack* stack) {
    return stack->size >= MAX_SIZE;
}

// ���ÿ� �� �߰�
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow: Cannot push to a full stack\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

// ���ÿ��� �� ����
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow: Cannot pop from an empty stack\n");
        exit(1);
    }
    else {
        Node* temp = stack->top;
        int poppedValue = temp->value;
        stack->top = stack->top->next;
        free(temp);
        stack->size--;
        return poppedValue;
    }
}

// ������ �ֻ��� �� ��ȯ
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty: Cannot peek\n");
        exit(1);
    }
    return stack->top->value;
}

// ������ ũ�� ��ȯ
int getSize(Stack* stack) {
    return stack->size;
}

// ������ ���� ���� ���
void printStack(Stack* stack) {
    for (Node* p = stack->top; p != NULL; p = p->next)
        printf("%d->", p->value);
    printf("NULL\n");
}

int main() {
    Stack stack;
    initStack(&stack);
    // ���ÿ� �� �߰�
    for (int i = 0; i < 10; i++) {
        push(&stack, i); 
        printStack(&stack);  // ���� ���� ���
    }
    // ���ÿ��� �� ����
    while (!isEmpty(&stack)) {
        pop(&stack); 
        printStack(&stack);  // ���� ���� ���
    }
    return 0;
}