#ifndef DAILY_H
#define DAILY_H

struct TreeNode {
    char val;
    struct TreeNode * child;
    struct TreeNode * brother;
};

typedef struct TreeNode TreeNode;

TreeNode * buildTree();

// 先序遍历结果
char * preSearch(TreeNode * root);

// 后序遍历结果
char * postSearch(TreeNode * root);

// 层序遍历结果
char * floorSearch(TreeNode * root);

void curveFree(TreeNode * root);

int depth(TreeNode * root);

int leaf(TreeNode * root);

void printBranch(TreeNode * root);

#endif // DAILY_H