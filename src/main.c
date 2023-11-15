#include "daily.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char const *argv[]) {

    TreeNode * root = buildTree("ab#cd####");

    root = buildThrt(root);

    char * ans = getThrt(root);
    printf("%s\n", ans);
    free(ans);
    printf("%d", getNode(root));
    freeTree(root);

    return 0;
}
