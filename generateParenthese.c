#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backtrack(char **ret, char *a, int *returnSize, int depth, int size, int left, int right);

void backtrack(char **ret, char *a, int *returnSize, int depth, int size, int left, int right) {
    if (*returnSize > 0) {
        printf("%c depth: %d.\n", ret[0][0], depth);
    }
    if (depth == size * 2 - 1) {
        // get a solution
        // printf("Get solution: ");
        // for (int i = 0; i < depth; ++i) {
        //     printf("%c", a[i]);
        // }
        int retSize = *returnSize;
        
        if (retSize == 0) {
            ret = (char **) malloc(sizeof(char *));
        } else {
            char **tmpRet = (char **) realloc(ret, sizeof(char *) * (retSize + 1));
            ret = tmpRet;
        }

        int charSize = size * 2 + 1;
        ret[retSize] = (char *) malloc(sizeof(char) * charSize);
        memcpy(ret[retSize], a, sizeof(char) * charSize);

        ++(*returnSize);
         printf("%d, %s.\n", retSize , ret[retSize]);
         return;
    } else {
        ++depth;

        if (left == 0 && right == 0) {
            printf("error \n");
            return;
        }

        if (left == 0) {
            a[depth] = ')';
            --right;
            backtrack(ret, a, returnSize, depth, size, left, right);
            return;
        }
        if (right == 0) {
            a[depth] = '(';
            --left;
            backtrack(ret, a, returnSize, depth, size, left, right);
            return;
        }

        if (left >= right) {
            // add a (
            a[depth] = '(';
            --left;
            backtrack(ret, a, returnSize, depth, size, left, right);
            return;
        } else {
            // try both
            a[depth] = '(';
            --left; 
            backtrack(ret, a, returnSize, depth, size, left, right);
            ++left;

            a[depth] = ')';
            --right;
            backtrack(ret, a, returnSize, depth, size, left, right);
            return;
        }
    }
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
    char **ret = NULL;
    int charSize = n * 2 + 1;
    char *a = (char *) malloc(sizeof(char) * charSize);
    backtrack(ret, a, returnSize, -1, n, n, n);
    printf(" %c.\n", ret[0][0]);
    for (int i = 0; i < *returnSize; ++i) {
        printf("%d: %s.\n", i, ret[i]);
    }
    return ret;
}

int main() {
    int n = 0;
    scanf("%d", &n);
    int returnSize = 0;
    char **ret = generateParenthesis(n, &returnSize);
    printf("start: %d.\n", returnSize);
    printf(" %c.\n", ret[0][0]);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d: %s.\n", i, ret[i]);
    }
    return 0;
}
