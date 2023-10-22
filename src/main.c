#include <stdio.h>
#include <stdlib.h>

#include "daily.h"

int main(int argc, char const *argv[]) {
  // 输入字符串
    char * pre = (char *) malloc(sizeof(char) * 1000);
  char * in = (char *) malloc(sizeof(char) * 1000);
    scanf("%s", pre);
  scanf("%s", in);

    // 头节点，不存放值
  TreeNode * head = initTree();
    addToTree(head, pre[0], 1);

  Sequence * sequence = (Sequence *) malloc(sizeof(Sequence));
    sequence->pre = pre;
    sequence->in = in;

  buildTree(head->left, sequence);

    computeTree(head->left);

  freeTree(head);
  return 0;
}
