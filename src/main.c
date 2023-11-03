#include "daily.h"
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char const *argv[]) {


    Node * root = (Node *) malloc(sizeof(Node));
    root->val = 0;
    Node * node1 = (Node *) malloc(sizeof(Node));
    node1->val = 1;
    Node * node2 = (Node *) malloc(sizeof(Node));
    node2->val = 2;

    root->left = node1;
    root->right = NULL;
    node1->right = node2;
    node1->left = NULL;
    node2->right = NULL;
    node2->left = NULL;

    root->next = NULL;
    node1->next = NULL;
    node2->next = NULL;

    root = connect(root);

    free(root);
    free(node1);
    free(node2);
}
