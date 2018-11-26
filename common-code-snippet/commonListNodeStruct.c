#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct ListNode ListNode;
typedef struct TreeNode TreeNode;

int main() {

    ListNode *node = (ListNode *) malloc(sizeof(ListNode));
    ListNode *node1 = (ListNode *) malloc(sizeof(ListNode));
    ListNode *node2 = (ListNode *) malloc(sizeof(ListNode));
    ListNode *node3 = (ListNode *) malloc(sizeof(ListNode));
    ListNode *node4 = (ListNode *) malloc(sizeof(ListNode));
    ListNode *node5 = (ListNode *) malloc(sizeof(ListNode));
    ListNode *node6 = (ListNode *) malloc(sizeof(ListNode));
    // node - 1 - 2
    node->val = 0;
    node->next = node1;
    node1->next = node2;
    node2->next = NULL;
    node1->val = 7;
    node2->val = 2;
    node3->val = 3;

    // another list
    // node3 - 4 - 5 - 6
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = NULL;
    node4->val = 4;
    node5->val = 5;
    node6->val = 6;

    // empty list
    ListNode *nodeEmpty = (ListNode *) malloc(sizeof(ListNode));
    nodeEmpty->val = 0;
    nodeEmpty->next = NULL;

    return 0;
}
