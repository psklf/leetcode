#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    ListNode *resultListNode = (ListNode *) malloc(sizeof(ListNode));
    ListNode *thisNode = resultListNode;

    ListNode *leftNext = NULL;
    ListNode *rightNext = NULL;
    int firstNum;

    // judge if null
    if (l1 == NULL) {
        if (l2 == NULL) {
            // both NULL
            return NULL;
        } else {
            rightNext = l2->next;
            firstNum = l2->val;
        }
    } else if (l2 == NULL) {
        // l2 == NULL and l1 != NULL
        leftNext = l1->next;
        firstNum = l1->val;
    } else {
        // both not NULL
        leftNext = l1->next;
        rightNext = l2->next;
        firstNum = l1->val + l2->val;
    }

    int flag = 0;
    if (firstNum < 10) {
        resultListNode->val = firstNum;
    } else {
        resultListNode->val = firstNum - 10;
        flag = 1;
    }

    while (leftNext != NULL || rightNext != NULL) {
        ListNode *tmpNode = (ListNode *) malloc(sizeof(ListNode));
        if (leftNext == NULL) {
            tmpNode->val = rightNext->val;
            rightNext = rightNext->next;
        } else if (rightNext == NULL) {
            tmpNode->val = leftNext->val;
            leftNext = leftNext->next;
        } else {
            tmpNode->val = leftNext->val + rightNext->val;
            rightNext = rightNext->next;
            leftNext = leftNext->next;
        }

        // deal with the flag
        if (flag) {
            ++tmpNode->val;
            --flag;
        }

        // judge if > 9
        if (tmpNode->val > 9) {
            tmpNode->val -= 10;
            ++flag;
        }

        // set the linked list
        resultListNode->next = tmpNode;
        resultListNode = resultListNode->next;
    }
    // if still has flag puls it
    if (flag) {
        ListNode *lastNode = (ListNode *) malloc(sizeof(ListNode));
        lastNode->val = 1;
        lastNode->next = NULL;
        resultListNode->next = lastNode;
    } else {
        resultListNode->next = NULL;
    }
    return thisNode;
}

int main() {

    ListNode *node = (ListNode *) malloc(sizeof(ListNode));
    ListNode *node1 = (ListNode *) malloc(sizeof(ListNode));
    ListNode *node2 = (ListNode *) malloc(sizeof(ListNode));
    ListNode *node3 = (ListNode *) malloc(sizeof(ListNode));
    ListNode *node4 = (ListNode *) malloc(sizeof(ListNode));
    ListNode *node5 = (ListNode *) malloc(sizeof(ListNode));
    ListNode *node6 = (ListNode *) malloc(sizeof(ListNode));
    node->val = 0;
    node->next = node1;
    node1->next = node2;
    node2->next = NULL;

    node1->val = 7;
    node2->val = 2;
    node3->val = 3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = NULL;
    node4->val = 4;
    node5->val = 5;
    node6->val = 6;

    ListNode *nodeEmpty = (ListNode *) malloc(sizeof(ListNode));
    nodeEmpty->val = 0;
    nodeEmpty->next = NULL;

    ListNode *ret = addTwoNumbers(nodeEmpty, node3);
    while (ret != NULL) {
        printf("result1: %d.\n", ret->val);
        ret = ret->next;
    }
    return 0;
}
