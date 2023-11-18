#include "daily.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char const *argv[]) {

    TreeNode * root = buildTree();

    char * str = preSearch(root);
    printf("%s\n", str);
    free(str);
    str = postSearch(root);
    printf("%s\n", str);
    free(str);
    str = floorSearch(root);
    printf("%s\n", str);
    free(str);
    printf("%d\n%d\n", depth(root), leaf(root));

    printBranch(root);

    curveFree(root);
    return 0;
}
