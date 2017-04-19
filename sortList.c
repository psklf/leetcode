/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

ListNode *inner_sort(ListNode *head, int len);
ListNode *merge_list(ListNode *list1, int len1, ListNode *list2, int len2);

struct ListNode* sortList(struct ListNode* head) {
    // get length
    int list_length = 0;
    if (head == NULL) {
        return NULL;
    }
    ++list_length;
    ListNode* calcu_node = head;
    while (calcu_node->next != NULL) {
        list_length++;
        calcu_node = calcu_node->next;
    }

    return inner_sort(head, list_length);
}

ListNode *inner_sort(ListNode *head, int len) {
    if (len == 1) {
        return head;
    }

    if (len == 2) {
        if (head->val < head->next->val) {
            return head;
        } else {
            head->next->next = head;
            head = head->next;
            head->next->next = NULL;
            return head;
        }
    }
    ListNode *first;
    ListNode *second;
    first = head;
    second = first;
    int i = 0;
    for (i; i < len / 2 - 1; ++i) {
        second = second->next;
    }
    ListNode *tmp = second;
    second = second->next;
    tmp->next = NULL;
    ++i;
    return merge_list(inner_sort(first, i), i, inner_sort(second, len - i), len - i);
}

ListNode *merge_list(ListNode *list1, int len1, ListNode *list2, int len2) {
    int total_len = len1 + len2;
    ListNode *ret_head = NULL; 
    ListNode *this_node = ret_head;
    for (int i = 0; i < total_len; ++i) {
        if (list1 == NULL && list2 == NULL) {
            break;
        }
        if (list1 == NULL) {
            ListNode *tmp = list2;
            list2 = list2->next;
            tmp->next = NULL;
            if (this_node != NULL) {
                this_node->next = tmp;
                this_node = tmp;
            } else {
                this_node = tmp;
                ret_head = tmp;
            }
            // printf("this val : %d.\n", ret_array[i]);
            continue;
        }

        if (list2 == NULL) {
            ListNode *tmp = list1;
            list1 = list1->next;

            tmp->next = NULL;
            if (this_node != NULL) {
                this_node->next = tmp;
                this_node = tmp;
            } else {
                this_node = tmp;
                ret_head = tmp;
            }
            // printf("this val : %d.\n", ret_array[i]);
            continue;
        }

        if (list1->val < list2->val) {
            ListNode *tmp = list1;
            list1 = list1->next;

            tmp->next = NULL;
            if (this_node != NULL) {
                this_node->next = tmp;
                this_node = tmp;
            } else {
                this_node = tmp;
                ret_head = tmp;
            }
        } else {
            ListNode *tmp = list2;
            list2 = list2->next;

            tmp->next = NULL;
            if (this_node != NULL) {
                this_node->next = tmp;
                this_node = tmp;
            } else {
                this_node = tmp;
                ret_head = tmp;
            }
        }
    }  // end of loop

    return ret_head;
}

int main() {
    ListNode *node = (ListNode *) malloc(sizeof(ListNode));
    ListNode *node1 = (ListNode *) malloc(sizeof(ListNode));
    ListNode *node2 = (ListNode *) malloc(sizeof(ListNode));
    ListNode *node3 = (ListNode *) malloc(sizeof(ListNode));
    ListNode *node4 = (ListNode *) malloc(sizeof(ListNode));
    ListNode *node5 = (ListNode *) malloc(sizeof(ListNode));
    ListNode *node6 = (ListNode *) malloc(sizeof(ListNode));
    node->val = 1;
    node->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;
    node1->val = 13;
    node2->val = 24;
    node3->val = 5;
    node4->val = 15;
    node5->val = 4;

    ListNode *main_ret = sortList(node);
    while (main_ret != NULL) {
        printf("Val: %d.\n", main_ret->val);
        main_ret = main_ret->next;
    }
    return 1;
}
