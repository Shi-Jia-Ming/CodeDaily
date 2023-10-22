#include <stdio.h>
#include <stdlib.h>

#include "daily.h"

int main(int argc, char const *argv[]) {
    TreeNode* root = (TreeNode *)malloc(sizeof(TreeNode));
    root->left = NULL;
    root->right = NULL;
    root->val = 1;
    TreeNode* node = (TreeNode *)malloc(sizeof(TreeNode));
    node->left = NULL;
    node->right = NULL;
    node->val = 2;
    root->left = node;
    TreeNode* node2 = (TreeNode *)malloc(sizeof(TreeNode));
    node2->left = NULL;
    node2->right = NULL;
    node2->val = 3;
    node->right = node2;

    int size = 0;

    int* val = postorderTraversal(root, &size);
    for (int i = 0; i < size; i++) {
        printf("%d ", val[i]);
    }
    printf("\n");
    return 0;
}
