#ifndef DAILY_H
#define DAILY_H

struct TreeNode {
    char val;
    struct TreeNode * left;
    struct TreeNode * right;
};

typedef struct TreeNode TreeNode;

// 递归遍历
void recursionCreate(TreeNode * root, char ** str);

// 递归释放二叉树
void recursionFree(TreeNode * root);

// 根据字符串创建二叉树
void createTree(TreeNode * root, char * str);

// 先序遍历
char * Pre(TreeNode * root);

// 递归先序遍历
void recursionPre(TreeNode * root, char ** ans, int * index);

// 中序遍历
char * In(TreeNode * root);

// 递归中序遍历
void recursionIn(TreeNode * root, char ** ans, int * index);

//
char * Post(TreeNode * root);

// 递归后序遍历
void recursionPost(TreeNode * root, char ** ans, int * index);

// 叶子节点数量
int leaf(TreeNode * root);

// 二叉树深度
int deep(TreeNode * root);

// 非递归中序遍历
char * noRecursionIn(TreeNode * root);

#endif // DAILY_H