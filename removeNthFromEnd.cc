/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *        */

#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            std::vector<ListNode *> array;
            ListNode *cursor = head;
            while (cursor != NULL) {
                array.push_back(cursor);
                cursor = cursor->next;
            }
            
            int index = array.size() - n;
            if (index == 0) {
                if (array.size() == 1) {
                    return NULL;
                }

                return array.at(1);
            }

            ListNode *cursor_before = array.at(array.size() - n - 1);
            if (n == 1) {
                cursor = NULL;
            } else {
                cursor = array.at(array.size() - n + 1);
            }
            cursor_before->next = cursor;

            return array.at(0);
        }
};

int main() {
    ListNode n1{1};
    ListNode n2{2};
    n1.next = &n2;
    ListNode n3{3};
    n2.next = &n3;
    ListNode n4{4};
    n3.next = &n4;
    ListNode n5{5};
    n4.next = &n5;
   
    Solution so;
    ListNode *head = so.removeNthFromEnd(&n1, 1);

    while (head != NULL) {
        printf("val %d\n", head->val);
        head = head->next;
    }
    return 0;
}
