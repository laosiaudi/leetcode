// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Remove_Duplicates_From_Sorted_List.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-27 12:45:01
// MODIFIED: 2015-04-28 13:09:13
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
        ListNode* deleteDuplicates(ListNode* head) {
            if (head == NULL)
                return head;

            ListNode* helper = new ListNode(-9999);
            helper->next = head;

            ListNode* walker = helper;
            while (walker->next != NULL) {
                if (walker->next->val == walker->val) {
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
