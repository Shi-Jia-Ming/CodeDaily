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

    int * size =(int *) malloc(sizeof(int) * 1000);
    int * columnSize[1500];
    // 数组内指针的初始化
    for (int i = 0; i < 1500; ++i) {
        columnSize[i] = (int *) malloc(sizeof(int));
    }

    int** val = levelOrder(root, size, columnSize);
    for (int i = 0; i < *size; ++i) {
        for (int j = 0; j < (*columnSize)[i]; ++j) {
            printf("%d\n", val[i][j]);
        }
    }
    printf("\n");
    return 0;
}
