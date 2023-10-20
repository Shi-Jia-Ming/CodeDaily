#include <daily.h>
#include <stdlib.h>

/**
 * 定义栈数据结构
 */
// 定义栈节点
struct StackNode {
    TreeNode* node;
    struct StackNode* next;
};

typedef struct StackNode StackNode;

// 定义栈
struct Stack {
    StackNode* bottom;
    StackNode* top;
};

typedef struct Stack Stack;

int isEmpty(Stack* stack) {
    return stack->top == stack->bottom;
}

Stack* initStack() {
    Stack* stack = (Stack *)malloc(sizeof(Stack));
    stack->bottom = (StackNode *)(sizeof(StackNode));
//    stack->bottom->node = NULL;
//    stack->bottom->next = NULL;
    stack->top = stack->bottom;
    return stack;
}

void push(Stack* stack, TreeNode* node) {
    StackNode* newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->node = node;
    newNode->next = stack->top;
    stack->top = newNode;
}

TreeNode* pop(Stack* stack) {
    if (isEmpty(stack)) {
        return NULL;
    } else {
        TreeNode* val = stack->top->node;
        stack->top = stack->top->next;
        return val;
    }
}


// 树的先序遍历
int* preorderTraversal(TreeNode* root, int* returnSize) {
    int* val = (int *)malloc(sizeof(int) * 100);

    int count = 0;

    Stack* stack = initStack();
    TreeNode* move = root;

    while (1) {
        if (move == NULL && isEmpty(stack)) {
            *returnSize = count;
            return val;
        } else if (move != NULL) {
            val[count++] = move->val;
            push(stack, move);
            move = move->left;
        } else if (move == NULL) {
            move = pop(stack);
            TreeNode* temp = move;
            move = move->right;
            free(temp);
        }
    }
}