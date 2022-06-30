//
// Created by DHL on 2022/6/30.
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
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        int m = left;
        ListNode *p = dummyNode;
        while (--m != 0) {
            p = p->next;
        }

        ListNode *q = p->next;
        int k = right - left;
        while (k-- != 0) {
            ListNode *node = q->next;
            q->next = q->next->next;
            node->next = p->next;
            p->next = node;
        }
        return dummyNode->next;
    }
};