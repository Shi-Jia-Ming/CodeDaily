#ifndef DAILY_H
#define DAILY_H

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

/**
 * 二叉树的先序遍历
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 * @param root TreeNode类
 * @return int* returnSize 返回数组的长度
 * @return int整型一维数组
 */
int* preorderTraversal(TreeNode* root, int* returnSize);

#endif