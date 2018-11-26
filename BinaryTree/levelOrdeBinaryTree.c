#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int calculateDepth(struct TreeNode *tree);

int getVal(struct TreeNode *tree, int level, int **result, int **columnSizes); 

int calculateDepth(struct TreeNode *tree) {
    if (tree == NULL) {
        // Attention if root tree is NULL, depth = 0
        return -1;
    }
    int left = 0;
    int right = 0;

    if ((*tree).left != NULL) {
        left = calculateDepth((*tree).left) + 1;
    }
    if ((*tree).right != NULL) {
        right = calculateDepth((*tree).right) + 1;
    }
    return left < right ? right : left;
}

int getVal(struct TreeNode *tree, int level, int **result, int **columnSizes) {
    if (tree == NULL) {
        return -1;
    }

    int *columns = *columnSizes;

    if (level == 0) {
        result[0] = (int *)malloc(sizeof(int));
        result[0][0] = (*tree).val;
        columns[0] = 1;

        getVal((*tree).left, level + 1, result, columnSizes);
        getVal((*tree).right, level + 1, result, columnSizes);
        return 0;
    }
    
    ++columns[level];
    int length = columns[level];
//    printf("++columns[level];%d\n", length);
    // save value to result
    if (result[level] == NULL || 1 == length) {
        // first of the array
//        printf("Init array.\n");
        result[level] = (int *) malloc(sizeof(int));
        result[level][0] = (*tree).val;
    } else {
        // expand the array
//        printf("Expand array.Length: %d.\n", length);
        int *tmpArray = realloc(result[level], length * sizeof(int));
        if (tmpArray != NULL) {
            tmpArray[length - 1] = (*tree).val;
        }
        result[level] = tmpArray;
    }

    getVal((*tree).left, level + 1, result, columnSizes);
    getVal((*tree).right, level + 1, result, columnSizes);
    return 0;
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int **result = NULL;
    int depth = calculateDepth(root) + 1;
    result = (int**) malloc(sizeof(int *) * depth);
    *columnSizes = (int *) malloc(sizeof(int) * depth);
    memset(*columnSizes, 0, depth * sizeof(int));
    
    *returnSize = depth;
    struct TreeNode *tmpTree = root;
    // start 
    getVal(root, 0, result, columnSizes); 
//    for (int i =0; i< depth; ++i) {
//        printf("after get value: columnSizes: %d.return Size:%d.\n",
//                (*columnSizes)[i], (*returnSize));
//    }
    return result;
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

    int **columnSize = (int **) malloc(sizeof(int *));
    int *returnSize = (int *) malloc(sizeof(int));

    int **result = levelOrder(tree, columnSize, returnSize);
    printf("result:\n");
    // printf("return size %d; columnSize 0 \n", (*returnSize));
    // printf("column%d!\n", (*columnSize)[0]);

    for (int i = 0; i < (*returnSize); ++i) {
        for (int j = 0; j < (*columnSize)[i]; ++j) {
            printf("result %d %d :%d.\n", i, j, result[i][j]);
        }
    }
    return 0;
}
