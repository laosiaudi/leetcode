// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Add_Two_Numbers.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-30 16:02:32
// MODIFIED: 2015-05-05 10:40:10
#include <iostream>
using namespace std;

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* helper = new ListNode(-1);

        ListNode* pre = helper;
        ListNode* walker1 = l1;
        ListNode* walker2 = l2;
        int carry = 0;
        while (walker1 != NULL || walker2 != NULL) {
            int va1 = walker1 == NULL ? 0 : walker1->val;
            int va2 = walker2 == NULL ? 0 : walker2->val;
            ListNode* newNode = new ListNode((va1 + va2 + carry) %10);
            carry = (va1 + va2 + carry)/10;
            pre->next = newNode;
            pre = newNode;
            walker1 = walker1 == NULL ? NULL : walker1->next;
            walker2 = walker2 == NULL ? NULL : walker2->next;
        }
        if (carry > 0)
            pre->next = new ListNode(1);
        ListNode* head = helper->next;
        delete helper;
        return head;
    }
};
