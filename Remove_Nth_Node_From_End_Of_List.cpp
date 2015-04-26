// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Remove_Nth_Node_From_End_Of_List.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-27 00:57:04
// MODIFIED: 2015-04-27 01:18:47
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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            if (head == NULL)
                return head;
            ListNode* helper = new ListNode(0);
            helper->next = head;
            ListNode* walker = helper;
            while (1) {
                ListNode* temp = walker;
                for (int i = 1; i <= n + 1; i ++)
                    temp = temp->next;
                if (temp == NULL) {
                    ListNode* removeNode = walker->next;
                    walker->next = removeNode->next;
                    break;
                }
                walker = walker->next;
            }
            head = helper->next;
            delete helper;
            return head;
        }
};

