// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Insertion_Sort_List.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-30 11:11:23
// MODIFIED: 2015-04-30 12:02:56
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
        ListNode* insertionSortList(ListNode* head) {
            if (head == NULL || head->next == NULL)
                return head;

            ListNode* helper = new ListNode(0);
            helper->next = head;

            ListNode* pre = helper;
            ListNode* com = head;
            while (com != NULL) {
                ListNode* tempPre = helper;
                ListNode* walker = helper->next;
                bool ischange = false;
                while (walker != com) {
                    if (walker->val <= com->val) {
                        tempPre = tempPre->next;
                        walker = walker->next;
                    } else {
                        ListNode* nextNode = com->next;
                        pre->next = nextNode;
                        tempPre->next = com;
                        com->next = walker;
                        com = pre->next;
                        ischange = true;
                        break;
                    }
                }
                if (ischange == false) {
                    pre = pre->next;
                    com  = com->next;
                }
            }

            head = helper->next;
            delete helper;
            return head;
        }
};

//another simple solution
class Solution {
    public:
        ListNode* insertionSortList(ListNode* head) {
            if (head == NULL || head->next == NULL)
                return head;

            ListNode* helper = new ListNode(0);
            ListNode* com = head;
            while (com != NULL) {
                ListNode* tempPre = helper;
                ListNode* next = com->next;
                while (tempPre->next != NULL && tempPre->next->val <= com->val) {
                    tempPre = tempPre->next;
                }
                com->next = tempPre->next;
                tempPre->next = com;
                com = next;
            }

            head = helper->next;
            delete helper;
            return head;
        }
};
