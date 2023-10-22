#include <stdlib.h>
#include "daily.h"

void getTree(TreeNode * node, int * size, int * value) {
    if (node == NULL) return;
    if (node->right == NULL && node->left == NULL) {
        value[(*size)++] = node->val;
        return;
    } else if (node->right == NULL) {
        getTree(node->left, size, value);
        value[(*size)++] = node->val;
        return;
    } else if (node->left == NULL) {
        getTree(node->right, size, value);
        value[(*size)++] = node->val;
        return;
    } else {
        getTree(node->left, size, value);
        getTree(node->right, size, value);
        value[(*size)++] = node->val;
        return;
    }
}


int* postorderTraversal(TreeNode* root, int* returnSize) {
    int* value = (int *) malloc(sizeof(int) * 100);
    getTree(root, returnSize, value);
    return value;
}