#ifndef DAILY_H
#define DAILY_H

// C语言中没有 bool 类型
enum bool {
    false,
    true
};

typedef enum bool bool;

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 
 * @param s string字符串 
 * @return bool布尔型
 */
bool isValid(const char* s);

#endif // DAILY_H