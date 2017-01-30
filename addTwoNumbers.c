#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lnode {
    int *val;
    struct Lnode *next;
} ListNode;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    ListNode* resultListNode = (ListNode *) malloc(sizeof(ListNode));
    resultListNode->val = l1.val + l2.val;
}

int main() {

    return 0;
}
