#include "daily.h"
#include <stdlib.h>

/**
 * 定义队列数据结构
 */
struct Queue {
    TreeNode * data[1500];
    int head;
    int tail;
    int endIndex;
};

typedef struct Queue Queue;

// 初始化队列
Queue * initQueue() {
    Queue * queue = (Queue *) malloc(sizeof(Queue));
    queue->head = 0;
    queue->tail = -1;
    queue->endIndex = 0;
    return queue;
}

// 释放队列
void freeQueue(Queue * queue) {
    free(queue);
}

// 判断队列是否为空
int isEmpty(Queue * queue) {
    return queue->head  == queue->tail + 1;
}

// 为队列最后一个元素标记 endIndex
void setEndNode(Queue * queue) {
    queue->endIndex = queue->tail;
}

// 入队
void push(Queue * queue, TreeNode * node) {
    queue->tail++;
    queue->data[queue->tail] = node;
}

// 出队
TreeNode * pop(Queue * queue) {
    if (isEmpty(queue))
        return NULL;
    TreeNode * val = queue->data[queue->head];
    queue->head++;
    return val;
}

void reverse(int* val, int length) {
    int count = length / 2;
    int temp;
    for (int i =0; i < count; ++i) {
        temp = val[i];
        val[i] = val[length - i - 1];
        val[length - i - 1] = temp;
    }
}


int** Print(TreeNode* pRoot, int* returnSize, int** returnColumnSizes) {
    // 初始化结果
    *returnSize = 0;

    *returnColumnSizes = (int *) malloc(sizeof(int) * 1500);
    (*returnColumnSizes)[*returnSize] = 0;
    if (pRoot == NULL)
        return NULL;
    else {
        int** val = (int **) malloc(sizeof(int *) * 1500);
        TreeNode * move = pRoot;

        // 初始化队列
        Queue * queue = initQueue();
        // 将根节点入队并将其标记为一层的最后一个节点
        push(queue, move);
        setEndNode(queue);
        while (!isEmpty(queue)) {
            // 计算当前层的节点数
            int count = queue->endIndex - queue->head + 1;
            if (count == 0)
                break;
            // 初始化该层的结果指针
            val[*returnSize] = (int *) malloc(sizeof(int) * count);
            // 遍历该层的节点
            for (int i = 0; i < count; ++i) {
                move = pop(queue);
                val[*returnSize][(*returnColumnSizes)[*returnSize]] = move->val;
                if (move->left != NULL)
                    push(queue, move->left);
                if (move->right != NULL)
                    push(queue, move->right);
                (*returnColumnSizes)[*returnSize]++;
            }
            // 如果为偶数层就反转结果
            if (*returnSize % 2 != 0)
                reverse(val[*returnSize], count);
            
            // 行数加一，列数置零
            (*returnSize)++;
            (*returnColumnSizes)[*returnSize] = 0;
            // 设置尾节点为行尾节点
            setEndNode(queue);
        }

        freeQueue(queue);
        return val;
    }
}