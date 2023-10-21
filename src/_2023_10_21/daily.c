#include "daily.h"
#include <stdlib.h>

/**
 * 初始化栈结构
 */
// 树的节点最多1000个，所以初始化数组栈为1000
struct Stack {
    TreeNode * data[1000];
    int bottom;
    int top;
};

typedef struct Stack Stack;

int isEmpty(Stack * stack) {
    return stack->bottom == stack->top;
}

Stack * initStack() {
    Stack * stack = (Stack *)malloc(sizeof(Stack));
    stack->bottom = -1;
    stack->top = stack->bottom;
    return stack;
}

void push(Stack * stack, TreeNode * node) {
    stack->top++;
    stack->data[stack->top] = node;
}

TreeNode * pop(Stack * stack) {
    if (isEmpty(stack))
        return NULL;
    TreeNode * node = stack->data[stack->top--];
    return node;
}

int* inorderTraversal(TreeNode* root, int* returnSize) {
    int* val = malloc(sizeof(int) * 1000);
    *returnSize = 0;

    Stack * stack = initStack();
    while (1) {
        if (root == NULL && isEmpty(stack))
            return val;
        else if (root != NULL) {
            push(stack, root);
            root = root->left;
        } else if (root == NULL) {
            TreeNode * node = pop(stack);
            val[(*returnSize)++] = node->val;
            root = node->right;
            free(node);
        }
    }
        
}