#include <stdio.h>
#include "daily.h"

int main(int argc, char const *argv[]) {
    int nums[5] = {1, 10, 3, 3, 3};
    int k = 3;
    printf("%ld", maxKelements(nums, 5, k));
    return 0;
}
