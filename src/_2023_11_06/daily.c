#include "daily.h"
#include <string.h>
#include <stdlib.h>
//
//// 为数组的 length 排序
//void sortLength(char ** words, int wordsSize) {
//    for (int i = 0; i < wordsSize; ++i) {
//        for (int j = i + 1; j < wordsSize; ++j) {
//            if (strlen(words[i]) < strlen(words[j])) {
//                char * temp = words[i];
//                words[i] = words[j];
//                words[j] = temp;
//            }
//        }
//    }
//}
//
//// 比较两个字符串中是否有相同的字符
//int hasSameChar(const char * str1, const char * str2) {
//    for (char * move1 = (char *)str1; *move1 != '\0'; ++move1) {
//        for (char * move2 = (char *)str2; *move2 != '\0'; ++move2) {
//            // 有相同字符
//            if (*move1 == *move2)
//                return 1;
//        }
//    }
//    return 0;
//}
//
//
//// 计算length * length
//int calcRes(char ** words, int wordsSize) {
//    int maxRes = 0;
//    int head = 0, rear = 0;
//    for (head; head < wordsSize; ++head) {
//        for (rear = head + 1; rear < wordsSize; ++rear) {
//            if (!hasSameChar(words[head], words[rear]))
//                if ((int)(strlen(words[head]) * strlen(words[rear])) > maxRes)
//                    maxRes = (int)(strlen(words[head]) * strlen(words[rear]));
//        }
//    }
//    return maxRes;
//}
//
//int maxProduct(char ** words, int wordsSize) {
//    sortLength(words, wordsSize);
//    return calcRes(words, wordsSize);
//}

#define MAX_S(a, b) ((a) > (b) ? (a) : (b))

// 用来存字符串信息
typedef struct NODE {
    int val; // bit 位标识，出现的字符置1
    int len; // 用来存字符串的长度，用于计算
}NODE_S;

NODE_S *g_Buf = NULL;

// 利用右移和| 运算符存储字符串中出现的字符
void SetBit(char ** words, int wordsSize)
{
    for (int i = 0; i < wordsSize; i++) {
        g_Buf[i].len = (int)strlen(words[i]);
        for (int j = 0; j < g_Buf[i].len; j++) {
            // 利用二进制中 1 的位置来标记存在对应的字母
            g_Buf[i].val |= (1 << (words[i][j] - 'a'));
        }
        // printf("%X\n", g_Buf[i].val);
    }
}

int maxProduct(char ** words, int wordsSize){
    g_Buf = (NODE_S*)malloc(sizeof(NODE_S) * wordsSize);
    memset(g_Buf, 0, sizeof(NODE_S) * wordsSize);
    int maxSum = 0;
    SetBit(words, wordsSize);
    for (int i = 0; i < wordsSize - 1; i++) {
        for (int j = i + 1; j < wordsSize; j++) {
            // 如果两个字符串存在相同的字符，则 & 运算后，其值不为 0
            int temp = g_Buf[i].val & g_Buf[j].val;
            if (temp == 0) {
                int val = g_Buf[i].len * g_Buf[j].len;
                maxSum = MAX_S(maxSum, val);
            }
        }
    }
    free(g_Buf);
    return maxSum;
}
