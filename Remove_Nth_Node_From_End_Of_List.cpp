// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Remove_Nth_Node_From_End_Of_List.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-27 00:57:04
// MODIFIED: 2015-04-27 01:33:51
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

//一个指针先走n步，然后一起走，当第一个指针到达终点，第二个指针指向的节点就是要删除的节点
class BetterSolution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            if (head == NULL)
                return head;
            ListNode* pre = head;
            ListNode* walker = head;

            int step = 0;
            while (step < n &&  pre != NULL) {
                pre = pre->next;
                step ++;
            }

            while (step == n && pre == NULL) {
                head = head->next;
                return head;
            }

            while (pre->next != NULL) {
                walker = walker->next;
                pre = pre->next;
            }

            walker->next = walker->next->next;
            return head;
        }
};


