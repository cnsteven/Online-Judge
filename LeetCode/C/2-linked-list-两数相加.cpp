/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */
#include "main.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode head(-1);
        ListNode *p = &head, *t;
        int carry = 0;
        while (l1 && l2) {
            carry += l1->val + l2->val;
            t = new ListNode(carry % 10);
            carry /= 10;
            t->next = p->next;
            p->next = t;
            p = p->next;
            t = l1;
            l1 = l1->next;
            delete t;
            t = l2;
            l2 = l2->next;
            delete t;
        }
        p->next = l1 ? l1 : l2;
        t = p;
        p = p->next;
        while (p) {
            carry += p->val;
            p->val = carry % 10;
            carry /= 10;
            t = t->next;
            p = p->next;
        }
        if (carry != 0)
            t->next = new ListNode(carry);
        return head.next;
    }
};
// @lc code=end
