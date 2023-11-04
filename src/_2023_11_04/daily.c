#include "daily.h"
#include <stdlib.h>
#include <math.h>

/**
 * 构造栈数据结构
 */
struct StackChar {
    char data[1000];
    int top;
};
struct StackInt {
    int data[1000];
    int top;
};

typedef struct StackChar StackChar;
typedef struct StackInt StackInt;

// 初始化栈
StackChar * initStackChar() {
    StackChar * stack = (StackChar *) malloc(sizeof(StackChar));
    stack->top = -1;
    return stack;
}
StackInt * initStackInt() {
    StackInt * stack = (StackInt *) malloc(sizeof(StackInt));
    stack->top = -1;
    return stack;
}

// 检验栈是否为空
int isEmptyChar(StackChar * stack) {
    return stack->top == -1;
}
int isEmptyInt(StackInt * stack) {
    return stack->top == -1;
}

// 释放栈
void freeStackChar(StackChar * stack) {
    free(stack);
}
void freeStackInt(StackInt * stack) {
    free(stack);
}

// 入栈
void pushChar(StackChar * stack, char val) {
    stack->top++;
    stack->data[stack->top] = val;
}
void pushInt(StackInt * stack, int val) {
    stack->top++;
    stack->data[stack->top] = val;
}

// 出栈
char popChar(StackChar * stack) {
    char val = stack->data[stack->top];
    stack->top--;
    return val;
}
int popInt(StackInt * stack) {
    int val = stack->data[stack->top];
    stack->top--;
    return val;
}

// 获取当前栈顶元素
char getChar(StackChar * stack) {
    return stack->data[stack->top];
}

/**
 * 构造队列数据结构
 */
struct Queue {
    int data[1000];
    int head;
    int tail;
    int size;
};

typedef struct Queue Queue;

// 初始化队列
Queue * initQueue() {
    Queue * queue = (Queue *) malloc(sizeof(Queue));
    queue->head = 0;
    queue->tail = -1;
    queue->size = 0;
    return queue;
}

// 队列是否为空
int isEmpty(Queue * queue) {
    return queue->size == 0;
}

// 释放队列
void freeQueue(Queue * queue) {
    free(queue);
}

// 入队
void pushQueue(Queue * queue, int val) {
    queue->tail++;
    queue->data[queue->tail] = val;
    queue->size++;
}

// 出队
int popQueue(Queue * queue) {
    int val = queue->data[queue->head];
    queue->head++;
    queue->size--;
    return val;
}

// 获取队首元素
int getInt(Queue * queue) {
    return queue->data[queue->head];
}

// 根据字符串(左闭右开)转换为整数
int translate(const char * start,const  char * end) {
    int res = 0;
    int e = (int)(end - start - 1);
    for (char * move = (char *)start; move != end; ++move, --e) {
        res += (*move - '0') * (int)pow(10, e);
    }
    return res;
}

// 比较第一个符号和第二个符号的优先级
int compare(char in, char exist) {
    if (exist == '(' || exist == ')')
        return 0;
    switch (in) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            switch (exist) {
                case '+':
                case '-':
                    return 0;
                default:
                    return 1;
            }
        default:
            return 0;
    }
}

// 中序表达式转后序表达式
Queue * InToRear(const char * str) {
    StackChar * stackChar = initStackChar();
    Queue * queue = initQueue();

    for (char * move = (char *) str; *move != '\0'; ++move) {
        // 用来记录数字的开头
        char * start;
        if (*move >= '0' && *move <= '9') {
            start = move;
            for (move; *move >= '0' && *move <= '9'; ++move);
            pushQueue(queue, translate(start, move));
        }
        if (*move == '\0')
            break;
        if (*move <= '0' || *move >= '9') {
            // 处理符号
            if (!isEmptyChar(stackChar)) {
                if (*move == ')') {
                    char val = popChar(stackChar);
                    while (val != '(') {
                        pushQueue(queue, val);
                        val = popChar(stackChar);
                    }
                } else if (compare(*move, getChar(stackChar))) {
                    while (compare(*move, getChar(stackChar))) {
                        pushQueue(queue, popChar(stackChar));
                    }
                    pushChar(stackChar, *move);
                } else {
                    pushChar(stackChar, *move);
                }
            } else {
                pushChar(stackChar, *move);
            }
        }
    }
    while (!isEmptyChar(stackChar)) {
        pushQueue(queue, popChar(stackChar));
    }

    freeStackChar(stackChar);
    return queue;
}

// 根据后序表达式进行计算
int RearToVal(Queue * queue) {
    StackInt * stackInt = initStackInt();

    while (!isEmpty(queue)) {
        while (getInt(queue) != '+' && getInt(queue) != '-' && getInt(queue) != '*' && getInt(queue) != '/') {
            pushInt(stackInt, popQueue(queue));
        }
        int x = popInt(stackInt);
        int y = popInt(stackInt);
        switch (popQueue(queue)) {
            case '+':
                pushInt(stackInt, x + y);
                break;
            case '-':
                pushInt(stackInt, y - x);
                break;
            case '*':
                pushInt(stackInt, x * y);
                break;
            case '/':
                pushInt(stackInt, y / x);
                break;
        }
    }

    int val = popInt(stackInt);
    freeStackInt(stackInt);
    return val;
}


int StrToVal(const char * str) {
    Queue * queue = InToRear(str);
    int val = RearToVal(queue);
    freeQueue(queue);
    return val;
}