#ifndef DAILY_H
#define DAILY_H

struct TreeNode {
    char val;
    struct TreeNode * left;
    struct TreeNode * right;
};

typedef struct TreeNode TreeNode;

TreeNode * buildTree(char * str);

char * Pre(TreeNode * root);

char * In(TreeNode * root);

char * Post(TreeNode * root);

void recursionFree(TreeNode * root);

#endif