#include "daily.h"
#include <stdlib.h>
#include <string.h>

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

void push(Stack * stack, TreeNode * node) {
    stack->top++;
    stack->data[stack->top] = node;
}

TreeNode * pop(Stack * stack) {
    TreeNode * node = stack->data[stack->top];
    stack->top--;
    return node;
}

void recursionCreate(TreeNode * root, char ** str) {
    TreeNode * move = root;

    if (**str != '#') {
        move->left = (TreeNode *) malloc(sizeof(TreeNode));
        move = move->left;
        move->val = **str;
        (*str)++;
        recursionCreate(move, str);
        move = root;
    } else {
        move->left = NULL;
        (*str)++;
    }
    if (**str == '#') {
        move->right = NULL;
        (*str)++;
    } else {
        move->right = (TreeNode *) malloc(sizeof(TreeNode));
        move = move->right;
        move->val = **str;
        (*str)++;
        recursionCreate(move, str);
    }
}

void createTree(TreeNode * root, char * str) {
    if (strlen(str) == 0)
        return;
    else {
        root->val = *str;
        str++;

        recursionCreate(root, &str);
    }
}

void recursionFree(TreeNode * root) {
    if (root == NULL)
        return;

    recursionFree(root->left);
    recursionFree(root->right);
    free(root);
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

char * noRecursionIn(TreeNode * root) {
    char * ans = (char *) malloc(sizeof(char) * 100);
    int index = 0;
    if (root == NULL) {
        return ans;
    }
    Stack * stack = initStack();
    push(stack, root);
    TreeNode * move = root->left;
    while (!isEmpty(stack) || move != NULL) {
        if (move != NULL) {
            push(stack, move);
            move = move->left;
        }  else {
            TreeNode * treeNode = pop(stack);
            ans[index] = treeNode->val;
            index++;
            move = treeNode->right;
        }
    }
    freeStack(stack);
    return ans;
}

int leaf(TreeNode * root) {
    int ans = 0;
    if (root == NULL) {
        return ans;
    }
    Stack * stack = initStack();
    push(stack, root);
    TreeNode * move = root->left;
    while (!isEmpty(stack) || move != NULL) {
        if (move != NULL) {
            push(stack, move);
            move = move->left;
        }  else {
            TreeNode * treeNode = pop(stack);
            if (treeNode->left == NULL && treeNode->right == NULL) {
                ans++;
            }
            move = treeNode->right;
        }
    }
    freeStack(stack);
    return ans;
}

int deep(TreeNode * root) {
    int m, n;
    if (root == NULL)
        return 0;
    else {
        m = deep(root->left);
        n = deep(root->right);
        return m > n ? m + 1 : n + 1;
    }
}