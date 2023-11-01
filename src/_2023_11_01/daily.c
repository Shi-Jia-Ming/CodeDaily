#include "daily.h"
#include <stdlib.h>

/**
 * 栈相关逻辑
 */
struct Stack {
    char data[10000];
    int top;
};

typedef struct Stack Stack;

// 初始化栈
Stack * initStack() {
    Stack * stack = (Stack *) malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

// 释放栈
void freeStack(Stack * stack) {
    free(stack);
}

// 检验栈是否为空
int isEmpty(Stack * stack) {
    return stack->top == -1;
}

// 入栈
void push(Stack * stack, char value) {
    stack->top++;
    stack->data[stack->top] = value;
}

// 出栈
char pop(Stack * stack) {
    char value = stack->data[stack->top];
    stack->top--;
    return value;
}

/**
 * 题目函数
 */
bool isValid(const char * s) {
    // 初始化栈
    Stack * stack = initStack();
    
    char * move = (char *)s;
    // 逐个读取字符
    while(*move != '\0') {
        // 遇到左括号入栈
        if (*move == '[' || *move == '(' || *move == '{') {
            push(stack, *move);
            move++;
        } else if (*move == ']') {
            if (pop(stack) != '[') {
                freeStack(stack);
                return false;
            }
            move++;
        } else if (*move == ')') {
            if (pop(stack) != '(') {
                freeStack(stack);
                return false;
            }
            move++;
        } else if (*move == '}') {
            if (pop(stack) != '{') {
                freeStack(stack);
                return false;
            }
            move++;
        }
    }
    if (!isEmpty(stack)) {
        freeStack(stack);
        return false;
    }
    freeStack(stack);
    return true;
}