## 二分查找

#### 描述

请实现无重复数字的升序数组的二分查找。

给定一个元素的升序的、无重复数组的整型数组`nums`和一个目标值`target`，写一个函数搜索`nums`中的`target`，如果目标值存在返回下标，否则返回-1。

数据范围：`0 <= len(nums) <= 2 * 10^(5)`，数组中任意值满足`|val| <= 10^(9)`。

时间复杂度`O(log n)`，空间复杂度`O(1)`。

#### 示例

```txt
输入：[-1, 0, 3, 4, 6, 10, 13, 14], 13
返回值：6
说明：13 出现在 nums 中并且下标为 6
```

---
#### 链接列表

- [README.md](../../README.md)
- [Source Code](./daily.c)