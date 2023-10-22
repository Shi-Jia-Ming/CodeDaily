#ifndef DAILY_H
#define DAILY_H

// 将两个遍历结果封装为结构体
struct Sequence {
    // 先序遍历
    char* pre;
  // 中序遍历
  char* in;
};

typedef struct Sequence Sequence;

    // 树节点结构体
struct TreeNode {
    struct TreeNode * super;
struct TreeNode * left;
    struct TreeNode * right;
  char value;
    };

    typedef struct TreeNode TreeNode;

    /**
* 初始化树的数据结构
 * @return 返回树的头节点(不存储数据)
 */
TreeNode * initTree();

/**
 * 释放树
 * @param head 树的头节点
 */
void freeTree(TreeNode * head);

/**
    * 为树添加新的接节点
    * @param super 待添加节点的父节点，用来定位要添加的位置
 * @param value 待添加的节点的值
 * @param isLeft 是否为左子节点
 * @return 新添加的节点
 */
TreeNode * addToTree(TreeNode * super, char value, int isLeft);

/**
 * 计算树的深度和叶子节点的数量
 * @param head 树的头节点
 */
void computeTree(TreeNode * head);

/**
 * 根据根节点和对应的遍历结果构建树
 * @param sequence 包含该根节点的遍历结果
 */
void buildTree(TreeNode * head, Sequence * sequence);

#endif // DAILY_H
