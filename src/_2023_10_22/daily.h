#ifndef DAILY_H
#define DAILY_H

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 * @param root TreeNode类 
 * @return int整型一维数组
 * @return int* returnSize 返回数组行数
 */
int* postorderTraversal(TreeNode* root, int* returnSize);

#endif
