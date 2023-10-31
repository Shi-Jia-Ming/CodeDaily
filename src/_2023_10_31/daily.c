#include "daily.h"
#include <math.h>


int search(const int* nums, int numsLen, int target) {
    // 数组为空
    if (numsLen == 0)
        return -1;
    // 指向第一个元素
    int former = 0;
    // 指向最后一个元素
    int later = numsLen - 1;
    int medium = ceil((former + later) / 2.0);

    while (former != medium && later != medium) {
        if (target < nums[medium]) {
            later = medium;
            medium = floor((former + later) / 2.0);
        }
        else if (target > nums[medium]) {
            former = medium;
            medium = ceil((former + later) / 2.0);
        }
        else if (target == nums[medium]) {
            return medium;
        }
    }

    if (target == nums[former])
        return former;
    else if (target == nums[later])
        return later;
    else
        return -1;
}
