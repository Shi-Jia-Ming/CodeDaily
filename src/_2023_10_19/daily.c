#include "daily.h"
#include <stdio.h>

struct ListNode* ReverseList(struct ListNode* head) {
    if (head->next == NULL || head == NULL)
        return head;
    struct ListNode* p = head->next;
    if (p->next == NULL) {
        p->next = head;
        head->next = NULL;
        return p;
    } else {
        struct ListNode* t = head;
        struct ListNode* q = p->next;
        for (; q != NULL; t = p, p = q, q = q->next) {
            p->next = t;
        }
        p->next = t;
        head->next = NULL;
        return p;
    }
};