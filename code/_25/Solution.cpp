//
// Created by DHL on 2022/6/29.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *p = dummyHead;
        ListNode *q = dummyHead->next;
        int len = getListLength(head);
        int index = 0;
        while (q) {
            if (len - index < k) {
                return dummyHead->next;
            }
            index = index + k;
            int m = k;
            while ((--m) > 0) {
                ListNode *node = q->next;
                q->next = q->next->next;
                node->next = p->next;
                p->next = node;
            }
            p = q;
            q = q->next;
        }

        return dummyHead->next;
    }

    int getListLength(ListNode *head) {
        ListNode *cur = head;
        int len = 0;
        while (cur) {
            cur = cur->next;
            len++;
        }
        return len;
    }
};