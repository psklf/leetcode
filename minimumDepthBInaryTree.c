#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int minDepth(struct TreeNode* root);

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if (NULL == root) {
        return 0;
    }

    if (root->left == NULL) {
        if (root->right == NULL) {
            return 1;
        }
        return minDepth(root->right) + 1;
    } 
    if (root->right == NULL) {
        return minDepth(root->left) + 1;
    } 

    int left = minDepth(root->left) + 1;
    if (left == 1) {
        return minDepth(root->right);
    }

    int right = minDepth(root->right) + 1;
    // printf("val %d; left: %d, right: %d.\n", root->val, left, right);
    if (left == right) {
        return left;
    }

    if (right == 1) {
        return left;
    } else {
        return left > right ? right : left ;
    }

}


int main() {
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

    int depth = minDepth(tree);
    printf("depth %d.\n", depth);

    return 0;
}
