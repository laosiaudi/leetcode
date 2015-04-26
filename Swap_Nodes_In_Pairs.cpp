// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Swap_Nodes_In_Pairs.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-26 14:13:26
// MODIFIED: 2015-04-26 14:45:45
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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* second = head->next;
        ListNode* temp = second->next;
        second->next = head;
        head->next = temp;
        head = second;
        ListNode* first;
        second = head->next;
        ListNode* start;
        start = head->next;
        while (start->next != NULL) {
           first = start->next;
           if (first == NULL || first->next == NULL)
               break;
           second = first->next;
           temp = second->next;
           first->next = temp;
           second->next = first;
           start->next = second;
           if (start->next == NULL)
               break;
           start = start->next->next;
        }
        return head;
    }
};

//recursive
class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            if (head == NULL || head->next == NULL)
                return head;
            ListNode* nextPair = head->next->next;
            ListNode* newHead = head->next;
            head->next->next = head;
            head->next = swapPairs(nextPair);
            head = newHead;
            return head;
        }
};
