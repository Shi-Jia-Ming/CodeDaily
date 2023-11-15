#ifndef DAILY_H
#define DAILY_H

// 二叉树数据结构
struct TreeNode {
    char val;
    int isLChild;
    struct TreeNode * left;
    int isRChild;
    struct TreeNode * right;
};

typedef struct TreeNode TreeNode;

TreeNode * buildTree(char * str);

void freeTree(TreeNode * root);

TreeNode * buildThrt(TreeNode * root);

char * getThrt(TreeNode * root);

int getNode(TreeNode * root);

#endif // DAILY_H