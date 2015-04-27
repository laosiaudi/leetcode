// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Remove_Linked_List_Elements.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-27 11:06:37
// MODIFIED: 2015-04-27 11:16:35
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
        ListNode* removeElements(ListNode* head, int val) {
            if (head == NULL)
                return head;

            ListNode* helper = new ListNode(0);
            helper->next = head;

            ListNode* walker = helper;
            while (walker->next != NULL) {
                if (walker->next->val == val) {
                    walker->next = walker->next->next;
                } else {
                    walker = walker->next;
                }
            }
            head = helper->next;
            delete helper;
            return head;
        }
};
