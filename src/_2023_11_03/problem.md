## 填充每个节点的下一个右侧节点指针

#### 描述

给定二叉树：
```c
struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};
```

填充它的每个`next`指针指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将`next`指针设置为`NULL`。

初始状态下，所有`next`指针都被设置为`NULL`。

#### 示例

![Alt text](./assets/117_sample.png)

```txt
输入：root = [1, 2, 3, 4, 5, #, 7]
输出：[1, #, 2, 3, #, 4, 5, 7, #]
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。序列化输出按层序遍历顺序（由 next 指针连接），'#' 表示每层的末尾。
```

---
#### 链接列表

- [README.md](../../README.md)
- [Source Code](./daily.c)