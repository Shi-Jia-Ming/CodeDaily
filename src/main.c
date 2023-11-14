#include "daily.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char const *argv[]) {

    TreeNode * root = buildTree("-+ab/de");
    char * ans = Pre(root);
    printf("%s\n", ans);
    free(ans);
    ans = In(root);
    printf("%s\n", ans);
    free(ans);
    ans = Post(root);
    printf("%s\n", ans);
    free(ans);
    recursionFree(root);
    return 0;
}
