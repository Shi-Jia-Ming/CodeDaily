#include "daily.h"
#include <math.h>

/* 超出时间限制 
long long maxKelements(int* nums, int numsSize, int k) {
    // 初始分数
    long long score = 0;

    for (int i = 0; i < k; ++i) {
        // 记录 nums 中值最大的位置和最大值
        int index = 0, max = 0;
        for (int j = 0; j < numsSize; ++j) {
            if (nums[j] > max) {
                index = j;
                max = nums[j];
            }
        }

        score += max;
        nums[index] = ceil(max / 3.0);
    }
    return score;
}
*/

/* 交换 nums 中的索引为 i 和 j 的元素 */
void swap(int *nums, int i, int j) {
    int x = nums[i];
    nums[i] = nums[j];
    nums[j] = x;
}

/* 将父节点和比它大的子节点交换 */
void down(int *nums, int size, int i) {
    // nums[2 * i + 1] 是 nums[i] 节点的左子节点
    for (int k = 2 * i + 1; k < size; k = 2 * k + 1) {
        // 如果右子节点大于左子节点，就使用右子节点
        if (k + 1 < size && nums[k] < nums[k + 1]) 
            k++;
        // 如果子节点小于父节点，则直接退出循环
        if (nums[k] < nums[(k - 1) / 2])
            break;
        // 如果子节点大于父节点，则调用swap函数交换子节点和父节点的值
        swap(nums, k, (k - 1) / 2);
    }
}

/* 初始化堆 */
void Init(int *nums, int size) {
    // 从最后一个非叶子节点的索引开始遍历
    for (int i = size / 2 - 1; i >= 0; --i) {
        down(nums, size, i);
    }
}

void Push(int *nums, int size, int x) {
    nums[size] = x;
    // 如果子节点的值大于父节点的值，就交换这两个节点
    for (int i = size; i > 0 && nums[i] > nums[(i - 1) / 2]; i = (i - 1) / 2) {
        swap(nums, i, (i - 1) / 2);
    }
}

/* 交换第一个元素和最后一个元素之后，出队时获取数组最后的元素 */
int Pop(int *nums, int size) {
    swap(nums, 0, size - 1);
    down(nums, size - 1, 0);
    return nums[size - 1];
}

long long maxKelements(int *nums, int numsSize, int k) {
    Init(nums, numsSize);
    long long ans = 0;
    for (int i = 0; i < k; i++) {
        int x = Pop(nums, numsSize);
        ans += x;
        Push(nums, numsSize - 1, (x + 2) / 3);
    }
    return ans;
}
