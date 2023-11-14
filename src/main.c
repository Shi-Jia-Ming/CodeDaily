#include "daily.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char const *argv[]) {
    TreeNode * root = (TreeNode *) malloc(sizeof(TreeNode));
    createTree(root, "AB#C##D##");
    char * ans = Pre(root);
    printf("Pre  : %s\n", ans);
    free(ans);
    ans = In(root);
    printf("In   : %s\n", ans);
    free(ans);
    ans = Post(root);
    printf("Post : %s\n", ans);
    free(ans);
    ans = noRecursionIn(root);
    printf("In   : %s\n", ans);
    free(ans);
    printf("Leaf: %d\n", leaf(root));
    printf("Depth: %d\n", deep(root));
    recursionFree(root);
    return 0;
}
