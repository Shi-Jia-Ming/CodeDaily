#include "daily.h"
#include <stdio.h>
#include <stdlib.h>

TreeNode * buildNode(char val) {
    TreeNode * node = (TreeNode *) malloc(sizeof(TreeNode));
    node->val = val;
    node->child = NULL;
    node->brother = NULL;
    return node;
}

struct Queue {
    TreeNode * data[1000];
    int head;
    int rear;
};

typedef struct Queue Queue;

struct Stack {
    TreeNode * data[1000];
    int top;
};

typedef struct Stack Stack;

Queue * initQueue() {
    Queue * queue = (Queue *) malloc(sizeof(Queue));
    queue->head = -1;
    queue->rear = 0;
    return queue;
}

Stack * initStack() {
    Stack * stack = (Stack *) malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

void freeQueue(Queue * queue) {
    free(queue);
}

void freeStack(Stack * stack) {
    free(stack);
}

int isEmptyQueue(Queue * queue) {
    return queue->rear - queue->head == 1;
}

int isEmptyStack(Stack * stack) {
    return stack->top == -1;
}

void pushQueue(Queue * queue, TreeNode * node) {
    queue->head++;
    queue->data[queue->head] = node;
}

void pushStack(Stack * stack, TreeNode * node) {
    stack->top++;
    stack->data[stack->top] = node;
}

TreeNode * popQueue(Queue * queue) {
    TreeNode * node = queue->data[queue->rear];
    queue->rear++;
    return node;
}

TreeNode * popStack(Stack * stack) {
    TreeNode * node = stack->data[stack->top];
    stack->top--;
    return node;
}

int getStackLength(Stack * stack) {
    return stack->top + 1;
}

// 输出栈中元素
void printStack(Stack * stack) {
    for (int i = 0; i <= stack->top; ++i) {
        printf("%c", stack->data[i]->val);
    }
    printf("\n");
}

TreeNode * buildTree() {
    // 初始化队列数据结构
    Queue * queue = initQueue();
    char a = ' ', b, temp;
    scanf("%c,%c", &a, &b);
    // 消除 scanf 留下的回车
    scanf("%c", &temp);
    while (a != '#') {
        printf("Wrong scanning!");
        scanf("%c,%c", &a, &b);
        scanf("%c", &temp);
    }
    TreeNode * root = buildNode(b);
    pushQueue(queue, root);

    // 记录当前的节点
    a = ' '; b = ' ';
    TreeNode * parentNode = popQueue(queue);
    while (a != '#' && b != '#') {
        scanf("%c,%c", &a, &b);
        scanf("%c", &temp);

        if (a == '#' && b == '#') {
            break;
        }
        while (a != parentNode->val) {
            parentNode = popQueue(queue);
        }
        // 根据 b 建节点
        TreeNode * node = buildNode(b);
        pushQueue(queue, node);
        // 如果当前节点没有孩子，将该节点录入为孩子，否则为兄弟节点
        if (parentNode->child == NULL) {
            parentNode->child = node;
        } else {
            TreeNode * move = parentNode->child;
            while (move->brother != NULL) {
                move = move->brother;
            }
            move->brother = node;
        }
    }
    freeQueue(queue);
    return root;
}

void curveSearchPre(TreeNode * root, char ** str, int * index) {
    if (root == NULL)
        return;
    (*str)[*index] = root->val;
    (*index)++;
    curveSearchPre(root->child, str, index);
    curveSearchPre(root->brother, str, index);
}

char * preSearch(TreeNode * root) {
    char * str = (char *) malloc(sizeof(char) * 1000);
    int index = 0;
    curveSearchPre(root, &str, &index);
    return str;
}

char * postSearch(TreeNode * root) {
    char * str = (char *) malloc(sizeof(char) * 1000);
    int index = 0;
    if (root == NULL)
        return str;
    Stack * stack = initStack();
    TreeNode * move = root;
    pushStack(stack, move);
    while (!isEmptyStack(stack)) {
        while (move->child != NULL) {
            move = move->child;
            pushStack(stack, move);
        }
        // move->child 为 NULL，到达分支的最下面
        while (move->brother == NULL && move != root) {
            move = popStack(stack);
            str[index] = move->val;
            index++;
        }
        if (move != root) {
            move = move->brother;
            pushStack(stack, move);
        }
    }
    freeStack(stack);
    return str;
}

void curveFree(TreeNode * root) {
    if (root == NULL)
        return;
    curveFree(root->child);
    curveFree(root->brother);
    free(root);
}

char * floorSearch(TreeNode * root) {
    char * str = (char *) malloc(sizeof(char) * 1000);
    int index = 0;
    Queue * queue = initQueue();
    pushQueue(queue, root);
    while (!isEmptyQueue(queue)) {
        TreeNode * move = popQueue(queue);
        str[index] = move->val;
        index++;

        if (move->child != NULL) {
            move = move->child;
            pushQueue(queue, move);
            while (move->brother != NULL) {
                pushQueue(queue, move->brother);
                move = move->brother;
            }
        }
    }
    freeQueue(queue);
    return str;
}

int leaf(TreeNode * root) {
    int num = 0;
    Queue * queue = initQueue();

    pushQueue(queue, root);
    TreeNode * node;
    while (!isEmptyQueue(queue)) {
        node = popQueue(queue);
        if (node->child != NULL) {
            pushQueue(queue, node->child);
        } else {
            num++;
        }
        if (node->brother != NULL) {
            pushQueue(queue, node->brother);
        }
    }
    freeQueue(queue);
    return num;
}

void printBranch(TreeNode * root) {
    if (root == NULL)
        return;
    Stack * stack = initStack();
    TreeNode * move = root;
    pushStack(stack, move);
    while (!isEmptyStack(stack)) {
        while (move->child != NULL) {
            move = move->child;
            pushStack(stack, move);
        }
        // move->child 为 NULL，到达分支的最下面
        printStack(stack);
        while (move->brother == NULL && move != root) {
            move = popStack(stack);
        }
        if (move != root) {
            move = move->brother;
            pushStack(stack, move);
        }
    }
    freeStack(stack);
}

int depth(TreeNode * root) {
    int maxDepth = 0;
    if (root == NULL)
        return 0;
    Stack * stack = initStack();
    TreeNode * move = root;
    pushStack(stack, move);
    while (!isEmptyStack(stack)) {
        while (move->child != NULL) {
            move = move->child;
            pushStack(stack, move);
        }
        // move->child 为 NULL，到达分支的最下面
        int length = getStackLength(stack);
        if (length > maxDepth) {
            maxDepth = length;
        }
        while (move->brother == NULL && move != root) {
            move = popStack(stack);
        }
        if (move != root) {
            move = move->brother;
            pushStack(stack, move);
        }
    }
    freeStack(stack);
    return maxDepth;
}