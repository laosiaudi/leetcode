// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Add_Two_Numbers.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-30 16:02:32
// MODIFIED: 2015-04-30 16:13:48
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
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        int length1 = 0;
        int length2 = 0;
        ListNode* tail1;
        ListNode* tail2;
        ListNode* temp = l1;
        while (temp != NULL) {
            length1 ++;
            if (temp->next == NULL)
                tail1 = temp;
            temp = temp->next;
        }

        temp = l2;
        while (temp != NULL) {
            length2 ++;
            if (temp->next == NULL)
                tail2 = temp;
            temp = temp->next;
        }
        if (length1 < length2) {
            int dis = length2 - length1;
            for (int i = 1;i <= dis; i ++) {
                ListNode* newSNode = new ListNode(0);
                tail1->next = newSNode;
                tail1 = newSNode;
            }
        } else {
            int dis = length1 - length2;
            for (int i = 1;i <= dis; i ++) {
                ListNode* newSNode = new ListNode(0);
                tail2->next = newSNode;
                tail2 = newSNode;
            }
        }

        ListNode* walker1 = l1;
        ListNode* walker2 = l2;
        int add = 0;
        ListNode* helper = new ListNode(-1);
        ListNode* pre = helper;
        while (walker1 != NULL && walker2 != NULL) {
            int newVal = walker1->val + walker2->val + add;
            if (newVal > 9) {
                newVal = newVal - 10;
                add = 1;
            } else {
                add = 0;
            }
            ListNode* newNode = new ListNode(newVal);
            pre->next = newNode;
            pre = newNode;
            walker1 = walker1->next;
            walker2 = walker2->next;
        }
        if (add == 1) {
            ListNode* newTNode = new ListNode(1);
            pre->next = newTNode;
        }
        ListNode* head = helper->next;
        delete helper;
        return head;
    }
};
