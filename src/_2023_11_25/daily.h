#ifndef DAILY_H
#define DAILY_H

struct FileNode {
    int idx;
    struct FileNode * next;
};

struct ArrayNode {
    char * val;
    struct FileNode * file;
    struct ArrayNode * next;
};

typedef struct ArrayNode ArrayNode;
typedef struct FileNode FileNode;


ArrayNode * getFile(int number);

void freeAll(ArrayNode * head);

double * getRate(ArrayNode * head, int num);

#endif // DAILY_H