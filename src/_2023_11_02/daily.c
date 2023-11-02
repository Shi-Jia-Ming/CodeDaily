#include "daily.h"
#include <stdio.h>
#include <string.h>

int countPoints_(const char * rings) {

    // 待返回的值
    int val = 0;

    // 创建数组用来存储杆上的环的数量
    char colors[10][100];
    int count[10] = {0};
    // 移动指针
    char * move;
    for (move = (char *)rings; *move != '\0'; ++move) {
        char color = *move;
        move++;
        int index = *move - '0';
        colors[index][count[index]] = color;
        count[index]++;
    }

    for (int i = 0; i < 10; ++i) {
        colors[i][count[i]] = '\0';
    }

    for (int i =0; i < 10; ++i) {
        if (strchr(colors[i], 'R') != NULL && strchr(colors[i], 'G') != NULL && strchr(colors[i], 'B') != NULL)
            val++;
    }

    return val;
}

// 官方思路
#define POLE_NUM 10
#define COLOR_NUM 3
enum Color {
    R = 0, G = 1, B = 2
};


int countPoints(const char * rings) {
    int colorState[POLE_NUM][COLOR_NUM] = {0};

    for (char * move = (char *)rings; *move != '\0'; ++move) {
        char color = *move;
        move++;
        int index = *move - '0';
        switch(color) {
            case 'R': {
                colorState[index][R] = 1;
                break;
            } case 'G': {
                colorState[index][G] = 1;
                break;
            } case 'B': {
                colorState[index][B] = 1;
                break;
            } default:;
        }
    }

    int count = 0;
    for (int i = 0; i < POLE_NUM; ++i) {
        if (colorState[i][R] && colorState[i][G] && colorState[i][B])
            count++;
    }

    return count;
}