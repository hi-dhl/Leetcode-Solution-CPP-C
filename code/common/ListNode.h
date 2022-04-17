//
// Created by denghuilong on 2022/4/17.
//

#ifndef LEETCODE_SOLUTION_C_C___LISTNODE_H
#define LEETCODE_SOLUTION_C_C___LISTNODE_H

#endif //LEETCODE_SOLUTION_C_C___LISTNODE_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
