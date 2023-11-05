#include "daily.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// KMP算法
int KMP(char * str, char * pat, int * idx) {
    // 影子状态
    int X = 0;
    // 状态的个数
    int Length = (int)strlen(pat) + 1;

    // 初始化动态规划数组
    int ** dp = (int **) malloc(sizeof(int *) * Length);
    for (int i = 0; i < Length; ++i) {
        dp[i] = (int *) malloc(sizeof(int) * 256);
        for (int j = 0; j < 256; ++j) {
            dp[i][j] = 0;
        }
    }

    // 设置动态规划数组
    for (int status = 0; status < Length; ++status) {
        // 回退到影子状态
        for (int c = 0; c < 256; ++c) {
            dp[status][c] = dp[X][c];
        }
        // 状态前进
        dp[status][pat[status]] = status + 1;
        // 更新影子状态
        X = dp[X][pat[status]];
    }

    // 开始匹配
    int status = 0;
    int maxStatus = 0;
    for (char * move = str; *move != '\0'; ++move) {
        status = dp[status][*move];
        if (status >= maxStatus) {
            maxStatus = status;
            *idx = (int)(move - str) - status + 2;
        }
    }
    return maxStatus;
}


// 获取匹配结果
void getResult() {
    // 基因库中的基因数
    int number;
    scanf("%d", &number);
    char ** genesRepo = (char **) malloc(sizeof(char *) * number);
    for (int i = 0; i < number; ++i) {
        genesRepo[i] = (char *) malloc(sizeof(char) * 100);
        scanf("%s", genesRepo[i]);
    }
    char * pat = (char *) malloc(sizeof(char) * 100);
    scanf("%s", pat);

    int * idx = (int *) malloc(sizeof(int));
    *idx = 0;
    int res = 0;
    int maxRes = 0;
    int num = 0;
    int * maxIdx = (int *) malloc(sizeof(int));
    for (int i = 0; i < number; ++i) {
        res = KMP(genesRepo[i], pat, idx);
        if (res > maxRes) {
            maxRes = res;
            num = i + 1;
            *maxIdx = *idx;
        }
    }
    printf("%d %d %.2lf%c", num, *maxIdx, (double)maxRes / (double) strlen(pat) * 100, '%');
}
