//
// Created by DHL on 2022/4/29.
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
class Solution2 {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        stack<int> stack1, stack2;
        while (l1) {
            stack1.push(l1->val);
            l1 = l1->next;
        }

        while (l2) {
            stack2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode *head = nullptr;
        while (!stack1.empty() || !stack2.empty() || carry > 0) {
            int a = !stack1.empty() ? stack1.top() : 0;
            int b = !stack2.empty() ? stack2.top() : 0;
            int sum = a + b + carry;
            carry = sum / 10;
            ListNode *node = new ListNode(sum % 10);
            node->next = head;
            head = node;
            if (!stack1.empty()) stack1.pop();
            if (!stack2.empty()) stack2.pop();
        }
        return head;
    }

};