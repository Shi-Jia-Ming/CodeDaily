#include "daily.h"
#include <stdlib.h>

/** 
 * 有内存泄露的问题，对二重指针的运用还不太熟悉
struct Queue {
    TreeNode * data[150];
    int head;
    int tail;
    int end;
};

typedef struct Queue Queue;

Queue * initQueue() {
    Queue * queue = (Queue *) malloc(sizeof(Queue));
    queue->head = -1;
    queue->tail = -1;
    queue->end = 0;
    return queue;
}

int isEmpty(Queue * queue) {
    return queue->head == queue->tail;
}


// 判断队列头部的节点是否为树的一层的最后一个节点
int isEndNode(Queue * queue) {
    return queue->head + 1 == queue->end;
}

void freeQueue(Queue * queue) {
    free(queue);
}

void push(Queue * queue, TreeNode * node, int isEnd) {
    queue->data[(queue->tail)++] = node;
    // 标记一层的尾节点
    if (isEnd)
        queue->end = queue->tail;
}

TreeNode * pop(Queue * queue) {
    if (isEmpty(queue))
        return NULL;
    return queue->data[queue->head++];
}


int** levelOrder(TreeNode* root, int* returnSize, int** returnColumnsSizes) {
    *returnSize = 0;
    *returnColumnsSizes[*returnSize] = 0;
    int** value = (int **) malloc(sizeof(int *) * 1500);
    value[*returnSize] = (int *) malloc(sizeof(int) * 1500);

    TreeNode * move = root;
    Queue * queue = initQueue();

    push(queue, move, 1);

    while (!isEmpty(queue)) {
        int isEnd = isEndNode(queue);
        move = pop(queue);

        if (move != NULL) {
            value[*returnSize][*returnColumnsSizes[*returnSize]] = move->val;
            (*returnColumnsSizes[*returnSize])++;
            // move是一层的尾节点
            if (isEnd) {
                (*returnSize)++;
                (*returnColumnsSizes[*returnSize]) = 0;
                value[*returnSize] = (int *) malloc(sizeof(int) * 1500);
            }
            push(queue, move->left, isEnd && move->right == NULL);
            push(queue, move->right, isEnd && move->right != NULL);
        }
    }
    freeQueue(queue);

    return value;
}*/

/** 
 * 官方答案
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;   //特殊情况，空树
    if (root == NULL)
        return NULL;
    struct TreeNode* queue[100001];  //新建队列
    int** res = (int**)malloc(sizeof(int*) * 100001);  //为res分配内存，res实际上是一个数组，数组内存的内容是指向int型数组的地址，即构成一个二维数组
    *returnColumnSizes = (int*)malloc(sizeof(int) * 100001);  //为存储数组列数的数组分配空间，即存入每层多少个元素

    int head = 0, rear = 0;  //设队列的头尾指针
    queue[rear] = root;   //根结点入队，尾指针后移一位
    rear++;

    while (head != rear) {    //队列非空时
        int preRear = rear;  //记录当前层的尾结点
        int k = 0;           //当前层的结点数量
        res[*returnSize] = (int*)malloc(sizeof(int) * (preRear - head)); //为二维数组res的第*returnSize行分配空间
        while (head < preRear) {  //遍历当前层结点
            struct TreeNode* p = queue[head];   //队头元素出队
            res[*returnSize][k++] = p->val; //更新返回数组中的值
            if (p->left != NULL)   //将当前出队元素的左孩子结点入队
                queue[rear++] = p->left;
            if (p->right != NULL)  //将当前出队元素的右孩子结点入队
                queue[rear++] = p->right;
            head++;  //队头指针后移一位
        }
        (*returnColumnSizes)[*returnSize] = k;  //更新返回数组本层结点个数
        (*returnSize)++;  //指针指向下一层返回数组
    }

    return res;
}