// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Reverse_Linked_List.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-16 14:29:35
// MODIFIED: 2015-05-16 14:50:21
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
        ListNode* reverseList(ListNode* head) {
            ListNode* pre = NULL;
            ListNode* walker = head;
            while (walker != NULL) {
                ListNode* temp = walker->next;
                walker->next = pre;
                pre = walker;
                walker = temp;
            }
            head = pre;
            return head;
    }
};

//Recursive Version
class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            if (head == NULL || head->next == NULL)
                return head;
            ListNode* temp = head->next;
            head->next = NULL;
            return recursiveReverse(head, temp);
        }

        ListNode* recursiveReverse(ListNode* pre, ListNode* cur) {
            if (cur->next == NULL) {
                cur->next = pre;
                return cur;
            }
            ListNode* temp = cur->next;
            cur->next = pre;
            return recursiveReverse(cur, temp);
        }
};
