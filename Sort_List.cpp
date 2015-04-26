// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Sort_List.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-26 14:48:33
// MODIFIED: 2015-04-26 16:07:40
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
        ListNode* sortList(ListNode* head) {
            if (head == NULL || head->next == NULL)
                return head;
            
            ListNode* oneStep = head;
            ListNode* twoStep = head;
            while (twoStep->next != NULL &&  twoStep->next->next != NULL) {
                oneStep = oneStep->next;
                twoStep = twoStep->next->next;
            }
            
            ListNode* secondHead = oneStep->next;
            oneStep->next = NULL; //将前半段和后半段分开，便于后面合并
            ListNode* firstHead = sortList(head);
            secondHead = sortList(secondHead);
            head = merge(firstHead, secondHead);
            return head;
        }


        ListNode* merge(ListNode* node1, ListNode* node2) { //将后半段插入到前半段
            ListNode *helper = new ListNode(0);
            helper->next = node1;
            ListNode* temp = helper;
            while (node1 != NULL && node2 != NULL) {
                if (node1->val < node2->val)
                    node1 = node1->next;
                else {
                    ListNode* next = node2->next;
                    node2->next = temp->next;
                    temp->next = node2;
                    node2 = next;
                }
                temp = temp->next;
            }

            if (node2 != NULL)
                temp->next = node2;
            return helper->next;
        }

};

