#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "daily.h"

/**
 * 构造栈数据结构，用来进行树的遍历
 */
struct Stack {
    TreeNode * data[1000];
    int bottom;
  int top;
  };

typedef struct Stack Stack;

Stack * initStack() {
  Stack * stack = (Stack *) malloc(sizeof(Stack));
    stack->bottom = -1;
    stack->top = -1;
  return stack;
}

void freeStack(Stack * stack) {
    free(stack);
}

int isEmpty(Stack * stack) {
    return stack->bottom == stack->top;
  }

  void push(Stack * stack, TreeNode * node) {
    stack->top++;
    stack->data[stack->top] = node;
}

TreeNode * pop(Stack * stack) {
    if (isEmpty(stack))
        return NULL;
  stack->top--;
      return stack->data[stack->top + 1];
  }

  TreeNode * initTree() {
  TreeNode * head = (TreeNode *) malloc(sizeof(TreeNode));
    head->value = 0;
    head->super = NULL;
  head->left = NULL;
    head->right = NULL;
    return head;
  }

  TreeNode * addToTree(TreeNode * super, char value, int isLeft) {
    TreeNode * newNode = (TreeNode *) malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->super = super;
    if (isLeft)
        super->left = newNode;
    else
      super->right = newNode;

    return newNode;
}

int Depth(TreeNode * root) {
  int m, n;
    if (root == NULL)
        return 0;
  else {
  m = Depth(root->left);
    n = Depth(root->right);
    return m > n ? m + 1 : n + 1;
    }
}

void computeTree(TreeNode * root) {
    // 叶子节点个数
    int leafCount = 0;

  // 栈数据结构
  Stack * stack = initStack();

    TreeNode * move = root;
    while(1) {
    if (move == NULL && isEmpty(stack))
            break;
      else if (move == NULL) {
      TreeNode * parent = pop(stack);
    move = parent->right;
        } else if (move != NULL) {
      push(stack, move);
      if (move->left == NULL && move->right == NULL)
          leafCount++;
            move = move->left;
        }
        }

        printf("%d\n", Depth(root));
    printf("%d\n", leafCount);

    freeStack(stack);
        }

        void freeTree(TreeNode * head) {

    Stack * stack = initStack();
          if (head != NULL) {
    TreeNode  * move = head;
            //        push(stack, move);
    while(1) {
    if (move == NULL && isEmpty(stack))
      break;
      else if (move == NULL) {
    TreeNode * parent = pop(stack);
        move = parent->right;
    free(parent);
    } else if (move != NULL) {
      push(stack, move);
                move = move->left;
      }
      }
      }
    }

    void buildTree(TreeNode * head, Sequence * sequence) {
    // 如果左子树和右子树都为NULL，那么递归结束
      if (strlen(sequence->in) == 1)
      return;
      // 从中序遍历中找到该节点的左子树
    long long index = strchr(sequence->in, head->value) - sequence->in;

    // 左子树的中序遍历序列
      char * leftIn = (char *) malloc(sizeof(char) * 1000);
      int leftSize = (int)index;
    strncpy(leftIn, sequence->in, leftSize);
    leftIn[leftSize] = '\0';

    // 左子树的先序遍历
    char * leftPre = (char *) malloc(sizeof(char) * 1000);
      strncpy(leftPre, sequence->pre + 1, leftSize);
    leftPre[leftSize] = '\0';

    if (strcmp(leftPre, "") != 0) {
        // 从先序遍历中确定根节点
    char leftValue = leftPre[0];
    TreeNode * newLeftNode = addToTree(head, leftValue, 1);

        // 将先序和中序封装为结构体
      Sequence * leftSeq = (Sequence *) malloc(sizeof(Sequence));
        leftSeq->pre = leftPre;
        leftSeq->in = leftIn;

    buildTree(newLeftNode, leftSeq);
    }

    // 右子树的中序遍历序列
    char * rightIn = (char *) malloc(sizeof(char) * 1000);
      int rightSize = (int)strlen(sequence->in) - leftSize;
        strncpy(rightIn, sequence->in + index + 1, rightSize);

    // 右子树的先序遍历
    char * rightPre = (char *) malloc(sizeof(char) * 1000);
    strncpy(rightPre, sequence->pre + 1 + leftSize, rightSize);

      if (strcmp(rightPre, "") != 0) {
      // 从先序遍历中找到根节点
        char rightValue = rightPre[0];
        TreeNode * newRightNode = addToTree(head, rightValue, 0);

        // 将先序和中序封装为结构体
        Sequence * rightSeq = (Sequence *) malloc(sizeof(Sequence));
        rightSeq->pre = rightPre;
      rightSeq->in = rightIn;

      // 递归
        buildTree(newRightNode, rightSeq);
    }

    if (rightPre == NULL && leftPre == NULL)
        return;
}