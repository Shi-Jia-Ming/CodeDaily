#include "daily.h"
#include <string.h>
#include <stdlib.h>

/**
 * 栈数据结构
 */
struct Stack {
    TreeNode * data[100];
    int top;
};

typedef struct Stack Stack;

Stack * initStack() {
    Stack * stack = (Stack *) malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

void freeStack(Stack * stack) {
    free(stack);
}

int isEmpty(Stack * stack) {
    return stack->top == -1;
}

void push(Stack * stack, TreeNode * c) {
    stack->top++;
    stack->data[stack->top] = c;
}

TreeNode * pop(Stack * stack) {
    TreeNode * c = stack->data[stack->top];
    stack->top--;
    return c;
}

int isSign(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}

TreeNode * buildTree(char * str) {

    Stack * stack = initStack();
    // 字符串从右往左开始遍历
    int length = (int)strlen(str);
    for (int i = length - 1; i >= 0; --i) {
        TreeNode * nodeS = (TreeNode *) malloc(sizeof(TreeNode));
        nodeS->left = NULL;
        nodeS->right = NULL;
        nodeS->val = str[i];
        if (!isSign(str[i])) {
            push(stack, nodeS);
        } else {
            TreeNode * a = pop(stack);
            TreeNode * b = pop(stack);
            nodeS->left = a;
            nodeS->right = b;
            push(stack, nodeS);
        }
    }
    TreeNode * root = pop(stack);
    freeStack(stack);
    return root;
}


void recursionPre(TreeNode * root, char ** ans, int * index) {
    if (root == NULL) {
        return;
    } else {
        (*ans)[*index] = root->val;
        (*index)++;
        recursionPre(root->left, ans, index);
        recursionPre(root->right, ans, index);
    }
}

char * Pre(TreeNode * root) {
    char * ans  = (char *) malloc(sizeof(char) * 100);
    int index = 0;

    recursionPre(root, &ans, &index);
    return ans;
}

void recursionIn(TreeNode * root, char ** ans, int * index) {
    if (root == NULL) {
        return;
    } else {
        recursionIn(root->left, ans, index);
        (*ans)[*index] = root->val;
        (*index)++;
        recursionIn(root->right, ans, index);
    }
}

char * In(TreeNode * root) {
    char * ans = (char *) malloc(sizeof(char) * 100);
    int index = 0;

    recursionIn(root, &ans, &index);
    return ans;
}

void recursionPost(TreeNode * root, char ** ans, int * index) {
    if (root == NULL) {
        return;
    } else {
        recursionPost(root->left, ans, index);
        recursionPost(root->right, ans, index);
        (*ans)[*index] = root->val;
        (*index)++;
    }
}

char * Post(TreeNode * root) {
    char * ans = (char *) malloc(sizeof(char) * 100);
    int index = 0;

    recursionPost(root, &ans, &index);
    return ans;
}

void recursionFree(TreeNode * root) {
    if (root == NULL)
        return;

    recursionFree(root->left);
    recursionFree(root->right);
    free(root);
}