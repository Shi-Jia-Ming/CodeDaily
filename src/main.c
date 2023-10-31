#include "daily.h"
#include <stdio.h>


int main(int argc, char const *argv[]) {

    int nums[8] = {-1, 0, 3, 4, 6, 10, 13, 14};
    printf("%d", search(nums, 8, 2));
    return 0;
}
