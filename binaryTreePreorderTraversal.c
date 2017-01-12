#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode Ztree;

void add2array(int **array, int data, int *size);

void getVal(Ztree *tree, int **array_ptr, int *size);

void getVal(Ztree *tree, int **array_ptr, int *size) {
    add2array(array_ptr, tree->val, size);
    if (tree->left != NULL) {
        getVal(tree->left, array_ptr, size);
    }
    if (tree->right != NULL) {
        getVal(tree->right, array_ptr, size);
    }
}

void add2array(int **array_ptr, int data, int *size) {
    int *array = *array_ptr;
    if (*size == 0) {
        array[0] = data;
        (*size) = 1;
        return;
    }
    
    int length = *size;
    int *tmp = realloc(array, (length + 1 ) * sizeof(int));
    if (tmp != NULL) {
        tmp[length] = data;
        *array_ptr = tmp;
        *size = length + 1;
    }
}



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int *array = (int *) malloc(sizeof(int));
    *returnSize = 0;
    if (root == NULL) {
        return array;
    }
    getVal(root, &array, returnSize);
    return array;
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

    int size = 9;
    int *result = preorderTraversal(tree, &size);
    for (int i = 0; i < size; ++i) {
        printf("[%d]: %d.\n", i, result[i]);
    }
    return 0;
}
