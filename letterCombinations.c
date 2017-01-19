#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lnode {
    char *data;
    int length;
    struct Lnode *next;
} ListNode;

void insert(ListNode *preNode, ListNode *thisNode); 

void appendChar(char *chars, ListNode **head);

int *getLetter(char *digits, int *size);

void appendChar(char *chars, ListNode **head) {
    ListNode *nextNode;
    ListNode *preNode;
    ListNode *headNode = *head;
    if (headNode == NULL) {
        // first char
        headNode = (ListNode *) malloc(sizeof(ListNode));
        char *tmpData = (char *) malloc(sizeof(char) * 2);
        tmpData[0] = chars[0];
        tmpData[1] = '\0';
        headNode->data = tmpData;
        headNode->length = 2;
        preNode = headNode;

        // do with rest chars
        int i = 1;
        while (chars[i] != '\0') {
            char *tmpData = (char *) malloc(sizeof(char) * 2);
            tmpData[0] = chars[i];
            tmpData[1] = '\0';
            ListNode *thisNode;
            thisNode = (ListNode *) malloc(sizeof(ListNode));
            thisNode->data = tmpData;
            thisNode->length = 2;
            thisNode->next = NULL;

            preNode->next = thisNode;
            preNode = thisNode;
            ++i;
        }
        *head = headNode;
        return;
    } else {
        preNode = *head;
        while (1) {
            // insert value first then change the preNode 
            // save the next node first
            nextNode = preNode->next;
            ListNode *innerPreNode = preNode;

            int newLength = preNode->length + 1;

            int i = 1;
            while (chars[i] != '\0') {
                ListNode *thisNode = (ListNode *) malloc(sizeof(ListNode));
            
                // set new data
                char *oldCharData = (char *) malloc(sizeof(char) * newLength);
                memcpy(oldCharData, preNode->data, sizeof(char) * preNode->length);
                oldCharData[newLength - 2] = chars[i];
                oldCharData[newLength - 1] = '\0';
                thisNode->data = oldCharData;

                thisNode->length = newLength;
                thisNode->next = NULL;

                // printf("length: %d, data: %s.\n", thisNode->length, thisNode->data);

                innerPreNode->next = thisNode;
                innerPreNode = thisNode;
                ++i;
            }

            // first char
            char *tmpPtr1 = (char *) realloc(preNode->data, newLength * sizeof(char));
            tmpPtr1[newLength - 2] = chars[0];
            tmpPtr1[newLength - 1] = '\0';
            preNode->data = tmpPtr1;
            preNode->length = newLength;

            if (nextNode == NULL) {
                break;
            }

            innerPreNode->next = nextNode;
            preNode = nextNode;
        }
    }
}

int *getLetter(char *digits, int *size) {
    int i = 0;
    int *digitsIndex = NULL;
    if (digits == NULL) {
        return digitsIndex;
    }

    while (digits[i] != '\0') {
        if (digits[i] > '9' || digits[i] < '2') {
            return NULL;
        }
        if (i == 0) {
            digitsIndex = (int *) malloc(sizeof(int));
        } else {
            int *tmpPtr = (int *) realloc(digitsIndex, (i + 1) * sizeof(int));
            if (!tmpPtr) {
                printf("Error!\n");
                return digitsIndex;
            }
            digitsIndex = tmpPtr;
        }
        digitsIndex[i] = digits[i] - '0';
        ++i;
    }
    *size = i;
    return digitsIndex;
}
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    char **ret = NULL;

    char *digi2chars[10];
    digi2chars[2] = "abc";
    digi2chars[3] = "def";
    digi2chars[4] = "ghi";
    digi2chars[5] = "jkl";
    digi2chars[6] = "mno";
    digi2chars[7] = "pqrs";
    digi2chars[8] = "tuv";
    digi2chars[9] = "wxyz";

    int length = 0;
    int *digitsIndex = getLetter(digits, &length);
    if (digitsIndex == NULL) {
        return ret;
    }
    ListNode *head = NULL;

    for (int i = 0; i < length; ++i) {
        int thisNumber = digitsIndex[i];
        char *thisChars = digi2chars[thisNumber];
        appendChar(thisChars, &head);
    }
    free(digitsIndex);

    int size = 1;
    ret = (char **) malloc(sizeof(char *));

    ListNode *tmp = head;
    ret[0] = (char *)malloc(sizeof(char) * tmp->length);
    memcpy(ret[0], tmp->data, sizeof(char) * tmp->length);

    while (tmp->next != NULL) {
        tmp = tmp->next;
        char **tmpRet = (char **) realloc(ret, sizeof(char *) * (size + 1));
        int charSize = tmp->length + 1;
        tmpRet[size] = (char *) malloc(sizeof(char) * charSize);
        memcpy(tmpRet[size], tmp->data, sizeof(char) * charSize);
        ret = tmpRet;
        ++size;
    }

    ListNode *freeNode = head;
    ListNode *tmpNext = freeNode->next;
    free(freeNode->data);
    free(freeNode);
    while(tmpNext != NULL) {
        freeNode = tmpNext;
        tmpNext = freeNode->next;

    free(freeNode->data);
    free(freeNode);
    }

    *returnSize = size;
    return ret;
}

int main() {

    char digits[10];
    int returnSize = 0;
    scanf("%s", digits);

    char **charArray = letterCombinations(digits, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d: %s.\n", i, charArray[i]);
    }


    return 0;
}
