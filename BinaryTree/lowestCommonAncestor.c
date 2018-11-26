#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct ListNode ListNode;
typedef struct TreeNode TreeNode;

TreeNode *findCommon(TreeNode *node, TreeNode *p, TreeNode *q, int *flag) {
    if (node == NULL) {return NULL;}

    // int current_flag = *flag;
    int l_flag = 0;
    int r_flag = 0;
    int current_flag = 0;
    
    TreeNode *l_rt = findCommon(node->left, p, q, &l_flag);
    TreeNode *r_rt = findCommon(node->right, p, q, &r_flag);

    if (node == p || node == q) {current_flag = 1;}

    if (current_flag + l_flag + r_flag == 2) {
        *flag = 2;
        if (l_flag == 2) {
            return l_rt;
        }
        if (r_flag == 2) {
            return r_rt;
        }
        return node;
    }

    if (current_flag + l_flag + r_flag == 1) {
        *flag = 1;
    }
    return node;
}


struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    int flag = 0;
    return findCommon(root, p, q, &flag);
}


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

    /***********************/

    // Binary tree init
    struct TreeNode *tree;
    tree = (struct TreeNode *) malloc (sizeof(struct TreeNode));
    (*tree).val = 1;
    // left
    struct TreeNode *leftTree = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    (*leftTree).val = 2;
    (*leftTree).left = NULL;
    (*leftTree).right = NULL;

    (*tree).left = leftTree;
    (*tree).right = NULL;

    // left right
    struct TreeNode *tmpTree = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    (*tmpTree).val = 3;
    (*tmpTree).left = NULL;
    (*tmpTree).right = NULL;
    (*leftTree).right = tmpTree;

    TreeNode *ret  = lowestCommonAncestor(tree, leftTree, tmpTree);
    printf("ret %d\n", ret->val);

    return 0;
}
