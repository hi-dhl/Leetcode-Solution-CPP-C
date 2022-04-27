//
// Created by DHL on 2022/4/27.
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
    ListNode *reverse(ListNode *head) {
        ListNode *pre = nullptr;
        while (head) {
            ListNode *next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *p1 = reverse(l1);
        ListNode *p2 = reverse(l2);
        int carry = 0;
        ListNode *head = nullptr;
        while ((p1 || p2)) {
            int a = p1 ? p1->val : 0;
            int b = p2 ? p2->val : 0;
            int sum = a + b + carry;
            carry = sum / 10;
            ListNode *node = new ListNode(sum % 10);
            node->next = head;
            head = node;
            p1 = p1 ? p1->next : nullptr;
            p2 = p2 ? p2->next : nullptr;
        }
        if (carry > 0) {
            ListNode *node = new ListNode(carry);
            node->next = head;
            head = node;
        }
        return head;
    }

};