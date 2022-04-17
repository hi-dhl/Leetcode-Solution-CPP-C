//
// Created by DHL on 2022/4/17.
//

#include "../common/ListNode.h"

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummyHead = new ListNode(n, head);
        ListNode *p1 = dummyHead;
        ListNode *p2 = head;

        while (n-- != 0) {
            p2 = p2->next;
        }

        while (p2) {
            p1 = p1->next;
            p2 = p2->next;
        }

        ListNode *node = p1->next;
        p1->next = p1->next->next;
        delete (node);
        ListNode *nhead = dummyHead->next;
        delete (dummyHead);
        return nhead;
    }
};