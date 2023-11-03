#ifndef DAILY_H
#define DAILY_H

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

typedef struct Node Node;

Node* connect(Node* root);

#endif // DAILY_H