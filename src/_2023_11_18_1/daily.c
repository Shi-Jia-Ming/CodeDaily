#include "daily.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *** scanData(int N) {
    char *** data = (char ***) malloc(sizeof(char **) * N);
    for (int i = 0; i < N; ++i) {
        data[i] = (char **) malloc(sizeof(char *) * 3);
        for (int j = 0; j < 3; ++j) {
            data[i][j] = (char *) malloc(sizeof(char) * 100);
            scanf("%s", data[i][j]);
        }
    }
    return data;
}

void freeData(char *** data, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            free(data[i][j]);
        }
        free(data[i]);
    }
    free(data);
}

void printData(char *** data, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%s ", data[i][j]);
        }
        printf("%c", '\n');
    }
}

// HITWHOJ 不支持 math.h 函数，并且 math.h 在 Linux 正常编译会出现问题，所以这里自定义函数
int power(int b) {
    int val = 1;
    for (int i = 0; i < b; ++i) {
        val *= 10;
    }
    return val;
}

// 字符串转换为整数
int strToInt(char * str) {
    int length = (int)strlen(str);
    int bit = 0;
    int val = 0;
    for (int i = length; i > -1; --i, ++bit) {
        val += str[i] * power(bit);
    }
    return val;
}

// 按字典顺序比较字符串
/*
 *  1: str1 > str2
 *  0: str1 = str2
 * -1: str1 < str2
 */
int isHeader(char * str1, char * str2) {
    int length1 = (int) strlen(str1);
    int length2 = (int) strlen(str2);

    int i;
    for (i = 0; i < length1 && i < length2; ++i) {
        if (str1[i] > str2[i])
            return 1;
        else if (str1[i] < str2[i])
            return -1;
        else continue;
    }
    if (i != length1 && i == length2)
        return 1;
    else if (i != length2 && i == length1)
        return -1;
    else return 0;
}

// 冒泡排序
char *** sort1(char *** head, int N) {
    for (int i = 0; i < N - 1; ++i) {
        int flag = 0;
        for (int j = 0; j < N - 1 - i; ++j) {
            if (strToInt(head[j][0]) > strToInt(head[j + 1][0])) {
                char ** temp = head[j];
                head[j] = head[j + 1];
                head[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
    return head;
}


// 冒泡排序
char *** sort2(char *** head, int N) {
    for (int i = 0; i < N - 1; ++i) {
        int flag = 0;
        for (int j = 0; j < N - 1 - i; ++j) {
            if (isHeader(head[j][1], head[j + 1][1]) == 1) {
                // str1 在后
                char ** temp = head[j];
                head[j] = head[j + 1];
                head[j + 1] = temp;
                flag = 1;
            } else if (isHeader(head[j][1], head[j + 1][1]) == 0) {
                // 重名
                if (strToInt(head[j][0]) > strToInt(head[j + 1][0])) {
                    char ** temp = head[j];
                    head[j] = head[j + 1];
                    head[j + 1] = temp;
                    flag = 1;
                }
            }
        }
        if (flag == 0) {
            break;
        }
    }
    return head;
}


char *** sort3(char *** head, int N) {
    for (int i = 0; i < N - 1; ++i) {
        int flag = 0;
        for (int j = 0; j < N - 1 - i; ++j) {
            if (strToInt(head[j][2]) > strToInt(head[j + 1][2])) {
                // str1 在后
                char ** temp = head[j];
                head[j] = head[j + 1];
                head[j + 1] = temp;
                flag = 1;
            } else if (strToInt(head[j][2]) == strToInt(head[j + 1][2])) {
                // 成绩相同
                if (strToInt(head[j][0]) > strToInt(head[j + 1][0])) {
                    char ** temp = head[j];
                    head[j] = head[j + 1];
                    head[j + 1] = temp;
                    flag = 1;
                }
            }
        }
        if (flag == 0) {
            break;
        }
    }
    return head;
}


char *** switchSort(char *** head, int N, int C) {
    switch (C) {
        case 1:
            return sort1(head, N);
        case 2:
            return sort2(head, N);
        case 3:
            return sort3(head, N);
        default:
            return NULL;
    }
}
