// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Partition_List.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-28 13:46:41
// MODIFIED: 2015-04-28 14:12:51
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
        ListNode* partition(ListNode* head, int x) {
            if (head == NULL || head->next == NULL)
                return head;

            ListNode* small = new ListNode(0);
            ListNode* big = new ListNode(0);

            ListNode* walker = head;
            ListNode* smallWalker = small;
            ListNode* bigWalker = big;

            while (walker != NULL) {
                if (walker->val < x) {
                    ListNode* temp = walker->next;
                    smallWalker->next = walker;
                    smallWalker = smallWalker->next;
                    walker = temp;
                } else {
                    ListNode* temp = walker->next;
                    bigWalker->next = walker;
                    bigWalker = bigWalker->next;
                    walker = temp;
                }
            }
            bigWalker->next = NULL;
            smallWalker->next = big->next;
            head = small->next;
            delete small;
            delete big;
            return head;

        }
};

//也可以找到第一个不小于x的节点，然后往它的左边一直插入小于x的节点
