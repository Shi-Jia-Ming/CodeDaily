#include "daily.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// 查询链表中是否存在该字符串
ArrayNode * findStr(ArrayNode * root, const char * str) {
    ArrayNode * move = root;
    while (move != NULL && (move->val == NULL || strcmp(move->val, str) != 0))
        move = move->next;
    return move;
}

// 查询链表中是否存在两个整数
int findInt(FileNode * root, int idx1, int idx2) {
    FileNode * move = root;
    while (move != NULL && move->idx != idx1 && move->idx != idx2)
        move = move->next;
    if (move == NULL) {
        return 0;
    } else if (move->idx == idx1) {
        while (move != NULL && move->idx != idx2)
            move = move->next;
    } else {
        while (move != NULL && move->idx != idx1)
            move = move->next;
    }
    return move == NULL ? 1 : 2;
}

// 添加str和i的信息
void pushArray(ArrayNode * head, char * str, int i) {
    ArrayNode * target = findStr(head, str);
    // 文件节点
    FileNode * fileNode = (FileNode *) malloc(sizeof(FileNode));
    fileNode->idx = i + 1;
    fileNode->next = NULL;
    if (target == NULL) {
        // 链表中没有 str
        ArrayNode * node = (ArrayNode *) malloc(sizeof(ArrayNode));
        node->val = str;
        node->next = NULL;
        node->file = fileNode;

        // 添加节点
        ArrayNode * move;
        for (move = head; move->next != NULL; move = move->next);
        move->next = node;
    } else {
        // target->val = str
        FileNode * move;
        for (move = target->file; move->next != NULL; move = move->next);
        move->next = fileNode;
    }
}

// 大写变小写
void upperToLower(char * str) {
    for (char * move = str; *move != '\0'; ++move) {
        if (*move <= 'Z' && *move >= 'A') {
            *move += 'a' - 'A';
        }
    }
}

ArrayNode * getFile(int number) {
    ArrayNode * head = (ArrayNode *) malloc(sizeof(ArrayNode));
    head->val = NULL;
    head->next = NULL;
    head->file = NULL;

    char * tmp =  (char *) malloc(sizeof(char) * 50);

    for (int i = 0; i < number; ++i) {
        while (1) {
            scanf("%s", tmp);
            if (strcmp(tmp, "#") == 0) break;
            // 对字符串进行处理
            char * start = tmp, * move;
            int length = 0;
            for (move = tmp; *move != '\0' && length <= 10; ++move, ++length) {
                if (*move < 'A' || (*move > 'Z' && *move < 'a') || *move > 'z') {
                    // 非字母
                    if ((int)(move - start + 1) >= 3) {
                        char * str = (char *) malloc(sizeof(char) * 11);
                        strncpy(str, start, (int)(move - start));
                        str[(int)(move - start)] = '\0';
                        upperToLower(str);
                        pushArray(head, str, i);
                    }
                    start = move + 1;
                    length = 0;
                }
            }
            if ((int)(move - start) >= 3) {
                char * str = (char *) malloc(sizeof(char) * 11);
                if ((int)(move - start) > 10) {
                    strncpy(str, start, 10);
                    str[10] = '\0';
                } else {
                    strncpy(str, start, (int)(move - start) + 1);
                }
                upperToLower(str);
                pushArray(head, str, i);
            }
        }
    }
    return head;
}

// 输出重复率
double * getRate(ArrayNode * head, int num) {
    int file1, file2;
    double * res = (double *) malloc(sizeof(double));
    for (int i = 0; i < num; ++i) {
        scanf("%d %d", &file1, &file2);
        // 总词数和重复的词数
        int wholeNum = 0, equalNum = 0;
        for (ArrayNode * move = head; move != NULL; move = move->next) {
            int count = findInt(move->file, file1, file2);
            if (count == 1) {
                wholeNum++;
            } else if (count == 2) {
                wholeNum++;
                equalNum++;
            }
        }
        res[i] =  (equalNum / (double) wholeNum) * 100;
    }
    return res;
}

void freeAll(ArrayNode * head) {
    if (head == NULL) return ;
    // 获取 ArrayNode 链表的长度
    ArrayNode * move;
    int arrayLength = 0;
    for (move = head; move->next != NULL; move = move->next, ++arrayLength);
    for (int i = arrayLength - 1; i > 0; --i) {
        // 定位节点
        move = head;
        for (int j = i; j > 0; --j)
            move = move->next;
        free(move->val);
        int fileLength = 0;
        FileNode * fileMove;
        for (fileMove = move->file; fileMove->next != NULL; fileMove = fileMove->next, ++fileLength);
        for (int ii = fileLength - 1; ii > 0; --ii) {
            fileMove = move->file;
            for (int jj = ii; jj > 0; --jj)
                fileMove = fileMove->next;
            free(fileMove);
        }
        free(move->file);
        free(move);
    }
    free(head);
}