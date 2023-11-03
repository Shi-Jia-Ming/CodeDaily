#include "daily.h"
#include <stdlib.h>


/**
 * 构造队列数据结构
 */
struct Queue {
    Node * data[6000];
    int endNode;
    int tail;
    int head;
    int size;
};

typedef struct Queue Queue;

// 初始化队列
Queue * initQueue() {
    Queue * queue = (Queue *) malloc(sizeof(Queue));
    queue->tail = -1;
    queue->head = 0;
    queue->endNode = -1;
    queue->size = 0;
    return queue;
}

// 释放队列
void freeQueue(Queue * queue) {
    free(queue);
}

// 将队尾节点设置为 end 节点
void setEndNode(Queue * queue) {
    queue->endNode = queue->tail;
}

// 入队
void push(Queue * queue, Node * node) {
    queue->tail++;
    queue->size++;
    queue->data[queue->tail] = node;
}

// 出队
Node * pop(Queue * queue) {
    queue->size--;
    Node * val = queue->data[queue->head];
    queue->head++;
    return val;
}

// 获取队首元素
Node * getHeadNode(Queue * queue) {
    return queue->data[queue->head];
}

// 队列是否为空
int isEmpty(Queue * queue) {
    return queue->size == 0;
}

// 队首元素是否为 end
int isEndNode(Queue * queue) {
    return queue->endNode == queue->head;
}


Node * connect(Node * root) {
    if (root == NULL)
        return NULL;

    // 初始化队列数据结构
    Queue * queue = initQueue();

    push(queue, root);
    setEndNode(queue);
    Node * move;

    while (!isEmpty(queue)) {
        while(!isEndNode(queue)) {
            move = pop(queue);
            move->next = getHeadNode(queue);
            if (move->left != NULL)
                push(queue, move->left);
            if (move->right != NULL)
                push(queue, move->right);
        }
        move = pop(queue);
        if (move->left != NULL)
            push(queue, move->left);
        if (move->right != NULL)
            push(queue, move->right);
        move->next = NULL;
        setEndNode(queue);
    }

    freeQueue(queue);
    return root;
}