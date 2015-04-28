// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Remove_Duplicates_From_Sorted_List_II.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-28 11:50:11
// MODIFIED: 2015-04-28 13:08:19
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
            ListNode* pre = helper;
            bool isDuplicate = false;
            while (walker->next != NULL) {
                if (walker->next->val == walker->val) {
                    if (isDuplicate == false)
                        isDuplicate = true;
                    ListNode* deleteNode = walker->next;
                    walker->next = walker->next->next;
                } else {
                    if (isDuplicate) {
                        ListNode* deleteNode = walker;
                        pre->next = walker->next;
                        walker = walker->next;
                        isDuplicate = false;
                    } else {
                        if (walker != helper)
                            pre = pre->next;
                        walker = walker->next;
                    }
                }
            }
            if (isDuplicate) {
                pre->next = walker->next;
            }
            head = helper->next;
            delete helper;
            return head;
        }
};
