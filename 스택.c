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

// 스택 초기화
void initStack(Stack* stack) {
    stack->top = NULL;
    stack->size = 0;
}

// 스택 비어 있는지 확인
int isEmpty(Stack* stack) {
    return stack->size == 0;
}

// 스택 가득 찼는지 확인
int isFull(Stack* stack) {
    return stack->size >= MAX_SIZE;
}

// 스택에 값 추가
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

// 스택에서 값 제거
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

// 스택의 최상위 값 반환
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty: Cannot peek\n");
        exit(1);
    }
    return stack->top->value;
}

// 스택의 크기 반환
int getSize(Stack* stack) {
    return stack->size;
}

// 스택의 현재 상태 출력
void printStack(Stack* stack) {
    for (Node* p = stack->top; p != NULL; p = p->next)
        printf("%d->", p->value);
    printf("NULL\n");
}

int main() {
    Stack stack;
    initStack(&stack);
    // 스택에 값 추가
    for (int i = 0; i < 10; i++) {
        push(&stack, i); 
        printStack(&stack);  // 스택 상태 출력
    }
    // 스택에서 값 제거
    while (!isEmpty(&stack)) {
        pop(&stack); 
        printStack(&stack);  // 스택 상태 출력
    }
    return 0;
}