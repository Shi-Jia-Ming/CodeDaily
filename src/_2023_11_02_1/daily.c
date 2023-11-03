#include "daily.h"
#include <stdlib.h>

/**
 * 构造队列数据结构
 */
struct Queue {
    char data[1000];
    int head;
    int tail;
};

typedef struct Queue Queue;

// 初始化队列
Queue * initQueue() {
    Queue * queue = (Queue *) malloc(sizeof(Queue));
    queue->head = 0;
    queue->tail = -1;
    return queue;
}

// 释放队列
void freeQueue(Queue * queue) {
    free(queue);
}

// 检验队列是否为空
int isEmpty(Queue * queue) {
    return queue->head >= queue->tail + 1;
}

// 入队
void push(Queue * queue, char c) {
    queue->tail++;
    queue->data[queue->tail] = c;
}

// 从队首出队
char popHead(Queue * queue) {
    char val = queue->data[queue->head];
    queue->head++;
    return val;
}

// 从队尾出队
char popTail(Queue * queue) {
    char val = queue->data[queue->tail];
    queue->tail--;
    return val;
}

int isPalindrome(const char * str) {
    Queue * queue = initQueue();
    for (char * move = (char *)str; *move != '\0'; ++move) {
        push(queue, *move);
    }

    while(!isEmpty(queue)) {
        if (popHead(queue) != popTail(queue)) {
            freeQueue(queue);
            return 0;
        }
    }
    freeQueue(queue);
    return 1;
}