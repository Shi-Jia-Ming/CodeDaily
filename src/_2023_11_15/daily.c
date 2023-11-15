#include "daily.h"
#include <stdlib.h>
#include <string.h>

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

void push(Stack * stack, TreeNode * node) {
    stack->top++;
    stack->data[stack->top] = node;
}

TreeNode * pop(Stack * stack) {
    TreeNode * node = stack->data[stack->top];
    stack->top--;
    return node;
}


void curveBuild(TreeNode * node, char ** str) {
    if (**str != '#') {
        node->left = (TreeNode *) malloc(sizeof(TreeNode));
        node->left->isLChild = 1;
        node->left->isRChild = 1;
        node->left->val = **str;
        (*str)++;
        curveBuild(node->left, str);
    } else {
        node->left = NULL;
        (*str)++;
    }
    if (**str != '#') {
        node->right = (TreeNode *) malloc(sizeof(TreeNode));
        node->right->isRChild = 1;
        node->right->isLChild = 1;
        node->right->val = **str;
        (*str)++;
        curveBuild(node->right, str);

    } else {
        node->right = NULL;
        (*str)++;
    }
}

TreeNode * buildTree(char * str) {
    TreeNode * root = NULL;
    if (strlen(str) != 0) {
        root = (TreeNode *) malloc(sizeof(TreeNode));
        root->val = *str;
        root->isRChild = 1;
        root->isLChild = 1;
        str++;

        curveBuild(root, &str);
    }

    return root;
}

void freeTree(TreeNode * root) {
    if (root == NULL)
        return;
    if (root->isLChild) {
        freeTree(root->left);
    }
    if (root->isRChild) {
        freeTree(root->right);
    }
    free(root);
}

void curveThrt(TreeNode * node, TreeNode ** pre) {
    if (node == NULL) {
        return;
    } else {
        // 对当前节点的左子树线索化
        curveThrt(node->left, pre);
        // 处理当前节点的前驱关系
        if (node->left == NULL) {
            node->left = (*pre);
            node->isLChild = 0;
        }
        if (node->right == NULL) {
            node->isRChild = 0;
        }
        // 处理上一个节点的后继关系
        if ((*pre) != NULL && (*pre)->right == NULL) {
            (*pre)->right = node;
            (*pre)->isRChild = 0;
        }
        (*pre) = node;
        // 右子树线索化
        curveThrt(node->right, pre);
    }
}

TreeNode * buildThrt(TreeNode * root) {
    TreeNode ** pre = (TreeNode **) malloc(sizeof(TreeNode *));
    (*pre) = NULL;
    curveThrt(root, pre);
    return root;
}

char * getThrt(TreeNode * root) {
    char * ans = (char *) malloc(sizeof(char) * 100);
    int index = 0;
    TreeNode * move = root;
    while (move->left != NULL) {
        move = move->left;
    }
    while (move->right != NULL) {
        ans[index] = move->val;
        index++;
        // move->left == NULL 遍历初始节点
        if (!move->isRChild) {
            move = move->right;
        } else {
            move = move->right;
            while (move->isLChild) {
                move = move->left;
            }
        }
    }
    ans[index] = move->val;
    index++;
    return ans;
}


int getNode(TreeNode * root) {
    int index = 0;
    TreeNode * move = root;
    while (move->left != NULL) {
        move = move->left;
    }
    while (move->right != NULL) {
        if (move->isLChild + move->isRChild == 1)
            index++;
        // move->left == NULL 遍历初始节点
        if (!move->isRChild) {
            move = move->right;
        } else {
            move = move->right;
            while (move->isLChild) {
                move = move->left;
            }
        }
    }
    if (move->isLChild + move->isRChild == 1)
        index++;
    index++;
    return index;
}