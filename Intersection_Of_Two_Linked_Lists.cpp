// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Intersection_Of_Two_Linked_Lists.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-29 21:52:45
// MODIFIED: 2015-04-29 21:58:11
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
//将其中一个链表首尾链接，然后找环就行
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
            return NULL;

        ListNode* temp = headB;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = headB;
        ListNode* node = detectCycle(headA);
        temp->next = NULL;
        return node;
        
    }
    ListNode* detectCycle(ListNode *head) {
            if (head == NULL || head->next == NULL)
                return NULL;

            ListNode* walker = head;
            ListNode* runner = head;
            bool hasCycle = false;
            while (walker != NULL && runner != NULL && walker->next != NULL && runner->next != NULL) {
                walker = walker->next;
                runner = runner->next->next;
                if (walker ==  runner) {
                    hasCycle = true;
                    break;
                }
            }

            if (hasCycle == false)
                return NULL;
            else {
                runner = head;
                while (runner != walker) {
                    runner = runner->next;
                    walker = walker->next;
                }
                return runner;
            }
        }
};
