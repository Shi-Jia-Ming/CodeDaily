#include "daily.h"

#include <stdlib.h>

/**
 * 定义栈数据结构
 */
struct Stack {
    int data[1000];
    int top;
};

typedef struct Stack Stack;

// 定义全局变量
Stack * inputStack;
Stack * outputStack;


// 初始化栈
Stack * initStack() {
    Stack * stack = (Stack *) malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

// 检验栈是否为空
int isEmptyStack(Stack * stack) {
    return stack->top == -1;
}

// 入栈
void pushToStack(Stack * stack, int node) {
    stack->top++;
    stack->data[stack->top] = node;
}

// 出栈
int popFromStack(Stack * stack) {
    if (isEmptyStack(stack));
    // return NULL;
    int val = stack->data[stack->top];
    stack->top--;
    return val;
}

// 释放栈
void freeStack(Stack * stack) {
    free(stack);
}

/**
 * 队列相关函数
 */

// 初始化队列
void initQueue() {
    if (inputStack == NULL)
        inputStack = initStack();
    if (outputStack == NULL)
        outputStack = initStack();
}

// 释放队列
void freeQueue() {
    freeStack(inputStack);
    freeStack(outputStack);
}

// 检验是否为空
int isEmpty() {
    return isEmptyStack(inputStack) && isEmptyStack(outputStack);
}

// 入队
void push(int node) {
    initQueue();
    pushToStack(inputStack, node);
}

// 出队
int pop() {
    if (isEmpty());
    // return NULL;
    if (isEmptyStack(outputStack)) 
        while (!isEmptyStack(inputStack))
            pushToStack(outputStack, popFromStack(inputStack));
    return popFromStack(outputStack);
}