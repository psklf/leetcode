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
ListNode *merge2(ListNode *list1, ListNode *list2);

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
    if (head->next == NULL) {
        return head;
    }

    if (head->next->next == NULL) {
        if (head->val < head->next->val) {
            return head;
        } else {
            head->next->next = head;
            head = head->next;
            head->next->next = NULL;
            return head;
        }
    }

    // split list

    ListNode *first;
    ListNode *second;
    first = head;
    second = head;

    while (1) {
        first = first->next;
        second = second->next->next;
        if (second->next == NULL || second->next->next == NULL) {
            break;
        }
    }
    ListNode *mid = first->next;
    first->next = NULL;
    // printf("%d %d\n", head->val, mid->val);
        // return merge_list(inner_sort(first, i), i, inner_sort(second, len - i), len - i);
    return merge2(inner_sort(head, 0),  inner_sort(mid, 0));
}


ListNode *merge2(ListNode *list1, ListNode *list2) {
    ListNode *ret_head = (ListNode *)malloc(sizeof(ListNode));
    ListNode *this_node = ret_head;
    // return list2;

    while (1) {
        if (list1 == NULL) {
            this_node->next = list2;
            return ret_head->next;
        }
        if (list2 == NULL) {
            this_node->next = list1;
            return ret_head->next;
        }
        if (list1->val > list2->val) {
            this_node->next = list2;
            list2 = list2->next;

        } else {

            this_node->next = list1;
            list1 = list1->next;
        }
        this_node = this_node->next;
    }
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

    ListNode *head = (ListNode *) malloc(sizeof(ListNode));
    ListNode *head1 = (ListNode *) malloc(sizeof(ListNode));
    head->val = 10;
    head->next = head1;

    head1->val = 20;
    head1->next = NULL;

    ListNode *main_ret = sortList(node);
    // ListNode *main_ret = merge2(node, head);
    while (main_ret != NULL) {
        printf("Val: %d.\n", main_ret->val);
        main_ret = main_ret->next;
    }
    return 1;
}
