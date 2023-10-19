#include <stdio.h>
#include "daily.h"
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    struct ListNode* head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode* node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode* node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode* node3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = node1;
    node1->val = 2;
    node1->next = node2;
    node2->val = 3;
    node2->next = node3;
    node3->val = 4;
    node3->next = NULL;
    struct ListNode* temp = head;
    // 输出链表
    for (int i = 0; i < 4; ++i) {
        printf("%d\n", temp->val);
        temp = temp->next;
    }
    head = ReverseList(head);
    // 输出链表
    for (int i = 0; i < 4; ++i) {
        printf("%d\n", head->val);
        head = head->next;
    }
    return 0;
}
